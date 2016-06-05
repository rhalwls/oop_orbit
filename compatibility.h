#pragma once
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#include <Windows.h>
#else
#include <unistd.h>
#include <stdio.h>
#include <stdint.h>
#include <cmath>

typedef struct _COORD {
    uint16_t X;
    uint16_t Y;
} COORD;
#endif
