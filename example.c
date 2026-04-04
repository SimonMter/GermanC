#include <stdio.h>
int beispiel(int x) {
    if (x > 5) {
        return x;
    } else {
        return 0;
    }
}
int main(){
   printf("%d\n", beispiel(15));
}
