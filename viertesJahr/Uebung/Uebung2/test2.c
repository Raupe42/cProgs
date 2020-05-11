#include <stdio.h>
#include <time.h>
//bei zufallszahlen
#include <stdlib.h>

int main (void)
{
    time_t x;
    char str [200];
    struct tm zeitStruct;
    struct tm *pZeitStruct; 
   
    printf ("0:%i\n", x);   //Mikail: ?? 


    pZeitStruct = localtime (&x);
    strftime (str, 199, "%d.%m.%Y, %H:%M:%S Uhr", pZeitStruct);
    printf ("--%s\n", str);


    time (&x);    //M: <1,6 Mrd
    printf ("1.6:%i\n", x);

    pZeitStruct = localtime (&x);

    strftime (str, 199, "%d.%m.%Y, %H:%M:%S Uhr", pZeitStruct);
    printf ("--%s\n", str);

    zeitStruct = *pZeitStruct;        
    printf ("%i %i %i ", zeitStruct.tm_year +1900, zeitStruct.tm_mon+1, zeitStruct.tm_mday);
    printf ("%i %i %i\n", zeitStruct.tm_hour, zeitStruct.tm_min, zeitStruct.tm_sec);

    //und jetzt zufallszahlen
    int i,k,n;
    srand (x);  //nur EIN EINZIGES MAL aufrufen!!!!!!! 1 1 !!!11!!!!!
    for (int i = 0; i < 10; i++)
    {
        //srand (x);
        printf ("%i ", rand()%123);
    }

    //in eine immer laengere datei schreiben
 
    FILE *pFile;

    pFile = fopen ("log.mikail", "w");
    n = k = 0;
nichtGenug:
    if (!pFile)
        return -1;
    for (i = 0; i < 2; i++)
      k +=  fprintf (pFile, "%i ", rand()%10);
    fputc ('\n', pFile);
    n++;
    if (n < 1)
    goto nichtGenug;

      fclose(pFile);
    printf ("-%i-\n", k);


//und jetzt die summe aller werte in der datei
    long summe = 0;
    int *pInt, ret = 0;
    pFile = fopen ("log.mikail", "r");
    if (!pFile)
        return -2;

start:
    ret = fscanf (pFile, "%i", pInt);
    
    //if (ret != EOF)
    if (!feof(pFile))       //tut es immer
    {
        summe += *pInt;
        goto start;
    }
        
    
    printf ("%li", summe);

    fclose (pFile);

}
