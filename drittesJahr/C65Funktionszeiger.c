/*
Funktionszeiger
am Beispiel von Quicksort (fertig in C implementiert)
der 4. Parameter:
int (*compar) (const void*, const void *)

*/

int main (void)
{
    void (*clearfunk) (void);
    clearfunk = &clear; //OHNE ()       //& ist optional
    //so wird die Startadresse der Funktion übergeben

    (*clearfunk) (); // Aufruf der Funktion die zuvor zugewiesen wurde
    // (* ... ) ist optional 


}

int main2 (void)
{
    //Bevorzugte Schreibweise bei Funktionszeigern
    void (*clearfunk) ();   //hier zwingend erforderlich
                            //ohne Steuerzeichen wäre es ein Prototyp!!!
                            //die () um den Namen sind wegen d. Bindungsregeln erfroderlich

    clearfunk = clear;
    clearfunk();
}


void cls () //Windows
{
    system ("cls");
}

void clear ()   //unix
{
    system ("clear");
}