//b)
struct abredat
{
    char name[30];
    char vName[30];
    int plz;
    char wohnort[50];
    char straße[50];
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