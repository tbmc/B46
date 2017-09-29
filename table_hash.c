#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "table_hash.h"

#define HASH_TABLE_SIZE (50000)

uInt Table_hash(const char *str)
{
    int i, s = 0;
    int size_str = strlen(str);
    for(i = 0; i < size_str; i++)
        s += (unsigned char)str[i];
    return s % HASH_TABLE_SIZE;
}

Table Table_new()
{
    Table table = calloc(sizeof(Cinematheque_Liste), HASH_TABLE_SIZE);
    int i;
    for(i = 0; i < HASH_TABLE_SIZE; i++)
    {
        table[i] = NULL;
    }
    return table;
}



void Table_free(Table table)
{
    if(table == NULL)
        return;
    int i;
    for(i = 0; i < HASH_TABLE_SIZE; i++)
    {
        ListeChainee_detruire(table[i]);
    }
    free(table);
}

Table Table_inserer(Table liste, char* title, int year, char* rea, char* resume)
{
    uInt hash;

    if(title == null || resume == null)
        return liste;

    hash = Table_hash(title);

    if(liste == null)
    {
        liste = Table_new();
    }
    liste[hash] = ListeChainee_inserer(liste[hash], ListeChainee_Cinematheque_creer(title, year, rea, resume));
    return liste;
}

Table Table_supprimer(Table t, char* clef)
{
    Cinematheque_Liste sortie;
    uInt hash = Table_hash(clef);
    sortie = ListeChainee_supprimer(t[hash], clef);
    if(sortie == null)
        return null;
    t[hash] = sortie;
    return t;
}

Table Table_rechercher_titre(Table table, char* titre)
{
    uInt hash = Table_hash(titre);
    Cinematheque_Liste l = ListeChainee_rechercher_titre(table[hash], titre);
    if(l == NULL)
        return NULL;
    Table t = Table_new();
    t = Table_inserer(t, l->titre, l->anneeDeSortie, l->realisateur, l->resume);
    return t;
}

Table inserer_multiple(Table out, Cinematheque_Liste src)
{
    while(src != NULL)
    {
        out = Table_inserer(out, src->titre, src->anneeDeSortie, src->realisateur, src->resume);
        src = src->suivant;
    }
    return out;
}

Table Table_rechercher_realisateur(Table table, char *rea)
{
    int i;
    Table out = NULL;
    for(i = 0; i < HASH_TABLE_SIZE; i++)
    {
        Cinematheque_Liste ll = ListeChainee_rechercher_realisateur(table[i], rea);
        out = inserer_multiple(out, ll);
        ListeChainee_detruire(ll);
    }
    return out;
}


void Table_print(Table table)
{
    if(table == NULL)
        return;
    int i;
    for(i = 0; i < HASH_TABLE_SIZE; i++)
    {
        ListeChainees_print(table[i]);
    }
}






















