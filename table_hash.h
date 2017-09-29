#ifndef TABLE_HASH_H
#define TABLE_HASH_H


#include "liste_chainees.h"

typedef Cinematheque_Liste * Table;

typedef unsigned int uInt;

void Table_free(Table table);

Table Table_inserer(Table liste, char* title, int year, char* rea, char* resume);

Table Table_supprimer(Table t, char* clef);

Table Table_rechercher_titre(Table table, char* titre);

Table Table_rechercher_realisateur(Table table, char *rea);

void Table_print(Table table);






#endif // TABLE_HASH_H
