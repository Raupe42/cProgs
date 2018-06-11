#include <stdio.h>


//b)
struct abredat
{
    char name[30];
    char vName[30];
    int plz;
    char wohnort[50];
    char strasse[50];
    char hausnummer[10];
};

//d)
union rechnungsT
{
    int KassenNummer;
    struct abredat daten;
};

struct patdat
{
    char name[30];
    char vName[30];
    int gebDat;
    char geschlecht[30];
    union rechnungsT data;
    short istKasse;
};


void printPatient(struct patdat pat);


int main (void)
{
    struct patdat patient1 = {"nach", "vor", 19700101, "neut", 123456, 1};
    struct patdat patient2 = {"Name", "Ein", 19420101, "neut", patient2.data.daten.plz = 888  , patient2.istKasse = 0};

    printPatient(patient1);
    printPatient(patient2);
}

void printPatient (struct patdat pat)
{
    printf("Vorname: %s\n", pat.vName);
    printf("Nachname: %s\n", pat.name);
    printf("Geburtstag: %i\n", pat.gebDat);
    if (pat.istKasse)
        printf("V Nr:: %i\n", pat.data.KassenNummer);
    else
    {
        printf("Patient PLZ: %i\n", pat.data.daten.plz);
    }
}