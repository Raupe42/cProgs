#define MAX_ANZAHL 200

char fragefeld [MAX_ANZAHL] [2] [81];


            ________________
            |   fragefeld  |
            |______________|
                    |
             _______|___________
            |   Listenelement * |       //erste Dimension
            |___________________|
         ___________|_____________
        |                         |
     ___|_____              ______|______
    |  Frage  |            |   Antowort  |      //zweite Dimension 
    |_________|            |_____________|      //Frage bei [0] und Antwort bei [1]
        |                         |
     ___|________           ______|______
    |  Zeichen * |         |  Zeichen *  |      //dritte Dimension -  Da String kein elementarer Datentyp ist
    |____________|         |_____________|      //sollte diese Dimension vorhanden sein. 




    O D E R

     _______________
    |   fragefeld   |
    |_______________|
            |
     _______|_______
    |            *  |      //erste Dimension
    |_______________|
            |
     _______|_______
    |            *  |      //zweite Dimension
    |_______________|
            |
     _______|_______
    |   char    *   |      //String
    |_______________|


/*
Wie bereits im letzten Präsenzunterricht thematisiert gibt es eine Definitionslücke
des Jackson-Diagramms bei mehrdimensionalen Arrays. 
Aufgrund dieser Definitionslücke ist das Obere Diagramm sowohl fuer die gewaehlte Definition aber 
auch fuer die Definition als struct fragen {char frage [80]; char antwort [80];} in einem [200] gueltig.

Nach meiner Ansicht stellt die untere Variante allerdings dieses eigentlich linaere dreidimensionale Array of Char
deutlicher dar. 

Das Jackson-Diagramm ist spracheneutral. Daher ist nicht klar, wie mit Datentypen zu verfahren ist, die nicht in allen Sprachen
elementar sind. Dies gilt insbesondere fuer Strings - also Zeichenketten. In C sind diese nur ueber Header-Dateien so benannt
und eigentlich nur ein einfaches Array of Char. Daher wird diese Aufloesung hier einzeln als tiefste Ebene (vgl. Baum -> Blatt)
betrachtet.
*/