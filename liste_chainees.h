#ifndef LISTECHAINEES_H
#define LISTECHAINEES_H

#define null NULL
struct Cinematheque_Liste
{
    char* titre;
    int anneeDeSortie;
    char* realisateur;
    char* resume;
    struct Cinematheque_Liste * suivant;
};

typedef struct Cinematheque_Liste * Cinematheque_Liste;

Cinematheque_Liste ListeChainee_Cinematheque_creer(const char* title, int year, char *rea, const char* def);

void ListeChainee_detruire(Cinematheque_Liste liste);

Cinematheque_Liste ListeChainee_inserer(Cinematheque_Liste liste, Cinematheque_Liste add);

Cinematheque_Liste ListeChainee_supprimer(Cinematheque_Liste Cine, char*title);

Cinematheque_Liste ListeChainee_rechercher_titre(Cinematheque_Liste Cine, char*titre);

Cinematheque_Liste ListeChainee_rechercher_realisateur(Cinematheque_Liste cinematheque, char* rea);

void ListeChainees_print(Cinematheque_Liste c);














#endif // LISTECHAINEES_H
