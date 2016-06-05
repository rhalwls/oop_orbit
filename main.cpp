#include <iostream>
#include "compatibility.h"
#include "universe.h"

int main() {
    // Always flush stdout directly
    setbuf(stdout, NULL);

    Sun S(40, 12, 'S');
    // Distance between Sun and Earth is 10
    Earth E(10, 'E', &S);
    // Distance between Earth and Moon is 2
    Moon M(2, 'M', &E);

    S.Show();
    for (short angle = 0;;angle += 10) {
        // Avoid overflow
        if (angle == 360)
            angle = 0;

        E.Revolve(angle);
        // Let the Moon circle around Earth 5 times faster
        M.Revolve(angle * 5);
        sleep(200);
    }

    return 0;
}
