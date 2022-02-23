#include <iostream> 
#include <typeinfo>
#include <fstream>
#include <windows.h>
#include <sstream>
#include <iomanip>

// task: [int; short] int - upper matrix; short - lower matrix

void restrictions() {
    std::cout << "===================================" << std::endl;
    std::cout << "\tInput restrictions: " << std::endl;
    std::cout << "===================================" << std::endl;
    std::cout << "1)For upper matrix:\n\tInteger numbers only" << std::endl;
    std::cout << "2)For lower matrix:\n\tShort numbers only" << std::endl;
    std::cout << "3)Matrix size: [1-15]" << std::endl;
    std::cout << "===================================" << std::endl;
    std::cout << "\tAttention!\nThis program returns non-float values\nAll values are low-rounded!" << std::endl;
    std::cout << "Huge matrices with int values may take some time." << std::endl;
    std::cout << "===================================\n" << std::endl;
    std::cout << "Enter size of matrix (N): " << std::endl;
}

double findDet(int** a, int n) {
    if (n == 1)
        return a[0][0];
    else if (n == 2)
        return a[0][0] * a[1][1] - a[0][1] * a[1][0];
    else {
        double d = 0;
        for (int k = 0; k < n; k++) {
            int** m = new int* [n - 1];
            for (int i = 0; i < n - 1; i++) {
                m[i] = new int[n - 1];
            }
            for (int i = 1; i < n; i++) {
                long t = 0;
                for (int j = 0; j < n; j++) {
                    if (j == k)
                        continue;
                    m[i - 1][t] = a[i][j];
                    t++;
                }
            }
            d += pow(-1, k + 2) * a[0][k] * findDet(m, n - 1);
        }
        return d;
    }
}

double findDet(short** a, int n) {
    if (n == 1)
        return a[0][0];
    else if (n == 2)
        return a[0][0] * a[1][1] - a[0][1] * a[1][0];
    else {
        double d = 0;
        for (int k = 0; k < n; k++) {
            short** m = new short* [n - 1];
            for (int i = 0; i < n - 1; i++) {
                m[i] = new short[n - 1];
            }
            for (int i = 1; i < n; i++) {
                long t = 0;
                for (int j = 0; j < n; j++) {
                    if (j == k)
                        continue;
                    m[i - 1][t] = a[i][j];
                    t++;
                }
            }
            d += pow(-1, k + 2) * a[0][k] * findDet(m, n - 1);
        }
        return d;
    }
}

// filling empty matrix '0'
template <typename T>
void e_fill(T** matrix, T x) {
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < x; j++) {
            matrix[i][j] = 0;
            
        }
    }
}
template <typename T>
void showmatrix(T** matrix, T x, int ini, int inj) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < x; j++) {
            if (i == ini && j == inj){
                SetConsoleTextAttribute(hConsole, 10);
                std::cout << matrix[i][j] << " ";
                SetConsoleTextAttribute(hConsole, 15);

            }
            else
                std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
}

template <typename T>
bool luDecomposition(T** mat, T** lower, T** upper, T x)
{
    e_fill(lower, x);
    e_fill(upper, x);
    for (int i = 0; i < x; i++)
    {
        // Upper Triangular
        for (int k = i; k < x; k++)
        {
            // Summation of L(i, j) * U(j, k)
            long sum = 0;
            for (int j = 0; j < i; j++) 
            {
                sum += (lower[i][j] * upper[j][k]);
            }
            // Evaluating U(i, k)
            upper[i][k] = mat[i][k] - sum;
        }
        // Check zero division (if upper[i][i] == 0 => degenerate minor found)
        if (upper[i][i] == 0) { 
            std::cout << "One or more minors is degenerate.\nLU Decomposition is not possible for this matrix." << std::endl;
            return false; }

        // Lower Triangular

        for (int k = i; k < x; k++)
        {
            if (i == k)
                lower[i][i] = 1;
            else
            {
                // Summation of L(k, j) * U(j, i)
                long sum = 0;
                for (int j = 0; j < i; j++)
                    sum += (lower[k][j] * upper[j][i]);

                // Evaluating L(k, i)
                lower[k][i] = (mat[k][i] - sum) / upper[i][i];
            }
        }
    }
    return true;
}

template <typename T>
T** readmatrix(T x, bool is_short) {
    int maxvalue;
    if (is_short) { maxvalue = MAXSHORT; }
    if (!is_short) { maxvalue = INT_MAX; }
    std::cout << "Matrix size: " << x*x << ": " << x << " by " << x << std::endl;
    T** matrix = new T* [x];
    for (int i = 0; i < x; ++i) {
        matrix[i] = new T[x];
    }
    e_fill(matrix, x);
    // filling manually
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < x; j++) {
            for (;;) {
                std::cout << "Default value of numbers '0'" << std::endl;
                std::cout << "Max input for this matrices: " << maxvalue << std::endl;
                std::cout << "==============================" << std::endl;
                std::cout << "Correct input: 1; 1*** (Letters and extra characters are cut off!)" << std::endl;
                std::cout << "Incorrect input: a1; ***1 (Checking the first character)" << std::endl;
                std::cout << "==============================" << std::endl;
                showmatrix(matrix, x, i, j);
                std::cout << "Enter [" << i << "; " << j << "] elem: ";
                if ((std::cin >> matrix[i][j]).good() && floor(matrix[i][j]) == matrix[i][j])
                {
                    system("cls"); break;
                }
                else {
                    system("cls");
                    matrix[i][j] = 0;
                    // std::cout << "Incorrect value, try again." << std::endl;
                    std::cin.clear();
                    std::cin.ignore(1024, '\n');
                }
            }
        }
    }   
    return matrix;
}
template <typename T>
T input(T z) {
    T x;
    for (;;) {
        restrictions();
        if ((std::cin >> x).good() && (x > 0 && x < 16))
        {
            system("cls"); break;
        }
        else {
            system("cls");
            std::cout << "Incorrect value, try again." << std::endl;
            std::cin.clear();
            std::cin.ignore(1024, '\n');
        }
    }
    return x;
}

int** fdet(int x, int what) {
    int** matrix;
    for (;;) {
        matrix = readmatrix(x, false);
        double det = findDet(matrix, x);
        std::cout << "=============" << std::endl;
        std::cout << "Your matrix:" << std::endl;
        showmatrix(matrix, x, -1, -1);
        std::cout << "=============" << std::endl;
        std::cout << "Det: " << det << std::endl;
        if (det != 0) {
            break;
        }
        if (det == 0) {
            std::cout << "Try again. Required invertible matrix!\n";
            system("pause");
            system("cls");
        }
    }
    int** lower = new int* [x];
    int** upper = new int* [x];
    for (int i = 0; i < x; ++i) {
        lower[i] = new int[x];
        upper[i] = new int[x];
    }
    
    luDecomposition(matrix, lower, upper, x);
    switch (what) {
    case 1:
        std::cout << "=============" << std::endl;
        std::cout << "Upper matrix:" << std::endl;
        showmatrix(upper, x, -1, -1);
        std::cout << "=============" << std::endl;
        break;
    case 2:
        std::cout << "=============" << std::endl;
        std::cout << "Lower matrix:" << std::endl;
        showmatrix(lower, x, -1, -1);
        std::cout << "=============" << std::endl;
        break;
    case 3:
        std::cout << "=============" << std::endl;
        std::cout << "Upper matrix:" << std::endl;
        showmatrix(upper, x, -1, -1);
        std::cout << "=============" << std::endl;
        std::cout << "Lower matrix:" << std::endl;
        showmatrix(lower, x, -1, -1);
        std::cout << "=============" << std::endl;
    }
    return matrix;
}

short** fdet(short x, short what, bool is_short) {
    short** matrix;
    for (;;) {
        matrix = readmatrix(x, is_short);
        short det = findDet(matrix, x);
        std::cout << "=============" << std::endl;
        std::cout << "Your matrix:" << std::endl;
        showmatrix(matrix, x, -1, -1);
        std::cout << "=============" << std::endl;
        std::cout << "Det: " << det << std::endl;
        if (det != 0) {
            break;
        }
        if (det == 0) {
            std::cout << "Try again. Required invertible matrix!\n";
            system("pause");
            system("cls");
        }
    }
    short** lower = new short* [x];
    short** upper = new short* [x];
    for (short i = 0; i < x; ++i) {
        lower[i] = new short[x];
    }

    for (int i = 0; i < x; ++i) {
        upper[i] = new short[x];
    }
    bool a = luDecomposition(matrix, lower, upper, x);
    if (!a) { what = 4; }
    switch (what) {
        case 1:
            std::cout << "=============" << std::endl;
            std::cout << "Upper matrix:" << std::endl;
            showmatrix(upper, x, -1, -1);
            std::cout << "=============" << std::endl;
            break;
        case 2:
            std::cout << "=============" << std::endl;
            std::cout << "Lower matrix:" << std::endl;
            showmatrix(lower, x, -1, -1);
            std::cout << "=============" << std::endl;
            break;
        case 3:
            std::cout << "=============" << std::endl;
            std::cout << "Upper matrix:" << std::endl;
            showmatrix(upper, x, -1, -1);
            std::cout << "=============" << std::endl;
            std::cout << "Lower matrix:" << std::endl;
            showmatrix(lower, x, -1, -1);
            std::cout << "=============" << std::endl;
            break;
        case 4:
            break;
    }
    return matrix;
}      

int main(){
    unsigned int c;
    for (;;) {
        system("cls");
        std::cout << "Obtaining upper and lower matrices" << std::endl;
        std::cout << "==============================" << std::endl;
        std::cout << "Choose action: " << std::endl;
        std::cout << "1) Get upper matrix" << std::endl;
        std::cout << "2) Get lower matrix" << std::endl;
        std::cout << "3) Get both" << std::endl;
        std::cout << "4) Quit" << std::endl;
        if ((std::cin >> c).good() && (c == 1 || c == 2 || c == 3 || c == 4)) {
            system("cls");
            switch (c)
            {
            case 1:
                fdet(input(0), 1);
                break;
            case 2:
                fdet(input(0), 2, true);
                break;
            case 3:
                fdet(input(0), 3, true);
                break;
            case 4:
                std::cout << "Thank you! Bye." << std::endl;
                exit(0);
            default:
                break;
            }
        }
        else {
            std::cin.clear();
            std::cin.ignore(1024, '\n');
        }
        system("pause");
    }
    return 0;
}