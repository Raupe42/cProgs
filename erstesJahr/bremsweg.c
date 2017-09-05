/*
autor: Raupe

Aufgabe: C26A
2 Berechnung des Anhaltewegs
Der Anhalteweg eines Fahrzeugen mit der Geschwindigkeit v setzt sich aus dem Reaktionsweg
lR und dem Bremsweg lB zusammen. Sobald die Notwendigkeit zu bremsen erkannt ist, dauert
es noch eine Zeit, bis der Bremsvorgang beginnt. Diese Zeit heißt Reaktionszeit. W¨ahrend der
Reaktionszeit f¨ahrt das Fahrzeug ungebremst weiter; man erh¨alt fur den Reaktionsweg ¨ lR = v ·tR.
Fur den Bremsweg gilt die Formel ¨ lB = v
2/(2a). Bei Pkws geht man von tR ≈ 1 s und a ≈ 4, 5 m/s
2
aus.

Dabei fehlen noch die Funktion, die die Umrechnung der Geschwindigkeit von km/h nach m/s
vornimmt sowie die Funktionen zur Berechnung von Reaktions- und Bremsweg.
a) Erstellen Sie die Prototypen!
b) Erstellen Sie die genannten Funktionen dazu!
c) Testen Sie die Funktionen im Programm! Erfahrungsgem¨aß sind bei Pkws bei v = 30 km/h
Reaktions- und Bremsweg etwa gleich groß; bei h¨oheren Geschwindigkeiten uberwiegt der ¨
Bremsweg.


*/

//includes
#include <stdio.h>
//defines
#define a_NORMAL 4.5
#define t_REAKTION 1.0

/* a) */
double umrechnen_kmh_nach_ms (double vkmh);
double berechne_reaktionsweg (double vms, double a);
double berechne_bremsweg (double vms, double t_reak_s);

//Main
int main ( void)
 {
 double anhalteweg ; /* l_A in m */
 double bremsweg ; /* l_B in m */
 double reaktionsweg ; /* l_R in m */
 double vkmh ; /* v in km/h */
 double vms ; /* v in m/ s */
 printf ("Bitte Geschwindigkeit eingeben (in kh/h): ");
 scanf ( "%lf " , &vkmh ) ; while ( getchar ( ) != '\n') { }
 vms = umrechnen_kmh_nach_ms ( vkmh );
 reaktionsweg = berechne_reaktionsweg (vms, t_REAKTION);
 bremsweg = berechne_bremsweg ( vms , a_NORMAL) ;
 anhalteweg = reaktionsweg + bremsweg;
 printf ("Anhalteweg ...: %lf m\n",anhalteweg);
 printf ( " Reaktionsweg : %lf m\n" , reaktionsweg) ;
 printf ( "Bremsweg . . . . : %lf m\n" , bremsweg ) ;
 return 0 ;
 }

