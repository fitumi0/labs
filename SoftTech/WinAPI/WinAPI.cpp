#pragma warning(disable : 4996)

#ifndef UNICODE
#define UNICODE
#endif

#define ID_firstB 1
#define ID_secondB 2
#define ID_Calculate 3
#define ID_Calculate2 4
#define ID_INFO 5
#define ID_PlusPoint 6
#define ID_CHILDLinePoints  7
#define ID_CHILDInCircle  8
#define ID_PRINT_DATA 9
#define ID_LOCK 10

#include <windows.h>
#include <tchar.h>
#include <iostream>
#include <format>
#include <stack>
#include <string>
#include <cwctype>
#include "WinAPI.h"


LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK FirstSubWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK SecSubWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

HWND hwnd, LinePoints, InCircle,EnterX1, EnterY1, 
EnterX2, EnterY2, EnterXn, EnterYn, R, RPointX, 
RPointY, INFO, Calculate1, Calculate2, PlusPoint, 
XYLabelN, PointList, LockLine;


const int buf_size = 256;
float x, y, Rad;
float x_1, x_2, y_1, y_2;
wchar_t TBuffer[buf_size];
std::string values = "";
std::string static_cache = "";
std::string answer = "";



LPCTSTR CLASS_NAME = TEXT("Window Class");
LPCTSTR CLASS_NAME1 = TEXT("Window1 Class");
LPCTSTR CLASS_NAME2 = TEXT("Window2 Class");

void ValueError(int ErrorCode) {
    switch (ErrorCode) {
    case 1: 
        MessageBox(hwnd, L"Error in point coordinates", L"Error", 0);
        break;
    case 2:
        MessageBox(hwnd, L"Error in line coordinates", L"Error", 0);

    }
    clear_buff(TBuffer);
}


void CreateMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow) {

    WNDCLASSEX wc;
    ZeroMemory(&wc, sizeof(WNDCLASSEX));
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;

    if (!RegisterClassEx(&wc)) {
        MessageBox(NULL, L"Window Registration Failed!", L"Error!", MB_ICONEXCLAMATION | MB_OK);
        return;
    }


    hwnd = CreateWindow(
        CLASS_NAME,                     
        L"3 Lab WinAPI",               
        WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX,            

        CW_USEDEFAULT,
        CW_USEDEFAULT,
        500,
        165,

        NULL,          
        NULL,       
        hInstance,  
        NULL        
    );

    HWND Button1 = CreateWindowW(
        L"Button",
        L"Количество точек на прямой в плоскости",
        WS_VISIBLE | WS_CHILD,
        80,    // X POS
        40,    // Y POS
        320,    // WIDTH
        26,    // HEIGHT
        hwnd,
        (HMENU)ID_firstB,
        NULL,
        NULL
    );

    HWND Button2 = CreateWindowW(
        L"Button",
        L"Количество точек попадающих в окружность",
        WS_VISIBLE | WS_CHILD,
        80,    // X POS
        70,    // Y POS
        320,    // WIDTH
        26,    // HEIGHT
        hwnd,
        (HMENU)ID_secondB,
        NULL,
        NULL
    );

    HWND Label1 = CreateWindowW(
        L"STATIC",
        L"Functions:",
        WS_VISIBLE | WS_CHILD,
        200,    // X POS
        20,    // Y POS
        70,    // WIDTH
        26,    // HEIGHT
        hwnd,
        NULL,
        NULL,
        NULL
    );
    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);
}

void CreateFirstChild(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow) {
    WNDCLASSEX wc;
    ZeroMemory(&wc, sizeof(WNDCLASSEX));
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.lpfnWndProc = FirstSubWindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME1;

    if (!RegisterClassEx(&wc)) {
        MessageBox(NULL, L"FirstChild Registration Failed!", L"Error!", MB_ICONEXCLAMATION | MB_OK);
        return;
    }

    LinePoints = CreateWindowEx(
        1,
        CLASS_NAME1,                     
        L"3 Lab WinAPI",               
        WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX,            

        CW_USEDEFAULT,
        CW_USEDEFAULT,
        500,
        285,

        hwnd,
        NULL,
        hInstance,
        NULL
    );

    HWND XYLabel1 = CreateWindowW(
        L"STATIC",
        L"Point 1 (INT) (X1;Y1)",
        WS_VISIBLE | WS_CHILD,
        20,    // X POS
        20,    // Y POS
        170,    // WIDTH
        20,    // HEIGHT
        LinePoints,
        NULL,
        NULL,
        NULL
    );

    HWND XYLabel2 = CreateWindowW(
        L"STATIC",
        L"Point 2 (INT) (X2;Y2)",
        WS_VISIBLE | WS_CHILD,
        20,    // X POS
        50,    // Y POS
        170,    // WIDTH
        20,    // HEIGHT
        LinePoints,
        NULL,
        NULL,
        NULL
    );

    EnterX1 = CreateWindowW(
        L"EDIT",
        L"",
        WS_VISIBLE | WS_CHILD | WS_BORDER,
        195,    // X POS
        20,    // Y POS
        30,    // WIDTH
        20,    // HEIGHT
        LinePoints,
        NULL,
        NULL,
        NULL
    );

    EnterY1 = CreateWindowW(
        L"EDIT",
        L"",
        WS_VISIBLE | WS_CHILD | WS_BORDER,
        230,    // X POS
        20,    // Y POS
        30,    // WIDTH
        20,    // HEIGHT
        LinePoints,
        NULL,
        NULL,
        NULL
    );

    EnterX2 = CreateWindowW(
        L"EDIT",
        L"",
        WS_VISIBLE | WS_CHILD | WS_BORDER,
        195,    // X POS
        50,    // Y POS
        30,    // WIDTH
        20,    // HEIGHT
        LinePoints,
        NULL,
        NULL,
        NULL
    );

    EnterY2 = CreateWindowW(
        L"EDIT",
        L"",
        WS_VISIBLE | WS_CHILD | WS_BORDER,
        230,    // X POS
        50,    // Y POS
        30,    // WIDTH
        20,    // HEIGHT
        LinePoints,
        NULL,
        NULL,
        NULL
    );

     LockLine = CreateWindowW(
        L"Button",
        L"Lock",
        WS_VISIBLE | WS_CHILD,
        280,    // X POS
        50,    // Y POS
        50,    // WIDTH
        20,    // HEIGHT
        LinePoints,
        (HMENU)ID_LOCK,
        NULL,
        NULL
    );

    Calculate1 = CreateWindowW(
        L"Button",
        L"=",
        WS_VISIBLE | WS_CHILD | WS_DISABLED,
        440,    // X POS
        80,     // Y POS
        20,     // WIDTH
        20,     // HEIGHT
        LinePoints,
        (HMENU)ID_Calculate,
        NULL,
        NULL
    );

    XYLabelN = CreateWindowW(
        L"STATIC",
        L"N Point (Xn;Yn):",
        WS_VISIBLE | WS_CHILD,
        20,    // X POS
        80,    // Y POS
        170,    // WIDTH
        20,    // HEIGHT
        LinePoints,
        NULL,
        NULL,
        NULL
    );

    EnterXn = CreateWindowW(
        L"EDIT",
        L"1",
        WS_VISIBLE | WS_CHILD | WS_BORDER | WS_DISABLED,
        195,    // X POS
        80,    // Y POS
        30,    // WIDTH
        20,    // HEIGHT
        LinePoints,
        NULL,
        NULL,
        NULL
    );

    EnterYn = CreateWindowW(
        L"EDIT",
        L"2",
        WS_VISIBLE | WS_CHILD | WS_BORDER | WS_DISABLED,
        230,    // X POS
        80,    // Y POS
        30,    // WIDTH
        20,    // HEIGHT
        LinePoints,
        NULL,
        NULL,
        NULL
    );

    PlusPoint = CreateWindowW(
        L"Button",
        L"+",
        WS_VISIBLE | WS_CHILD | WS_DISABLED,
        280,    // X POS
        80,     // Y POS
        20,     // WIDTH
        20,     // HEIGHT
        LinePoints,
        (HMENU)ID_PlusPoint,
        NULL,
        NULL
    );

    PointList = CreateWindowW(
        L"EDIT",
        L"",
        WS_VISIBLE | WS_CHILD | WS_VSCROLL |
        ES_MULTILINE | ES_AUTOVSCROLL | WM_CTLCOLORSTATIC,
        20,    // X POS
        80,    // Y POS
        170,    // WIDTH
        120,    // HEIGHT
        LinePoints,
        (HMENU)ID_PRINT_DATA,
        NULL,
        NULL
    );
}

void CreateSecChild(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow) {
    WNDCLASSEX wc;
    ZeroMemory(&wc, sizeof(WNDCLASSEX));
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.lpfnWndProc = SecSubWindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME2;

    if (!RegisterClassEx(&wc)) {
        
        MessageBox(NULL, L"SecChild Registration Failed!", L"Error!", MB_ICONEXCLAMATION | MB_OK);
        return;
    }

    InCircle = CreateWindowEx(
        1,
        CLASS_NAME2,                     
        L"In[Out]side",                
        WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX,            

        CW_USEDEFAULT,
        CW_USEDEFAULT,
        235,
        165,

        hwnd,
        NULL,
        hInstance,
        NULL
    );

    HWND RLabel = CreateWindowW(
        L"STATIC",
        L"R: ",
        WS_VISIBLE | WS_CHILD,
        20,    // X POS
        20,    // Y POS
        20,    // WIDTH
        20,    // HEIGHT
        InCircle,
        NULL,
        NULL,
        NULL
    );

    R = CreateWindowW(
        L"EDIT",
        L"",
        WS_VISIBLE | WS_CHILD | WS_BORDER,
        55,    // X POS
        20,    // Y POS
        30,    // WIDTH
        20,    // HEIGHT
        InCircle,
        NULL,
        NULL,
        NULL
    );

    HWND RPointLabel = CreateWindowW(
        L"STATIC",
        L"Point (INT) (X; Y): ",
        WS_VISIBLE | WS_CHILD,
        20,    // X POS
        50,    // Y POS
        130,    // WIDTH
        20,    // HEIGHT
        InCircle,
        NULL,
        NULL,
        NULL
    );

    RPointX = CreateWindowW(
        L"EDIT",
        L"",
        WS_VISIBLE | WS_CHILD | WS_BORDER,
        135,    // X POS
        50,    // Y POS
        30,    // WIDTH
        20,    // HEIGHT
        InCircle,
        NULL,
        NULL,
        NULL
    );

    RPointY = CreateWindowW(
        L"EDIT",
        L"",
        WS_VISIBLE | WS_CHILD | WS_BORDER,
        170,    // X POS
        50,    // Y POS
        30,    // WIDTH
        20,    // HEIGHT
        InCircle,
        NULL,
        NULL,
        NULL
    );

    Calculate2 = CreateWindowW(
        L"Button",
        L"=",
        WS_VISIBLE | WS_CHILD,
        20,    // X POS
        80,     // Y POS
        60,     // WIDTH
        20,     // HEIGHT
        InCircle,
        (HMENU)ID_Calculate2,
        NULL,
        NULL
    );

    INFO = CreateWindowW(
        L"Button",
        L"INFO",
        WS_VISIBLE | WS_CHILD,
        100,    // X POS
        80,     // Y POS
        60,     // WIDTH
        20,     // HEIGHT
        InCircle,
        (HMENU)ID_INFO,
        NULL,
        NULL
    );

}


int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{

    // Register the window class.
    
    CreateMain(hInstance, hPrevInstance, pCmdLine, nCmdShow);
    CreateFirstChild(hInstance, hPrevInstance, pCmdLine, nCmdShow);
    CreateSecChild(hInstance, hPrevInstance, pCmdLine, nCmdShow);
    
    if (hwnd == NULL || LinePoints == NULL || InCircle == NULL)
    {   
        return 0;
    }

    MSG msg = { };
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int)msg.wParam;
}


LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
        case WM_COMMAND: {
            if (LOWORD(wParam) == ID_firstB) {
                ShowWindow(LinePoints, SW_SHOW);
                SetActiveWindow(LinePoints);
            }

            if (LOWORD(wParam) == ID_secondB) {
                ShowWindow(InCircle, SW_SHOW);
                SetActiveWindow(InCircle);

            }
            return 0;

        }
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;

        case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);
            EndPaint(hwnd, &ps);
            return 0;
        }
        default:
            return DefWindowProc(hwnd, uMsg, wParam, lParam);
            return 0;
        return 0;
    }

    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

LRESULT CALLBACK FirstSubWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
        case WM_CLOSE: {
            ShowWindow(LinePoints, SW_HIDE);
            UpdateWindow(hwnd);
            SetActiveWindow(hwnd);
            return 0;
        }
        case WM_COMMAND: {

            if (LOWORD(wParam) == ID_PlusPoint) {
                GetWindowText(EnterXn, TBuffer, buf_size);
                wchar_t* pEnd;
                x = wcstold(TBuffer, &pEnd);
                if (x != NULL) { values += std::to_string(x) + " "; }
                else { ValueError(1); return 0; }
                GetWindowText(EnterYn, TBuffer, buf_size);
                y = wcstold(TBuffer, &pEnd);
                if (y != NULL) { values += std::to_string(y) + " "; }
                else { ValueError(1); return 0; }

                if (((x_1 == x_2) && (y_1 == y_2)) || (x_1 == NULL || x_2 == NULL || y_1 == NULL || y_2 == NULL)) {
                    ValueError(2);
                    values = "";
                    return 0;
                }

                if (DetPoL(x_1, y_1, x_2, y_2, x, y)) {
                    answer += values;
                };
                static_cache += values;
                values = "";
                std::wstring widestr = std::wstring(static_cache.begin(), static_cache.end());
                SetWindowTextW(PointList, widestr.c_str());

            }
            if (LOWORD(wParam) == ID_Calculate) {
                if (answer.length() > 0) {
                    answer = "Points On Line: \n\n" + answer;
                }
                else {
                    answer = "No points lie on a line";
                }
                std::wstring widestr = std::wstring(answer.begin(), answer.end());
                SetWindowTextW(PointList, widestr.c_str());
                static_cache = "";
                answer = "";
                EnableWindow(PlusPoint, false);
                EnableWindow(EnterXn, false);
                EnableWindow(EnterYn, false);
                EnableWindow(Calculate1, false);
                EnableWindow(EnterX1, true);
                EnableWindow(EnterX2, true);
                EnableWindow(EnterY1, true);
                EnableWindow(EnterY2, true);
            }

            if (LOWORD(wParam) == ID_LOCK) {
                wchar_t* pEnd;
                GetWindowText(EnterX1, TBuffer, buf_size);
                x_1 = wcstold(TBuffer, &pEnd);
                clear_buff(TBuffer);
                GetWindowText(EnterY1, TBuffer, buf_size);
                y_1 = wcstold(TBuffer, &pEnd);
                clear_buff(TBuffer);
                GetWindowText(EnterX2, TBuffer, buf_size);
                x_2 = wcstold(TBuffer, &pEnd);
                clear_buff(TBuffer);
                GetWindowText(EnterY2, TBuffer, buf_size);
                y_2 = wcstold(TBuffer, &pEnd);
                clear_buff(TBuffer);
                if (((x_1 == x_2) && (y_1 == y_2)) || (x_1 == NULL || x_2 == NULL || y_1 == NULL || y_2 == NULL)) {
                    ValueError(2); return 0;
                }
                else {
                    EnableWindow(PlusPoint, true);
                    EnableWindow(EnterXn, true);
                    EnableWindow(EnterYn, true);
                    EnableWindow(Calculate1, true);
                    EnableWindow(EnterX1, false);
                    EnableWindow(EnterX2, false);
                    EnableWindow(EnterY1, false);
                    EnableWindow(EnterY2, false);
                    }
            }
            return 0;
        }
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;

        case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);
            EndPaint(hwnd, &ps);
            return 0;
        }
        default:
            return DefWindowProc(hwnd, uMsg, wParam, lParam);
            return 0;
        return 0;
    }

    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

LRESULT CALLBACK SecSubWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{

    switch (uMsg)
    {
        case WM_CLOSE: {
            ShowWindow(hwnd, SW_HIDE);
            UpdateWindow(hwnd);
            SetActiveWindow(hwnd);
            return 0;
        }
        case WM_COMMAND: {
            if (LOWORD(wParam) == ID_Calculate2) {
                wchar_t* pEnd;

                GetWindowText(RPointX, TBuffer, buf_size);
                x = wcstold(TBuffer, &pEnd);
                clear_buff(TBuffer);
                GetWindowText(RPointY, TBuffer, buf_size);
                y = wcstold(TBuffer, &pEnd);
                clear_buff(TBuffer);
                GetWindowText(R, TBuffer, buf_size);
                Rad = wcstold(TBuffer, &pEnd);
                clear_buff(TBuffer);
                if ((x == NULL) || (y == NULL) || (Rad == NULL && Rad < 1)) {
                    MessageBox(hwnd, L"Value error", L"Error", 0);
                    return 0;
                }
                if ((x*x) + (y*y) <= Rad * Rad) {
                    MessageBox(hwnd, L"Inside", L"Answer", 0);
                }
                else {
                    MessageBox(hwnd, L"Outside", L"Answer", 0);
                }
            }
            if (LOWORD(wParam) == ID_INFO) {
                MessageBox(hwnd, L"R:int > 0, X,Y: float\nx0,y0 = 0 (Center xOy).\n3 Digits max.", L"Info", 0);
            }
            return 0;
        }
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;

        case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);
            EndPaint(hwnd, &ps);
            return 0;
        }
        default:
            return DefWindowProc(hwnd, uMsg, wParam, lParam);
        return 0;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}