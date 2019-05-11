/*
author: Raupe

Headerdatei des Widerstandsrechners

Basierend auf der der Vollversion des Widerstandsrechners aus C7.3
Bietet die Funktionen des Programms sowie einige defines 
die zur weietren Anpassung genutzt werden koennen
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

//Daten die nanpassbar sein sollen
#define MAXINPUT 99
#define MAXOUT 200
#define WORTLEN 30
#define VARIANTEN 8
#define TRENNZEICHEN "-,/ "


//Proto
int aufteilen(char *zk, char worte [] [WORTLEN], int wortmenge);
int farbringe2Ziffer(char *farbwort);
double farbring2Multi(char *farbwort);
double farbring2Tolleranz(char *farbwort);

//Zusaetzliche Funktionen
void fuelleVglArr(char vglArr[][VARIANTEN][20]);
void cpyArrOfStr(char dest[][20], char source[][20]);
int inputPruefen(char * input);
int ausgabe(char worte[][WORTLEN], int pruefung);

int ausgabeInStr(char worte[][WORTLEN], int pruefung, char *retStr, int ringe[6]);

char * eingabe(char inputStr[]);
void hilfeAnzeigen();
void farbenAnzeigen();
//End Proto

int main_Konsole(void);