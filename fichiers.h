#ifndef FICHIERS_H
#define FICHIERS_H

#include "liste_chainees.h"
#include "arbres.h"
#include "table_hash.h"

typedef enum {LISTE, ARBRE, TABLE} TYPE;

void* fichier(void* liste, const char *path, TYPE type);


#endif // FICHIERS_H
