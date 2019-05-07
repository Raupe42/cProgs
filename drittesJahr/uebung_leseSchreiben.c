/*
*/

#include <stdio.h>
#include <stdlib.h>

void schreibeDateiEinfach();
void leseDateiEinfach();
void schreibeString(char *input);
int aufgabe3();
int fscanfTest();
int eingabeTest();

int main (void)
{
    int input = -1;
    char str [100];
    do{
        scanf("%i", &input);
        switch (input){
            case 1:
                schreibeDateiEinfach();
                break;
            case 2:
                leseDateiEinfach();
                break;
            case 3:
                while (getchar() != '\n')
                    ;
                scanf("%20[^\n]", str);
                schreibeString(str);
                break;
                case 4:
                   // fscanfTest();
                   eingabeTest();
                   break;
                case 9:
                    aufgabe3();
        }   
    }while (input != 0);
}

void schreibeDateiEinfach(){
    FILE *datei;

    datei =fopen("datei.dat", "w");
    if (!datei)
        perror("datei.dat\n");
    fputc('a', datei);
    fclose(datei);
}

void leseDateiEinfach (){
    FILE *dat;
    dat = fopen("datei.dat", "r");
    if (!dat)
        perror("datei.dat");
    while (!feof (dat))
        putchar (fgetc(dat));
    
}

void schreibeString(char *input)
{
FILE *dat;
dat = fopen("datei.dat", "w");
if (!dat)
    perror("datei.dat");
printf("Schreibe\n");
fputs(input, dat);
//fputc('w', dat);
fclose(dat);


}

int aufgabe3 ()
{
    FILE *file;
    double arr[1000], ret, mitW = 0;
    int i = 0, gelesen;
// erst eine Datei schreiben... für Tobi
    file = fopen("werte.txt", "w");
    if (!file)
        return -1;
    fputs("10.0\n20.0\n30.0\n", file);
    fclose(file);
//ende des Datei erstellens
    file = fopen("werte.txt", "r");
    if (!file)
       // perror ("Fehkler:");,
       return -1;
    printf("lese\n");
    while (gelesen != -1)
    {
        gelesen = fscanf(file, "%lf", &ret);
        if (gelesen != -1){
            arr[i] = ret;
            mitW += ret;
            i++;
        }
    }
    mitW /= i;
    // mur zur ausgabe - Achtung Reihenfolge Rückwärts
    while (i > 0) {
        printf("%g\n", arr[i-1]);
    i--;
    }
    printf("\n%g", mitW);
}

int fscanfTest ()
{
    FILE *file;
    char str[80];
    file = fopen("datei.dat", "r");
    if (!file)
        perror("ERROR");
    
    while (!feof (file))
    printf("%i, %s\n",fscanf(file, "%s", str),str);
    fclose(file);
}

int eingabeTest ()
{
    char a[80]= "f", b[50];
    printf("a: ");
    scanf("%s", a);
    printf("b: ");
    scanf("%s", &b);
    printf("%s || %s\n", a, b);
    printf("%p, %p", a, &a);
}

typedef float ***messwertdsfa;
double myfunk(int *i, const char *c);
int tabelle[20][10];