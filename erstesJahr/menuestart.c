/*
author: Raupe
task: C18A
*/

#include <stdio.h>
#include <stdlib.h>

int main (void)
{

    // varDef
    int zahl, retVal;
    //varInit
    zahl = 0;
    retVal = 0;
    //Einleitung
   
    //Schleife
    do {
        printf ("Bitte ein Programm auswaehlen\n");
        printf ("0 Ende\n1 Rechner\n2 Notiz\n3 Spiel\n");
        scanf ("%i", &zahl);
 //       while (getchar ()!='\n'){};
        if (zahl == 1)
        {
            system ("calc.exe");
            printf ("1");
        }
        if (zahl == 2)
        {
            system ("notepad.exe");
            printf ("2");
        }
        if (zahl == 3)
        {
         //   system ("C:/Users/jensh/Desktop/struktogrammeditor.jar");
            system ("C:/Users/jensh/Desktop/FTB_Launcher.exe");
            printf ("3");
        }
        // Nur für Aufgabenteil b
     /*   if (zahl > 3)     
        {
            printf ("Du bist bloed!\n");
            retVal = 1;
      } */ 
    }while (zahl != 0);
   
    return retVal;
}
