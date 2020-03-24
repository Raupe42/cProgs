Willkommen zum Pruefungstrainer

Dieses Porgramm erfuellt die Anforderungen, wie diese in C72A vereinbart worden sind. Saemtliche Einzelschritte der Ergebnisfindung sind in den Ordnern
mit den entsprechenden Buchstaben A bis G abgelegt. Hinweis: Auch zusaetzliche Dokumentation wie Diagramme sind in den entsprechenden Unterordnern.

Funktionsumfang:
- Wie in C72A beschrieben
- Ein Debug-Bereich ist ausserdem erreichbar
- Einstellungen zum Verhalten des Programmes koennen ueber
    Precompiler-Directiven beeinflusst werden.

#define MAX_ANZAHL 200
#define RICHTIGE_ANTWORT "Richtige Antwort"
#define FALSCHE_ANTWORT "Nicht ganz Richtig"    //<Text>: Loesung
#define DATEINAME "Fragen2.txt"  //zur Eingabe des Dateinamens zur Laufzeit: Zeile auskommentieren

Hier ist es moeglich die Teste bei richtigen und auch bei falschen Antworten anzupassen.
Weiterhin kann hier entweder die Datei definiert werden, welche standardmaessig gelden werden soll
Oder wenn die Zeile mit DATEINAME auskommentiert (mit //) wird, so wird der Dateiname beim Laden erfragt. 
Hierbei ist es wichtig, dass die Dateiendung mit angegben wird. (Erinnerung: Im Unix-Umfeld ist die Gross- und Kleinschreibung auch bei der Endung relevant)#


Zum Uebersetzen des Programmes einfach die pruefungstrainer.c mit dem gcc aufrufen
z.B. gcc pruefungstrainer.c

Ueber das Systemumfeld wird die jeweilige Alternative fuer Unix oder Windows erzeugt und kann anschliessend aufgerufen werden.

Die Programme p1.c und p2.c sind Hilfsprogramme, wie diese in C72Ag gefordert werden. Dabei ist das p1.c exakt wie in der Vorlage.
Das p2.c hat die gleiche Funktionsweise, nur wird zufaelig +,*,-,/ ausgewaehlt. (Bei / ist das Ergebnis auf Ganzzahlen zu runden. z.B. 7/3=2)

Wie immer liegt die Software auch Verfuegbar unter GitHub:
https://github.com/Raupe42/cProgs/tree/master/viertesJahr/C72A

Verwendete Software:
Coding: Visual Studio Code (Microsoft)
Compiler Windows: gcc des MinGW-Package fuer Windows
Compiler Unix: gcc
Laufzeittest Windows: Windows 10 1909
Laufzeittest Unix: Unix Integrated in Windows via WSL (Add-In fuer VS-Code)
Struktogramm: Struktogrammeditor (Java Quelle von: https://whiledo.de/index.php?p=struktogrammeditor)

Code und Algorithmik in Eigenarbeit erstellt: Jens Höcker (Git: Raupe42)