/*
author: Raupe

task:

*/

//defines
//END_defines

//includes
#include <stdio.h>
//END_includes

//structs
struct film_t {
    char filmtitel [81];
    unsigned short filmdauer;
    unsigned int releaseJahr;
};
//END_structs

//prototypes
void printfilm(struct film_t);
struct film_t scanfilm(void);
void aktjahr(struct film_t *pfilm, unsigned int jahr);
//END_prototypes

/*no global variables*/

int main (void)
{
    struct film_t film;
    film = scanfilm();
    printfilm(film);
    aktjahr(&film, 2019);
    printfilm(film);
    return 0;
}

void printfilm (struct film_t film)
{
     printf("Titel: %s\n", film.filmtitel);
    printf("Filmdauer: %us\n", film.filmdauer);
    printf("Erscehinungsjahr: %ui\n", film.releaseJahr);
    return;
}

struct film_t scanfilm (void)
{
    struct film_t film;
    printf("Titel:");
    scanf("%80s", film.filmtitel);
    printf("Filmdauer:");
    scanf("%us", &film.filmdauer);
    printf("Erscheinungsjahr:");
    scanf("%ui", &film.releaseJahr);
    return film;
}

void aktjahr(struct film_t *pfilm, unsigned int jahr)
{
    pfilm->releaseJahr = jahr;      //so sollte es aussehen, vgl C52L 5.2.3
    return;
}