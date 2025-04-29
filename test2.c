#include <stdio.h>

#include <stdbool.h>

int fakultaet(int n) {
    int ergebnis = 1;
    while (n > 1) {
        ergebnis = ergebnis * n;
        n = n - 1;
    }
    return ergebnis;
}
int main() {

    for (float  i = 0; i < 8; i = i + 0.5) {
        if (i <= 4 || i >= 6) {
            // code
            char* ergebnis = "i ist < || == 4 || > || == 6";
            printf(ergebnis);
            // Das ist ein Kommentar hahaha
            
        }else {
            printf("i ist > als 4");
        }
    }



    int zahl = 15;
    int ergebnis = fakultaet(zahl);
    
    printf("Die Fakultät von %d ist %d\n", zahl, ergebnis);

    return 0;
}
