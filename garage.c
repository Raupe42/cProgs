/*
author: Raupe
Aufgabe:
Fur den Neubau einer Garage (6m x 2,5m x 2,5m, Wanddicke 0,1 m) sollen ¨ uberschl ¨ ¨agig (keine
Fenster, keine Turen) die folgenden Gr ¨ ¨oßen ermittelt werden:
a) umbauter Raum (=Volumen),
b) Volumen von Boden, W¨anden und Decke (zusammengerechnet),
c) Baumasse (berechne_masse(v,rho) nach der Formel m = ρV mit der Massendichte
ρ ≈ 2400 kg
m3 ),
d) ben¨otigte Menge Wandfarbe (Schichtdicke d = 0, 5 mm) in Litern,
e) Dachkantenl¨ange fur die Blitzschutzeinrichtung. ¨
Dabei sollen zuerst folgende Funktionen erstellt werden:
• berechne_quadervolumen() nutzt die Formel V = Agh (Ag ist die Grundfl¨ache, h die
H¨ohe, V das Volumen)
• berechne_quaderoberflaeche() nutzt die Formel Ao = 2A1 + 2A2 + 2A3 (A1, A2 und
A3 sind die Fl¨achen links, vorne und oben)
Dazu k¨onnen vorher auch diese Funktionen erstellt werden:
• berechne_rechteckflaeche(s1,s2) mit der Formel: A = s1s2 (die Fl¨ache ist A, die
Seiten s1 und s2)
• berechne_rechteckkantenlaenge(s1,s2) mit der Formel: sk = 2s1 + 2s2 (die Kantenl¨ange
ist sk, die Seitenl¨angen s1 und s2)

*/

//includes
#include <stdio.h>
#include <math.h>

//prototypes
double berechne_quadervolumen (double h,double Agrund);
double berechne_quaderoberflaeche (double A1,double A2,double A3);
double berechne_rechteckflaeche (double s1,double s2);
double berechne_masse (double v, double rho);
double berechne_rechteckkantenlaenge (double s1,double s2);


//main
int main (void)
{
    //Garage
    double h = 2.5;
    double l = 2.5;
    double b = 6.0;
    double wand = 0.1;

    double Volumen = berechne_quadervolumen(h, berechne_rechteckflaeche(l,b));
    double Oberflaeche = berechne_quaderoberflaeche(berechne_rechteckflaeche(h,l),berechne_rechteckflaeche(h,b),berechne_rechteckflaeche(l,b));
    double Volumen_Material =  berechne_quadervolumen(wand, Oberflaeche);
    double Baumasse = berechne_masse (Volumen_Material, 2400.0);
    double Farbmenge = Oberflaeche *5e-1;
   //a
    printf ("Volumen: %g\n", Volumen); 
    //b
    printf ("Voulmen Material: %g\n", Volumen_Material);
    //c
    printf ("Baumasse: %g\n", Baumasse);
    //d
    printf ("Oberflaeche: %gm*m\n", Oberflaeche);
    printf ("Benoetigte Farbe: %gl\n", Farbmenge);
    //e 
    printf ("Blitzableiter: %gm\n", berechne_rechteckkantenlaenge (l,b));
}

double berechne_rechteckflaeche (double s1,double s2)
{
    double A = 0;
    A = s1 * s2;
    return A;
}

double berechne_rechteckkantenlaenge (double s1,double s2)
{
    double sk = 0;
    sk = 2 * s1 + 2 * s2;
    return sk;
}

double berechne_quadervolumen (double h,double Agrund)
{
    double V = 0;
    V = h * Agrund;
    return V;
}

double berechne_masse (double v,double rho)
{
    double m = 0;
    m = rho * v;
    return m;
}

double berechne_quaderoberflaeche (double A1, double A2, double A3)
{
    double A0 = 2 * A1 + 2 * A2 + 2 * A3;
    return A0;
}

