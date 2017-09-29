#include "fichiers.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAILLE_TEMP (50000)

void *fichier(void *liste, const char *path,  TYPE type)
{
    char temp[TAILLE_TEMP], *b;
    int length;
    FILE *fichier = NULL;
    fichier = fopen(path, "r");

    if(fichier == NULL)
        printf("Rate!\n");
    else
    {

        char *title, *year, *rea, *def, *temp2;
        //int dec = 0;
        while(!feof(fichier))
        {
            fgets(temp, TAILLE_TEMP, fichier);
            if(feof(fichier))
                break;
            temp2 = temp;
            //title = getInFile(temp2, &dec);
            b = strchr(temp2, '|');
            length = (int)(b - temp2);
            title = (char*)malloc((length + 1)*sizeof(char));
            memcpy(title, temp2, length);
            title[length] = '\0';
            temp2 += length + 1;

            b = strchr(temp2, '|');
            length = (int)(b - temp2);
            year = (char*)malloc((length + 1)*sizeof(char));
            memcpy(year, temp2, length);
            year[length] = '\0';
            temp2 += length + 1;

            b = strchr(temp2, '|');
            length = (int)(b - temp2);
            rea = (char*)malloc((length + 1)*sizeof(char));
            memcpy(rea, temp2, length);
            rea[length] = '\0';
            temp2 += length + 1;

            length = strlen(temp2);
            def = (char*)malloc(length + 1);
            memcpy(def, temp2, length);
            def[length] = '\0';

            if(type == LISTE)
                liste = ListeChainee_inserer(liste, ListeChainee_Cinematheque_creer(title, atoi(year), rea, def));
            else if(type == ARBRE)
            {
                liste = Arbre_inserer(liste, title, atoi(year), rea, def);
            }
            else if(type == TABLE)
                liste = Table_inserer(liste, title, atoi(year), rea, def);
        }
        fclose(fichier);
    }
    return liste;
}




















