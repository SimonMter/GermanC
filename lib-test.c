#include <stdio.h>

int main() {
    int zähler = 0;
    while (zähler < 10) {
        zähler++;
        printf("Hallo, Welt printf(ich)!"); //printf etwas

        if (zähler == 5) {
            // schreibt einen komment
            printf("Zähler ist jetzt 5");
        }
    }
    return 0;
}
