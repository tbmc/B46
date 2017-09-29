#include "menu.h"
#include "fichiers.h"
#include "liste_chainees.h"
#include <stdlib.h>
#include <stdio.h>
#include "arbres.h"

#define ARRAY_SIZE (5000)

void clear_screen()
{
#ifdef _WIN32
    system("cls");
#endif
#ifdef linux
    system("clear");
#endif
}

void* liste_inserer(void *liste, TYPE type)
{
    int annee;
    char title[ARRAY_SIZE], realisateur[ARRAY_SIZE], resume[ARRAY_SIZE];
    printf("Veuillez entrer le titre, l'annee, le realisateur et le resume (separes par un retour a la ligne).\n");
    scanf("%s %d %s %s", title, &annee, realisateur, resume);
    printf("\n");

    if(type == LISTE)
        liste = ListeChainee_inserer(liste, ListeChainee_Cinematheque_creer(title, annee, realisateur, resume));
    else if(type == ARBRE)
        liste = Arbre_inserer(liste, title, annee, realisateur, resume);
    else if(type == TABLE)
        liste = Table_inserer(liste, title, annee, realisateur, resume);

    return liste;
}

void* liste_remove(void *liste, TYPE type)
{
    char title[ARRAY_SIZE];
    printf("Entrer le titre du film a supprimer : ");
    scanf("%s", title);
    printf("\n\n");
    void *out;
    if(type == LISTE)
        out = ListeChainee_supprimer(liste, title);
    else if(type == ARBRE)
        out = Arbre_supprimer(liste, title);
    else if(type == TABLE)
        out  = Table_supprimer(liste, title);

    return out;
}

void liste_search(void *liste, TYPE type, int choice)
{
    char str[ARRAY_SIZE];
    if(choice == 1)
        printf("Entrer le titre du film a rechercher : ");
    else
        printf("Entrer le realisateurs des films a rechercher : ");
    scanf("%s", str);
    printf("\n\n");
    void *out;

    switch(type)
    {
    case LISTE:
        if(choice == 1)
            out = ListeChainee_rechercher_titre(liste, str);
        else
            out = ListeChainee_rechercher_realisateur(liste, str);
        break;
    case ARBRE:
        if(choice == 1)
            out = Arbre_rechercher_titre(liste, str);
        else
            out = Arbre_rechercher_realisateur(liste, str);
        break;
    case TABLE:
        if(choice == 1)
            out = Table_rechercher_titre(liste, str);
        else
            out = Table_rechercher_realisateur(liste, str);
        break;
    }
    if(out == NULL)
    {
        printf("Aucun film n'a ete trouve.\n");
    }
    else
    {
        if(type == LISTE)
        {
            ListeChainees_print(out);
            ListeChainee_detruire(out);
        }
        else if(type == ARBRE)
        {
            Arbre_print(out);
            Arbre_detruire(out);
        }
        else if(type == TABLE)
        {
            Table_print(out);
            Table_free(out);
        }
    }
    printf("\n");
}

void menu_second(TYPE type)
{
    int choix;
    void *liste = fichier(NULL, "B46_imdb.dat", type);

    do
    {
        printf("1-Inserer un nouveau film.\n");
        printf("2-Supprimer un film.\n");
        printf("3-Rechercher un film par titre.\n");
        printf("4-Rechercher un film par realisateur.\n");
        printf("0-Retour en arriere.\n\n");
        printf("Choix : ");
        scanf("%d", &choix);
        printf("\n\n");

        if(choix == 1)
            liste = liste_inserer(liste, type);
        else if(choix == 2)
            liste = liste_remove(liste, type);
        else if(choix == 3)
            liste_search(liste, type, 1);
        else if(choix == 4)
            liste_search(liste, type, 0);

    }
    while(choix != 0);

    if(type == LISTE)
        ListeChainee_detruire(liste);
    else if(type == ARBRE)
        Arbre_detruire(liste);
    else if(type == TABLE)
        Table_free(liste);
}

void menu()
{


    int choix;

    do
    {
        clear_screen();
        printf("---------------------BIENVENUE A LA CINEMATHEQUE !---------------------\n\n\n\n\n");
        printf("Nous proposons diverses sections qui pourraient vous interesser, a savoir:\n\n");
        printf("1-Presentation de la cinematheque sous forme d'une liste chainee \n");
        printf("2-Presentation de la cinematheque sous forme d'un arbre binaire de recherche\n");
        printf("3-Presentation de la cinematheque a l'aide d'une table de hachage\n");
        printf("0-Quitter!\n");
        scanf("%d", &choix);
        switch(choix)
        {
        case 1:
            printf("Listes chainees\n");
            menu_second(LISTE);
            break;
        case 2:
            printf("Arbres\n");
            menu_second(ARBRE);
            break;
        case 3:
            printf("Tables de hashages\n");
            menu_second(TABLE);
            break;
        }
    }
    while(choix != 0);

}

