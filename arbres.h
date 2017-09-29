#ifndef ARBRES_H
#define ARBRES_H

struct Cinematheque_Arbre
{
    char* titre;
    int anneeDeSortie;
    char* realisateur;
    char* resume;

    struct Cinematheque_Arbre *fg;
    struct Cinematheque_Arbre *fd;
};


typedef struct Cinematheque_Arbre * Cinematheque_Arbre;

void Arbre_detruire(Cinematheque_Arbre a);

Cinematheque_Arbre Arbre_nouveau_noeud(const char *title, int year, const char *rea, const char *def);

Cinematheque_Arbre Arbre_inserer(Cinematheque_Arbre liste, char* title, int year, char *rea, char* def);

Cinematheque_Arbre Arbre_rechercher_titre(Cinematheque_Arbre arbre, char *title);

Cinematheque_Arbre Arbre_rechercher_realisateur(Cinematheque_Arbre racine, const char* rea);

Cinematheque_Arbre Arbre_supprimer(Cinematheque_Arbre arbre, char* titre);

void Arbre_print(Cinematheque_Arbre arbre);

#endif // ARBRES_H
