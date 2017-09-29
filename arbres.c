#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "arbres.h"

#define null NULL


Cinematheque_Arbre Arbre_noeud_droit(Cinematheque_Arbre arbre)
{
    if(arbre == null)
        return null;
    if(arbre->fd != null)
        return Arbre_noeud_droit(arbre->fd);
    return arbre;
}

Cinematheque_Arbre Arbre_parent_droit(Cinematheque_Arbre parent, Cinematheque_Arbre arbre)
{
    if(arbre == null)
        return null;
    if(arbre->fd != null)
        return Arbre_parent_droit(arbre, arbre->fd);
    return parent;
}

Cinematheque_Arbre Arbre_cpy(Cinematheque_Arbre a)
{
    return Arbre_nouveau_noeud(a->titre, a->anneeDeSortie, a->realisateur, a->resume);
}

Cinematheque_Arbre Arbre_rechercher_titre(Cinematheque_Arbre arbre, char *titre)
{
    Cinematheque_Arbre a, b;
    if(arbre == null)
        return null;
    if(strcmp(arbre->titre, titre) == 0)
        return Arbre_cpy(arbre);
    a = Arbre_rechercher_titre(arbre->fg, titre);
    b = Arbre_rechercher_titre(arbre->fd, titre);
    if(a == null && b == null)
        return null;
    return a == null ? b : a; // WHAAAAT ??
}

Cinematheque_Arbre Arbre_inserer_in_another(Cinematheque_Arbre dest, Cinematheque_Arbre src)
{
    if(src == NULL)
        return dest;
    dest = Arbre_inserer(dest, src->titre, src->anneeDeSortie, src->realisateur, src->resume);
    dest = Arbre_inserer_in_another(dest, src->fg);
    dest = Arbre_inserer_in_another(dest, src->fd);
    return dest;
}

Cinematheque_Arbre Arbre_rechercher_realisateur(Cinematheque_Arbre arbre, const char* rea)
{
    Cinematheque_Arbre a, b;
    if(arbre == null)
        return null;
    a = Arbre_rechercher_realisateur(arbre->fg, rea);
    b = Arbre_rechercher_realisateur(arbre->fd, rea);
    Cinematheque_Arbre out = NULL;
    if(strcmp(arbre->realisateur, rea) == 0) // on compare le titre avec le realisateur?!
    {
        out = Arbre_cpy(arbre);
    }
    out = Arbre_inserer_in_another(out, a);
    out = Arbre_inserer_in_another(out, b);
    return out;
}


Cinematheque_Arbre Arbre_nouveau_noeud(const char* titre, int year, const char* rea, const char* def)
{
    Cinematheque_Arbre a = malloc(sizeof(struct Cinematheque_Arbre));

    a->titre = malloc(strlen(titre) + 1);
    a->realisateur = malloc(strlen(rea) + 1);
    a->resume = malloc(strlen(def) + 1);

    a->fg = null;
    a->fd = null;
    strcpy(a->titre, titre);
    strcpy(a->resume, def);
    a->anneeDeSortie = year;
    strcpy(a->realisateur, rea);
    return a;
}


void Arbre_free_noeud(Cinematheque_Arbre arbre)
{
    if(arbre == null)
        return;
    arbre->fg = null;
    arbre->fd = null;

    free(arbre->titre);
    free(arbre->resume);
    free(arbre->realisateur);
    free(arbre);
}


void Arbre_detruire(Cinematheque_Arbre a)
{
    if(a == null)
        return;
    free(a->titre);
    free(a->resume);
    free(a->realisateur);
    Arbre_detruire(a->fd);
    Arbre_detruire(a->fg);
    free(a);
}

Cinematheque_Arbre Arbre_inserer(Cinematheque_Arbre liste, char* titre, int year, char* rea, char* def)
{
    int cmp = 5;
    if(liste == null)
    {
        Cinematheque_Arbre re = Arbre_nouveau_noeud(titre, year, rea, def);
        return re;
    }
    cmp = strcmp(liste->titre, titre);
    if(cmp == 0)
        return null;
    if(cmp > 0)
    {
        if(liste->fg == null)
        {
            liste->fg = Arbre_nouveau_noeud(titre, year, rea, def);
        }
        else
        {
            Arbre_inserer(liste->fg, titre, year, rea, def);
        }
    }
    else
    {
        if(liste->fd == null)
        {
            liste->fd = Arbre_nouveau_noeud(titre, year, rea, def);
        }
        else
        {
            Arbre_inserer(liste->fd, titre, year, rea, def);
        }
    }
    return liste;
}

Cinematheque_Arbre Arbre_supprimer(Cinematheque_Arbre arbre, char* titre)
{
    Cinematheque_Arbre temp, fils_droite, parent;
    if(arbre == null)
        return null;
    if(strcmp(arbre->titre, titre) == 0)
    {
        if(arbre->fd == null)
        {
            temp = arbre->fg;
            Arbre_free_noeud(arbre);
            return temp;
        }
        else if(arbre->fg == null)
        {
            temp = arbre->fd;
            Arbre_free_noeud(arbre);
            return temp;
        }
        else
        {
            parent = Arbre_parent_droit(arbre, arbre->fg);
            fils_droite = parent->fd;
            if(fils_droite == arbre->fg)
            {
                fils_droite->fd = arbre->fd;
                Arbre_free_noeud(arbre);
                return fils_droite;
            }
            else
            {
                parent->fd = fils_droite->fg;
                fils_droite->fg = arbre->fg;
                fils_droite->fd = arbre->fd;

                Arbre_free_noeud(arbre);
                return fils_droite;
            }
        }
        return temp;
    }
    arbre->fg = Arbre_supprimer(arbre->fg, titre);
    arbre->fd = Arbre_supprimer(arbre->fd, titre);
    return arbre;
}

void Arbre_print(Cinematheque_Arbre arbre)
{
    if(arbre == NULL)
        return;
    printf("%s ; %d ; %s ; %s\n\n", arbre->titre, arbre->anneeDeSortie, arbre->realisateur, arbre->resume);
    Arbre_print(arbre->fg);
    Arbre_print(arbre->fd);
}


























