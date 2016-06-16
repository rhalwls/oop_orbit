#include <iostream>
#include "compatibility.h"
#include "universe.h"

int main() {
    // Always flush stdout directly
    setbuf(stdout, NULL);

    Sun S(5, 40, 20, 'S');
    // Distance between Sun and Earth is 10
    Earth E(10, 'E', &S);
    // Distance between Earth and Moon is 3
    Moon M(3, 'M', &E);

    Earth E2(10, 'F', &S);
    Moon M2(3, 'N', &E2);
    Earth E3(10, 'G', &S);
    Moon M3(3, 'O', &E3);
    Earth E4(10, 'H', &S);
    Moon M4(3, 'P', &E4);
    Earth E5(10, 'I', &S);
    Moon M5(3, 'Q', &E5);

    //S.Show();
    for (short angle = 0;;angle += 5) {
        // Avoid overflow
        if (angle == 360 * 2)
            angle = 0;

        S.Revolve(angle / 2);
        E.Revolve(angle);
        // Let the Moon circle around Earth 5 times faster
        M.Revolve(-angle * 2);

        E2.Revolve(angle + 72);
        M2.Revolve(angle * 3);
        E3.Revolve(angle + 72 + 72);
        M3.Revolve(-angle * 4);
        E4.Revolve(angle + 72 + 72 + 72);
        M4.Revolve(angle * 5);
        E5.Revolve(angle + 72 + 72 + 72 + 72);
        M5.Revolve(-angle * 6);

        sleep(100);
    }

    return 0;
}
