#include <stdio.h>
#include <stdlib.h>
#include "tp4_abr.h"
#include "affichage.h"
#include "tp4_cousu.h"


T_Noeud *abr_creer_noeud(int valeur) {

  // Étape 1 : allocation mémoire et vérification du fonctionnement de malloc
  T_Noeud* tn = (T_Noeud*)malloc(sizeof(T_Noeud));

  if(tn == NULL)
    return NULL;

  // Étape 2 : on donne la valeur au noeud et on précise qu'il n'a pas de fils.
  tn ->valeur = valeur;
  tn->droit = NULL;
  tn->gauche=NULL;

  return tn;

}

void abr_prefixe(T_Arbre abr)
{
  // Si l'arbre est nul, on s'arrête.
  if(abr == NULL)
    return;

  // Affichage de la valeur du noeud
  printf("Noeud --> %d\n", abr->valeur);

  // Affichage du fils gauche ou de NULL s'il n'existe pas
  printf("      --> FG : " );
  if(abr->gauche == NULL)
    printf("NULL ");
  else
    printf("%d ",abr->gauche->valeur);

  // Affichage du fils droit ou de NULL s'il n'existe pas
  printf(" -- FD : ");
  if(abr->droit == NULL)
    printf("NULL \n");
  else
    printf("%d\n",abr->droit->valeur);

  // Appel récursif sur les neouds fils.
  abr_prefixe(abr->gauche);
  abr_prefixe(abr->droit);

}

void abr_inserer(int valeur,T_Arbre *abr)
{
  // Étape 1, on parcourt l'arbre pour se placer la où le noeud doit être ajouté
  T_Noeud* y = NULL;
  T_Noeud* x = *abr;

  while(x!= NULL){
    y = x;
    if(valeur < x->valeur)
      x = x->gauche;
    else
      x = x->droit;
  }

  // Etape 2, on insere le noeud
  if(y == NULL) // s'il n'y a pas de pere alors on retourne le noeud.
    *abr = abr_creer_noeud(valeur);
  else if(valeur < y ->valeur) // Sinon on l'ajoute à gauche ou à droite selon la valeur
    y->gauche = abr_creer_noeud(valeur);
  else
    y->droit = abr_creer_noeud(valeur);

}

void abr_supprimer(int valeur,T_Arbre *abr)
{
    // ETAPE 1 : On recherche le noeud a supprimer, en gardant en memoire son pere
    T_Noeud* pere = NULL;
    T_Noeud* noeud = *abr;

    while(noeud != NULL && noeud->valeur != valeur)
    {
        pere = noeud;
        if(noeud->valeur < valeur) noeud = noeud->droit;
        else noeud = noeud->gauche;
    }

    if(noeud == NULL)
    {
        printf("Erreur : valeur introuvable !\n\n");
        return;
    }

    // ETAPE 2 : Supprimer le noeud et faire les adaptations nécessaires
    if(noeud->gauche == NULL && noeud->droit == NULL) // si pas de fils
    {
        // si le pere n'existe pas alors il n'y a plus d'arbre
        if(pere == NULL)
        {
            free(noeud);
            *abr = NULL;
            return;
        }

        // Si on doit supprimer le noeud de gauche
        if(pere->gauche != NULL && pere->gauche->valeur == valeur)
            pere->gauche = NULL;
        else // si on doit supprimer le noeud de droite
            pere->droit = NULL;

        free(noeud); // On libere la mémoire du noeud à supprimer
    }
    else if(noeud->droit != NULL && noeud->gauche != NULL) // si deux fils
    {
        // Etape 2.1 : On recherche le successeur (noeud le plus a gauche dans le sous arbre droit)
        T_Noeud* successeur = noeud->droit;
        T_Noeud* pereSuccesseur = noeud;
        while(successeur->gauche != NULL)
        {
            pereSuccesseur = successeur;
            successeur = successeur->gauche;
        }

        // Etape 2.2 : On inverse les deux cles.
        int tmp = noeud->valeur;
        noeud->valeur = successeur->valeur;
        successeur->valeur = tmp;

        // Etape 2.3 : in supprime l'ancien successeur comme etant un noeud a un fils.
        if(pereSuccesseur == noeud)
        {
            pereSuccesseur->droit = successeur->droit;
        }
        else
        {
            pereSuccesseur->gauche = successeur->droit;
        }
        free(successeur); // enfin on libere la memoire.
    }
    else { // si un seul fils
        T_Noeud* fils = NULL; // On commence par stocker le noeud du fils à supprimer
        if(noeud->gauche != NULL) fils = noeud->gauche;
        else fils = noeud->droit;

        // On lit ensuite le pere du noeud à supprimer à son fils
        if(pere != NULL && pere->gauche != NULL && pere->gauche->valeur == valeur) pere->gauche = fils;
        else if(pere != NULL) pere->droit = fils;
        else *abr = fils;
        free(noeud); // On libere la mémoire du noeud à supprimer
    }

    printf("                      Valeur supprimee !\n\n");

}

void abr_clone(T_Arbre original, T_Arbre* clone, T_Noeud* parent)
{
    if(parent == NULL)
    {
        if(original != NULL)
        {
            *clone = abr_creer_noeud(original->valeur);
            abr_clone(original, clone, *clone);
        }
        return ;
    }

    if(original->gauche != NULL)
    {
        parent->gauche = abr_creer_noeud(original->gauche->valeur);
        abr_clone(original->gauche, clone, parent->gauche);
    }

    if(original->droit != NULL)
    {
        parent->droit = abr_creer_noeud(original->droit->valeur);
        abr_clone(original->droit, clone, parent->droit);
    }

}

void detruire_arbre(T_Arbre *abr)
{
    if(*abr == NULL) return ;

    detruire_arbre(&(*abr)->gauche);
    detruire_arbre(&(*abr)->droit);

    free(*abr);
}
