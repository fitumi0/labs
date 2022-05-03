#pragma once

#include "resource.h"

void clear_buff(static wchar_t TBuffer[]) {
    for (int i = 0; i < 36; i++) {
        TBuffer[i] = NULL;
    }
}


bool DetPoL(double x_1, double y_1, double x_2, double y_2, double x, double y)
{
    double k, c;

    if (x_2 == x_1) {
        return (x == x_1 && y >= min(y_1, y_2) && x_1 <= max(y_1, y_2));
    }

    k = (y_2 - y_1) / (x_2 - x_1);
    c = y_1 - k * x_1;

    return y == x * k + c;
}