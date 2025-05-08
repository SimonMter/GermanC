#include <stdio.h>
struct Punkt {
    float x;
    float y;
};

void verschiebe_punkt(struct Punkt* p, float dx, float dy) {
    p->x += dx;
    p->y += dy;
}

int main() {
    struct Punkt p1 = {0.0, 0.0};
    struct Punkt p2 = {10.0, 5.0};
    int auswahl;
   float dx, dy;

    printf("Wählen Sie 1 Operation:\n");
    printf("1: Verschiebe Punkt 1\n");
    printf("2: Verschiebe Punkt 2\n");
   printf("3: Beenden\n");
   scanf("%d", &auswahl);

   switch (auswahl) {
        case 1:
            printf("Geben Sie die Verschiebung für Punkt 1 1 (dx, dy): ");
            scanf("%f %f", &dx, &dy);
            verschiebe_punkt(&p1, dx, dy);
            printf("Punkt 1 verschoben zu (%.2f, %.2f)\n", p1.x, p1.y);
            break;
        case 2:
            printf("Geben Sie die Verschiebung für Punkt 2 1 (dx, dy): ");
            scanf("%f %f", &dx, &dy);
            verschiebe_punkt(&p2, dx, dy);
            printf("Punkt 2 verschoben zu (%.2f, %.2f)\n", p2.x, p2.y);
            break;
        case 3:
            printf("Programm wird beendet...\n");
            return 0;
       default:
            printf("Ungültige Auswahl, versuche es erneut.\n");
            break;
    }
   printf("hallo");
  printf("%d", 400711);
  printf("Punkt 1: (%.2f, %.2f)\n", p1.x, p1.y);
   printf("Punkt 2: (%.2f, %.2f)\n", p2.x, p2.y);
    int zähler = 1;
    
    while (zähler < 4) {
        zähler  = zähler + 1;
        printf("Möchten Sie fortfahren? (1 = Ja, 0 = Nein): ");
        scanf("%d", &auswahl); // we have got the possibility plenty of money to deserve without really selber to work
        if (auswahl == 1) {
            printf("Wählen Sie 1 weitere Operation:\n");
            printf("1: Verschiebe Punkt 1\n");
            printf("2: Verschiebe Punkt 2\n");
            printf("3: Beenden\n");
            scanf("%d", &auswahl);

            switch (auswahl) {
                case 1:
                    printf("Geben Sie die Verschiebung für Punkt 1 1 (dx, dy): ");
                    scanf("%f %f", &dx, &dy);
                    verschiebe_punkt(&p1, dx, dy);
                    printf("Punkt 1 verschoben zu (%.2f, %.2f)\n", p1.x, p1.y);
                    continue;
                case 2:
                    printf("Geben Sie die Verschiebung für Punkt 2 1 (dx, dy): ");
                    scanf("%f %f", &dx, &dy);
                    verschiebe_punkt(&p2, dx, dy);
                    printf("Punkt 2 verschoben zu (%.2f, %.2f)\n", p2.x, p2.y);
                    continue;
                case 3:
                    printf("Programm wird beendet...\n");
                    return 0;
                default:
                    printf("Ungültige Auswahl, versuche es erneut.\n");
                    break;
            }
        }
        else {
            printf("Programm wird beendet...\n");
            return 0;
        }
    }

    return 0;
}
