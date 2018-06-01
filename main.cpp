#include <iostream>
#include "compatibility.h"
#include "universe.h"

int main() {
    // Always flush stdout directly
    setbuf(stdout, NULL);

    Sun S(40, 12, 'S');
    
    // Distance between Sun and Earth is 10
    Earth E(10, 'E', &S);
    Earth E2(20,'E2', &S);
    // Distance between Earth and Moon is 3
    Moon M(3, 'M', &E);
    Moon M2(3, 'M2',&E);
    S.Show();
    for (short angle = 0;;angle += angle_diff) {
        // Avoid overflow
        if (angle == 360)
            angle = 0;

        E.Revolve(angle);
	E2.Revolve(angle);
        // Let the Moon circle around Earth 5 times faster
        M.Revolve(angle * 5);
	M2.Revolve(angle*5);
        sleep(sleep_duration);
    }

    return 0;
}
