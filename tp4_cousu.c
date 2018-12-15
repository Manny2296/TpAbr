#include <stdio.h>
#include <stdlib.h>
#include "tp4_cousu.h"

T_Noeud_C* cousu_creer_noeud(int valeur)
{
  // ETAPE 1 : On alloue la mémoire et on vérifie que malloc a bien fonctionné
  T_Noeud_C* noeud_c = (T_Noeud_C*)malloc(sizeof(T_Noeud_C));
  if(noeud_c == NULL) return NULL;

  // ETAPE 2 : on initialise les valeurs du noeud
  noeud_c->predecesseur = 1;
  noeud_c->successeur = 1;
  noeud_c->gauche = NULL;
  noeud_c->droit = NULL;
  noeud_c->valeur = valeur;

  return noeud_c;
}

void cousu_prefixe(T_Arbre_C arbre){
 // Si l'arbre est nul, on s'arrête.
  if(arbre == NULL)
    return;

  // Affichage de la valeur du noeud
  printf("Noeud --> %d\n", arbre->valeur);

  // Affichage du fils gauche ou de NULL s'il n'existe pas
  printf("      --> FG(%d) : ", arbre->predecesseur);
  if(arbre->gauche == NULL)
    printf("NULL ");
  else
    printf("%d ",arbre->gauche->valeur);

  // Affichage du fils droit ou de NULL s'il n'existe pas
  printf(" -- FD(%d) : ", arbre->successeur);
  if(arbre->droit == NULL)
    printf("NULL \n");
  else
    printf("%d\n",arbre->droit->valeur);

  // Appel récursif sur les neouds fils.
  if(arbre->predecesseur == 0) cousu_prefixe(arbre->gauche);
  if(arbre->successeur == 0) cousu_prefixe(arbre->droit);
}

void cousu_inserer(int valeur,T_Arbre_C *arbre){
  // Étape 1, on parcourt l'arbre pour se placer la où le noeud doit être ajouté
  T_Noeud_C* y = NULL;
  T_Noeud_C* x = *arbre;

  while(x!= NULL){
    y = x;
    if(valeur < x->valeur)
        if(x->predecesseur == 0)
            x = x->gauche;
        else
            x = NULL;
    else
        if(x->successeur == 0)
            x = x->droit;
        else
            x = NULL;
  }

  // Etape 2, on insere le noeud
  if(y == NULL) // s'il n'y a pas de pere alors on retourne le noeud.
    *arbre = cousu_creer_noeud(valeur);
  else if(valeur < y ->valeur) {// Sinon on l'ajoute à gauche ou à droite selon la valeur
    T_Noeud_C* tmp = y->gauche;
    y->gauche = cousu_creer_noeud(valeur);
    y->predecesseur = 0;
    y->gauche->gauche = tmp;
    y->gauche->droit = y;
  } else {
    T_Noeud_C* tmp = y->droit;
    y->droit = cousu_creer_noeud(valeur);
    y->successeur = 0;
    y->droit->droit = tmp;
    y->droit->gauche = y;
  }

}


void cousu_infixe(T_Arbre_C *arbre)
{

    // ETAPE 1 : on va chercher le noeud le plus a gauche.
    T_Noeud_C* noeud = *arbre;
    affichageInfixeDebut();
    while(noeud != NULL) {
        while (noeud != NULL && noeud->predecesseur == 0)
            noeud = noeud->gauche;

        if(noeud == NULL) // si pas de noeud dans l'arbre
            return ;
        affichageInfixeNombre(noeud->valeur);
        affichageInfixeMilieu();

        while(noeud->successeur == 1 && noeud->droit != NULL) {
            noeud = noeud->droit;
            affichageInfixeNombre(noeud->valeur);
            affichageInfixeMilieu();
        }
        noeud = noeud->droit;
    }
    affichageInfixeFin();
}

void abr_to_cousu(T_Arbre abr, T_Arbre_C *clone, T_Noeud* parent)
{
    // TODO
/*
    parent = abr;

    if(abr->gauche != NULL) { // si on a un fils gauche
        *clone = parent; // on copie la racine
        abr_clone(abr->gauche, clone, parent); // on recommence le traitement sur le fils gauche
    } else if(abr->droit != NULL) { // si on a un fils droit
        *clone = parent; // on copie la racine
        abr_clone(abr->droit, clone, parent); // on recommence le traitement sur le fils droit
    }

    *clone = parent;
*/
}

void detruire_arbre_cousu(T_Arbre_C *arbre)
{
    if(*arbre == NULL) return ;

    if((*arbre)->predecesseur == 0) detruire_arbre_cousu(&(*arbre)->gauche);
    if((*arbre)->successeur == 0) detruire_arbre_cousu(&(*arbre)->droit);

    free(*arbre);
}
