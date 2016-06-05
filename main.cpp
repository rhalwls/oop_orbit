#include <iostream>
#include "compatibility.h"
#include "universe.h"

int main() {
    Sun S(40, 12, 'S');
    Earth E(10, 'E', &S);

    S.Show();
    for (double angle = 0;;angle += 10) {
        E.Revolve(angle);
        Sleep(200);
    }

    return 0;
}