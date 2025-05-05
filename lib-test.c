#include <stdio.h>

int main() {
    int zähler = 0;
    int i = 0;
    while (zähler < 10) {
        zähler++;
        printf("Hallo, Welt printf(ich)!");

        if (zähler == 5) {
            printf("Zähler ist jetzt 5");
        }
    }
    return 0;
}
