#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "tp4_abr.h"
#include "tp4_cousu.h"
#include "affichage.h"

void menu_principal()
{
    char choix[4];
    int i;
    T_Arbre abr = NULL, clone = NULL;
    T_Arbre_C abrc = NULL;

    do{
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("│                 Que souhaitez-vous faire ?                 │\n");
    printf("├─────────────────────────────┬──────────────────────────────┤\n");
    printf("│        P: Prefixe ABR       │       PC: Prefixe ABRC       │\n");
    printf("├─────────────────────────────┼──────────────────────────────┤\n");
    printf("│     A: Ajouter dans ABR     │    AC: Ajouter dans ABRC     │\n");
    printf("├─────────────────────────────┼──────────────────────────────┤\n");
    printf("│    S: Supprimer dans ABR    │       IC: Infixe ABRC        │\n");
    printf("├─────────────────────────────┼──────────────────────────────┤\n");
    printf("│        C: Cloner ABR        │    CA: Creer ABRC from ABR   │\n");
    printf("├─────────────────────────────┼──────────────────────────────┤\n");
    printf("│      VC: Voir Clone ABR     │          Q: Quitter          │\n");
    printf("└─────────────────────────────┴──────────────────────────────┘\n");

    scanf("%s", choix);
    for(i = 0 ; i < strlen(choix) ; i++) choix[i] = toupper(choix[i]);

    if(strcmp(choix, "P") == 0)
        abr_prefixe(abr);

    if(strcmp(choix, "PC") == 0)
        cousu_prefixe(abrc);

    if(strcmp(choix, "IC") == 0)
        cousu_infixe(&abrc);

    if(strcmp(choix, "Q") == 0)
    {
        detruire_arbre(&abr);
        detruire_arbre_cousu(&abrc);
    }

    if(strcmp(choix, "C") == 0)
        abr_clone(abr, &clone, NULL);

    if(strcmp(choix, "CA") == 0)
        abr_to_cousu(abr, &abrc, NULL);

    if(strcmp(choix, "VC") == 0)
        abr_prefixe(clone);

    if(strcmp(choix, "A") == 0)
    {
        int nb = 0;
        affichageAjout(&nb);
        abr_inserer(nb, &abr);
    }

    if(strcmp(choix, "AC") == 0)
    {
        int nb = 0;
        affichageAjout(&nb);
        cousu_inserer(nb, &abrc);
    }


    if(strcmp(choix, "S") == 0)
    {
        int nb = 0;
        affichageSupression(&nb);
        abr_supprimer(nb, &abr);
    }

    }while(strcmp(choix, "Q") != 0);
}

void affichageAjout(int* nb)
{
    printf("                      Inserer une valeur                      \n");
    printf(" ─────────────────────────────┬────────────────────────────── \n");
    printf("            Entier            │ ");
    scanf("%d", nb);
    printf("\n");
    printf("                       Valeur inseree !\n\n");
}

void affichageSupression(int* nb)
{
    printf("                      Valeur a supprimer                      \n");
    printf(" ─────────────────────────────┬────────────────────────────── \n");
    printf("            Entier            │ ");
    scanf("%d", nb);
    printf("\n");
}

void affichageInfixeDebut()
{
    printf("┌────────────────────────────────────────────────────────────┐\n");
}

void affichageInfixeFin()
{
    printf("└────────────────────────────────────────────────────────────┘\n\n");
}

void affichageInfixeMilieu()
{
    printf("├────────────────────────────────────────────────────────────┤\n");
}

void affichageInfixeNombre(int nb)
{
    int i = 0;

    printf("│");
    if(nb == 0) printf("                             0                              ");
    else
    {
        if(nb > 0) printf(" ");
        for(i = 0 ; i < (55-floor(log10(abs(nb)))+1)/2 ; i++) printf(" ");
        printf("%d", nb);
        for(i = 0 ; i < (58-floor(log10(abs(nb)))+1)/2 ; i++) printf(" ");
    }
    printf("│\n");
}
