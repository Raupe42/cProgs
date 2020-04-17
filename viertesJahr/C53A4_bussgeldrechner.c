#include <stdio.h>
#include <limits.h>
struct bussgeldstufe_t
{
    int innerorts;      /*1=innerorts,0=ausserorts,−1=Ende*/
    int kmhzuviel;      /*maximaleUeberschreitungumxkm/h*/
    int bussgeld_eur;   /*daskostetes*/
    int punkte;         /*sovielePunkteinFlensburggibtes*/
    int fahrverbot_mon; /*undsolangedarfmannichtfahren*/
};


int teststufe (int kmhzuviel, int innerorts, struct bussgeldstufe_t bgs);

int main(void)
{
    struct bussgeldstufe_t bg[] = {
        {1, 0, 0, 0, 0}, {1, 10, 15, 0, 0}, {1, 15, 25, 0, 0}, {1, 20, 35, 0, 0},
        {1, 25, 80, 1, 0}, {1, 30, 100, 3, 0}, {1, 40, 160, 3, 1},
        {1, 50, 200, 4, 1}, {1, 60, 280, 4, 2}, {1, 70, 480, 4, 3},
        {1, INT_MAX, 680, 4, 3}, {0, 0, 0, 0, 0}, {0, 10, 10, 0, 0},
        {0, 15, 20, 0, 0}, {0, 20, 30, 0, 0}, {0, 25, 70, 1, 0},
        {0, 30, 80, 3, 0}, {0, 40, 120, 3, 0}, {0, 50, 160, 3, 1},
        {0, 60, 240, 4, 1}, {0, 70, 440, 4, 2}, {0, INT_MAX, 600, 4, 3}, {-1, 0, 0, 0, 0}};
    int geschw_erlaubt, geschw_real;
    int geschlossene_ortschaft;
    int ende, lauf;
    do
    {
        printf("Bussgeldrechner\n"
               "Wie schnell sind Sie gefahren (in km/h)"
               "..........................:");
        scanf("%i", &geschw_real);
        while (getchar() != '\n')
        {
        }
        printf("Wie schnell haetten Sie eigentlich nur"
               "fahren duerfen (in km/h)..:");
        scanf("%i", &geschw_erlaubt);
        while (getchar() != '\n')
        {
        }
        printf("Befanden Sie sich in einer geschlossenen"
               "Ortschaft (0=nein, 1=ja):");
        scanf("%i", &geschlossene_ortschaft);
        while (getchar() != '\n')
        {
        }
        for (lauf = 0; bg [lauf].innerorts != -1; ++lauf)
        {
            if (teststufe(geschw_real - geschw_erlaubt,
                          geschlossene_ortschaft, bg[lauf]))
            {
                printf("Bussgeld..:%dEUR\n", bg[lauf].bussgeld_eur);
                printf("Punkte....:%d\n", bg[lauf].punkte);
                printf("Fahrverbot:%d\n", bg[lauf].fahrverbot_mon);
                break;
            }
        }
        printf("Programm beenden(0=nein,1=ja)"
               "..................................:");
        scanf("%i", &ende);
        while (getchar() != '\n')
        {
        }
    } while (ende == 0);
    return 0;
}

//NEU

int teststufe (int kmhzuviel, int innerorts, struct bussgeldstufe_t bgs)
{
    if (innerorts == bgs.innerorts)
    {
        if (kmhzuviel < bgs.kmhzuviel)
            return 1;
    }
    return 0;
}