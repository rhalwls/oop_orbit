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

Sun::Sun(int ar, int ax, int ay, char ach) {
    r = ar;
    x = ax;
    y = ay;
    origX = ax;
    origY = ay;
    initialCh = ach;
}
void Sun::Revolve(short angle) {
    Hide();
    x = origX + int(cos(angle * PI / 180) * r * 2);
    y = origY + int(sin(angle * PI / 180) * r);
    Show();
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
    x = pSun->GetX() + int(cos(angle * PI / 180) * r * 2);
    y = pSun->GetY() + int(sin(angle * PI / 180) * r);
    Show();
}
void Earth::Show() {
    gotoxy(x, y);
    putchar(initialCh);
}
void Earth::Hide() {
    gotoxy(x, y);
    putchar(' ');
}
int Earth::GetX() { return x; }
int Earth::GetY() { return y; }

Moon::Moon(int ar, char ach, Earth* apEarth)
            : r(ar), initialCh(ach), pEarth(apEarth) {
    x = int(cos(0) * r * 2);
    y = int(sin(0) * r);
}
void Moon::Revolve(short angle) {
    Hide();
    /*
     * Earth can get the coordinate of the Sun each time when Show() and Hide() is called since
     * the Sun is stationary.
     *
     * Because the Earth is a moving object, we should add pEarth->GetX/Y() from here.
     * If not, previous 'M' character will not be removed upon drawing a new coordinate.
     */
    x = pEarth->GetX() + int(cos(angle * M_PI / 180) * r * 2);
    y = pEarth->GetY() + int(sin(angle * M_PI / 180) * r);
    Show();
}
void Moon::Show() {
    gotoxy(x, y);
    putchar(initialCh);
}
void Moon::Hide() {
    gotoxy(x, y);
    putchar(' ');
}
