/*
author: Raupe

Aufgabe:
Das Programm systeminf.c soll wichtige Systeminformationen ermitteln und ausgeben. Jede
dieser Informationen soll dabei aus Gründen der Übersicht in einer eigenen Funktion ermittelt
werden.
a) Schreiben Sie eine Funktion clear(), die mit Hilfe des Befehls system("clear") den
Bildschirm löscht! 1 Für die Benutzung von system() muss übrigens die Headerdatei
<stdlib.h> mit #include eingebunden werden.
b) Schreiben Sie eine Funktion printdatum(), die mit Hilfe des Befehls system("date")
das aktuelle Datum mit Uhrzeit auf dem Bildschirm ausgibt! 2
c) Schreiben Sie eine Funktion printbs(), die mit Hilfe des Befehls system("uname -a")
die aktuelle Betriebssystemversion auf dem Bildschirm ausgibt!3
d) Schreiben Sie eine Funktion printnutzer(), die mit Hilfe des Befehls system("who")
die Namen der momentan eingeloggten Nutzer auf dem Bildschirm ausgibt!4
e) Schreiben Sie eine Funktion printproz(), die mit Hilfe des Befehls system("ps -a")
die Informationen zu den aktuellen Prozessen auf dem Bildschirm ausgibt!5
f) Schreiben Sie eine Funktion printplatz(), die mit Hilfe des Befehls system("df") die
den momentan verfügbaren Massenspeicherplatz auf dem Bildschirm ausgibt!6
g) Das Hauptprogramm (also die Funktion main()) soll die oben genannten Funktionen nacheinander
ausführen (das Löschen des Bildschirm natürlich zuerst), eine Sekunde warten (mit
sleep(1)) und dann wieder von vorne anfangen.
h) Binden Sie alle genannten Funktionen zu einem lauähigen Programm zusammen!
*/




//Includes
#include <stdio.h>
#include <stdlib.h>




void clear ()
{
    //system ("clear");
    system ("cls");
    return;
}

void printdatum ()
{
    //system ("date");
    system ("time");
}

void printbs ()
{
   // system ("uname -a");
   system ("ver");
}

void printnutzer ()
{
    //system ("who");
}

void printproz ()
{
    //system ("ps -a");
}

void printplatz ()
{
   // system ("df");
   system ("chkdsk");
}



// M   A   I   N
int main (void)
{
    clear();
    printdatum();
    printbs();
    printnutzer();
    printproz();
    printplatz();
    return 0;
}