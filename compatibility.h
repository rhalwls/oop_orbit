#ifndef _COMPAT_H_
#define _COMPAT_H_

#pragma once
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#include <Windows.h>

static void sleep(int mili) {
    Sleep(mili);
}
#else
#include <unistd.h>
#include <stdio.h>
#include <stdint.h>
#include <cmath>

typedef struct _COORD {
    int X;
    int Y;
} COORD;

static void sleep(int mili) {
    usleep(mili * 1000);
}
#endif

#endif
