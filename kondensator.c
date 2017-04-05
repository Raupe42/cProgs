#include <stdio.h>
#include <math.h>

//defines
#define _USE_MATH_DEFINES 
// task
/*
    3 Entladen eines Kondensators uber einen Widerstand ¨
(c_entladen.c)
Mit Hilfe eines Programms soll herausgefunden werden, wie lange es dauert, bis ein Kondensator
(C = 100 µF), der an einer Betriebsspannung von U0 = 350 V liegt, uber einen Widerstand ¨
(R = 100 kΩ) entladen werden muss, bis die Kondensatorspannung auf einen ungef¨ahrlichen Wert
von Uu = 24 V abgesunken ist.
Formel: Uc = U0 · e^(−t/τ)  mit τ = R · C
Hinweise zum programmtechnischen L¨osungsweg (Algorithmus):
• Bei t = 0 anfangen
• Uc fur ¨ t ausrechnen und ausgeben
• t um tx erhöhen (z.B. um tx = 1 s)
• Testen, ob Uc = 24 V erreicht wurden
• Falls nicht, weitermachen
*/


int main (void)
{
    //VarDec
    double C, R, Uc, U0, Uu, t, tx;
    //VarInit
    C = 100e-6;
    R = 100e3;
    U0 = 350.;
    Uc = 0.;
    Uu = 24.;
    t = 0.;

    tx = 1.;    //Zeitraster

    //Intro + Input
    Uc = U0;

    //Calc 
    while (Uc > Uu)
    {   
        printf ("Uc = %gV nach %g Sekunden\n", Uc, t);
        //Uc = U0 * M_E ^ (-1.*t/(R*C));
        Uc = U0 * pow (M_E, (-1.*t/(R*C)));
        t = t + tx;
    }

    printf ("nach %g Sekunden auf sichere %gV\n", t, Uc);
}