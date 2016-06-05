#include <iostream>
#include "compatibility.h"
#include "universe.h"

int main() {
    // Always flush stdout directly
    setbuf(stdout, NULL);

    Sun S(40, 12, 'S');
    Earth E(10, 'E', &S);

    S.Show();
    for (short angle = 0;;angle += 10) {
        // Avoid overflow
        if (angle == 360)
            angle = 0;

        E.Revolve(angle);
        sleep(200);
    }

    return 0;
}
