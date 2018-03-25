/*
author: Tim, Jens

Task: Erfüllung des Pflichtenhefts gemäß der Dokumentation.
Dieses Programm stellt das Prdukt als vereinbarte Grundversion dar.

*/

// Defines
#define MAXINPUT 99
#define WORTLEN 30
#define VARIANTEN 8

#define xstr(x) #x		//eine Konstante x direkt eintragen
#define str(x) xstr(x)	//use: str(x)  -> result: x

//VS-CE ONLY:
#define _CRT_SECURE_NO_WARNINGS
//End Defines

//Includes
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//End Includes

//Proto
int aufteilen(char *zk, char *w1, char *w2, char *w3, char *w4);
int farbringe2Ziffer(char *farbwort);
double farbring2Multi(char *farbwort);
double farbring2Tolleranz(char *farbwort);

//char * defineVglArr ();
void defineVglArr(char vglArr[][VARIANTEN][20]);
void cpyArrOfStr(char dest[][20], char source[][20]);
//void cpyArrOfStr (char dest [] [], char source [] []);
//End Proto

int main(void)
{
	//lokale Datenfelder
	char inputStr[MAXINPUT + 1];
	int i;
	/* char w1 [WortLen];
	char w2 [WortLen];
	char w3 [WortLen];
	char w4 [WortLen];
	*/
	char worte[4][WORTLEN];
	//End lokale Datenfelder

	//Begruessung und Arbeitsauftrag fuer den Benutzer
	printf("Gib die bloeden Ringe ein!!!\n");

	scanf("%" str(MAXINPUT) "[^\n]", inputStr);
	//scanf ("%99[^\n]", inputStr);
	//scanf("%s", inputStr);
	//Aufruf der Subroutinen
	aufteilen(inputStr, worte[0], worte[1], worte[2], worte[3]);

	for (i = 0; i < 4; i++)
	{
		printf("%s: ", worte[i]);
		int ret = 5;
		//farbringe2Ziffer(worte[i]);
		//printf("%i", ret);
		printf("%i\n", farbringe2Ziffer(worte[i]));
	}
	//Ausgabe an den Benutzer

}

int aufteilen(char *zk, char *w1, char *w2, char *w3, char *w4)
{
	
	strcpy (w1, strtok(zk, "-"));   //nicht - ist Fehler
	strcpy (w2, strtok(NULL, "-"));
	strcpy (w3, strtok(NULL, "-"));
	strcpy (w4, strtok(NULL, "-"));

	//reste Verwerten

	return 0;
}
int farbringe2Ziffer(char *farbwort)
{
	char vgl[12][VARIANTEN][20];
	defineVglArr(vgl);
	//char vgl [12] [VARIANTEN] [20];
	int farbe, var, retValInt = -1;
	char retValStr[20];

	for (farbe = 0; farbe < 12; farbe++)
	{
		for (var = 1; var < VARIANTEN; var++)
		{

			//suchen durch vergleichen
			if ((strcmp(vgl[farbe][var], farbwort)) == 0)
			{
				strcpy(retValStr, vgl[farbe][0]);
				char c = retValStr[0];
				retValInt = (c - '0');
				return retValInt;
			}
			//wenn etwas gefunden wurde
			// aktuelle zeile feld 0 -> ergebenis


		}
	}
	printf("text\n");
	return -1;
}
double farbring2Multi(char *farbwort)
{

}
double farbring2Tolleranz(char *farbwort)
{

}

void defineVglArr(char vglArr[][VARIANTEN][20])
{
	//static char vglArr [12] [VARIANTEN] [20];
	//static char * ptr = &vglArr;
	char sw[VARIANTEN][20] = { "0", "schwarz", "sw", "black", "bk" };
	char br[VARIANTEN][20] = { "1", "braun", "br", "brown", "bn" };
	char rt[VARIANTEN][20] = { "2", "rot", "rt", "red", "rd" };
	char or [VARIANTEN][20] = { "3", "orange", "or", "og" };
	char ge[VARIANTEN][20] = { "4", "gelb", "ge", "yellow", "ye" };
	char gn[VARIANTEN][20] = { "5", "grue", "gn", "green" };
	char bl[VARIANTEN][20] = { "6", "blau", "bl", "blue", "bu" };
	char vi[VARIANTEN][20] = { "7", "violett", "vi", "voilet", "vt", "lila", "vio" };
	char gr[VARIANTEN][20] = { "8", "grau", "gr", "grey", "gy" };
	char ws[VARIANTEN][20] = { "9", "weiss", "ws", "white", "wh", "weis" };
	char au[VARIANTEN][20] = { "A", "gold", "au", "go", "gd" };
	char ag[VARIANTEN][20] = { "B", "silber", "si", "silver", "sr", "ag" };
	cpyArrOfStr(vglArr[0], sw);
	cpyArrOfStr(vglArr[1], br);
	cpyArrOfStr(vglArr[2], rt);
	cpyArrOfStr(vglArr[3], or );
	cpyArrOfStr(vglArr[4], ge);
	cpyArrOfStr(vglArr[5], gn);
	cpyArrOfStr(vglArr[6], bl);
	cpyArrOfStr(vglArr[7], vi);
	cpyArrOfStr(vglArr[8], gr);
	cpyArrOfStr(vglArr[9], ws);
	cpyArrOfStr(vglArr[10], au);
	cpyArrOfStr(vglArr[11], ag);



	return;

}


void cpyArrOfStr(char dest[][20], char source[][20])
{
	int i;
	for (i = 0; i < VARIANTEN; i++)
	{
		strcpy(dest[i], source[i]);
	}
}

