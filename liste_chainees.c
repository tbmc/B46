#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "liste_chainees.h"

void ListeChainee_Cinematheque_free(Cinematheque_Liste d) // pour vider un noeud
{
    if(d == NULL)
        return;
    free(d->titre);
    free(d->realisateur);
    free(d->resume);
    free(d);
}



Cinematheque_Liste ListeChainee_Cinematheque_creer(const char* title, int year, char* rea, const char* def)
{
    Cinematheque_Liste d = malloc(sizeof(struct Cinematheque_Liste)); //Creation de la novelle structure

    if(title == NULL)
        return NULL;
    d->titre = (char*)malloc(strlen(title) + 1);
    if(d->titre == NULL)
    {
        printf("Erreur!\n");
        system("pause");
    }
    d->realisateur = (char*)malloc(strlen(rea) + 1);
    d->resume = (char*)malloc(strlen(def) + 1);

    strcpy(d->titre, title); //Copie pour donner nouveaux paramètre à la structures
    d->anneeDeSortie = year;
    strcpy(d->realisateur, rea);
    strcpy(d->resume, def);

    d->suivant = NULL;
    return d;
}

void ListeChainee_detruire(Cinematheque_Liste liste)
{
    Cinematheque_Liste temp = liste, suivant = NULL;
    while(temp != NULL)  //Tant que temp contient des caractère
    {
        free(temp->titre);     //free tout
        free(temp->realisateur);
        free(temp->resume);
        suivant = temp->suivant; //Il passse au film suivant une fois que le filme précédent a été détruit
        free(temp);
        temp = suivant;
    }
}

Cinematheque_Liste ListeChainee_inserer(Cinematheque_Liste liste, Cinematheque_Liste add) // EXPLICATION??
{
    if(liste == null) // si la liste existe pas, retourne le premier film
        return add;
    if(liste->titre == NULL || liste->resume == NULL) // si le film n'a pas de titre ou de resumé suppprime, et retourn add
    {
        ListeChainee_Cinematheque_free(liste);
        return add;
    }
    add->suivant = liste;
    return add;
}

Cinematheque_Liste ListeChainee_supprimer(Cinematheque_Liste liste, char* title)
{
    Cinematheque_Liste temp = liste, a = NULL, b = NULL;
    int v = 1;
    if(liste == NULL)
        return NULL;
    if(liste->suivant == NULL && strcmp(temp->titre, title) == 0)
    {
        ListeChainee_Cinematheque_free(liste);
        return NULL;
    }
    while(temp != NULL && v != 0)
    {
        v = strcmp(temp->titre, title);
        if(v == 0)
            break;
        b = a;
        a = temp;
        temp = temp->suivant;
    }
    if(v != 0)
    {
        return liste;
    }
    if(a == NULL)
    {
        b = temp->suivant;
        ListeChainee_Cinematheque_free(temp);
        return b;
    }
    a->suivant = temp->suivant;
    ListeChainee_Cinematheque_free(temp);

    return liste;
}

Cinematheque_Liste ListeChainee_rechercher_titre(Cinematheque_Liste cinematheque, char* titre)
{
    Cinematheque_Liste temp = cinematheque, a = NULL;
    int v = 1;
    if(cinematheque == NULL)
    {
        return NULL;
    }
    while(temp != NULL && v != 0)
    {
        v = strcmp(temp->titre, titre);
        if(v == 0)
            a = ListeChainee_inserer(a, ListeChainee_Cinematheque_creer(temp->titre,
                                temp->anneeDeSortie, temp->realisateur, temp->resume));
        temp = temp->suivant;
    }
    ;;;
    return a;

}
void ListeChainees_print(Cinematheque_Liste c)
{

    while(c != NULL)
    {
        printf("%s ; %d ; %s ; %s\n\n", c->titre, c->anneeDeSortie, c->realisateur, c->resume);
        c = c->suivant;
    }
}

Cinematheque_Liste ListeChainee_rechercher_realisateur(Cinematheque_Liste cinematheque, char* rea)
{
    Cinematheque_Liste t = cinematheque, a = NULL;
    int v = 1;
    if(cinematheque == NULL)
        return NULL;

    while(t != NULL)
    {
        v = strcmp(t->realisateur, rea);
        if(v == 0)
        {
            Cinematheque_Liste ll = ListeChainee_Cinematheque_creer(t->titre, t->anneeDeSortie,
                                                                    t->realisateur, t->resume);
            a = ListeChainee_inserer(a, ll);
        }

        t = t->suivant;

    }

    return a;
}

































