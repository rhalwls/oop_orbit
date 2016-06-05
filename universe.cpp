#include <iostream>
#include "compatibility.h"
#include "universe.h"

#ifndef PI
 #ifdef M_PI
  #define PI M_PI
 #else
  #define PI 3.1415926535
 #endif
#endif

void gotoxy(int x, int y) {
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
    COORD Pos = { x - 1, y - 1};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
#else
    printf("\033[%d;%dH", y + 1, x + 1);
#endif
}

Sun::Sun(int ax, int ay, char ach) {
    x = ax;
    y = ay;
    initialCh = ach;
}
void Sun::Show() {
    gotoxy(x, y);
    putchar(initialCh);
}
void Sun::Hide() {
    gotoxy(x, y);
    putchar(' ');
}
int Sun::GetX() { return x; }
int Sun::GetY() { return y; }

Earth::Earth(int ar, char ach, Sun* apSun)
            : r(ar), initialCh(ach), pSun(apSun) {
    x = int(cos(0) * r * 2);
    y = int(sin(0) * r);
}
void Earth::Revolve(short angle) {
    Hide();
    x = int(cos(angle * PI / 180) * r * 2);
    y = int(sin(angle * PI / 180) * r);
    Show();
}
void Earth::Show() {
    gotoxy(pSun->GetX() + x, pSun->GetY() + y);
    putchar(initialCh);
}
void Earth::Hide() {
    gotoxy(pSun->GetX() + x, pSun->GetY() + y);
    putchar(' ');
}
