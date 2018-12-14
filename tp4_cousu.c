#include <stdio.h>
#include <stdlib.h>
#include "tp4_cousu.h"
T_Noeud_C* cousu_creer_noeud(int valeur){
  T_Noeud_C* noeud_c = malloc(sizeof(T_Noeud_C));
  noeud_c->predeceseur = 1;
  noeud_c->suceseur = 1;
  noeud_c->gauche = NULL;
  noeud_c->droit = NULL;
  noeud_c->valeur = valeur;
  return noeud_c;
}
void cousu_prefixe(T_Arbre_C arbre){
  printf("Noeud --> %d  pred %d succ %d\n", arbre->valeur,arbre->predeceseur,arbre->suceseur );
  printf(" -----> FG : " );
  if(arbre->gauche == NULL ){printf("NULL ");}
  else{printf("%d  ",arbre->gauche->valeur);}
  printf(" -- FD : ");
  if( arbre->droit == NULL){  printf("NULL \n"); }
  else{printf("%d  \n",arbre->droit->valeur);}
  if(arbre->gauche != NULL){ cousu_prefixe(arbre->gauche);}
  if(arbre->droit != NULL){ cousu_prefixe(arbre->droit);}
}
void cousu_inserer(int valeur,T_Arbre_C *arbre){

  T_Noeud_C* y = NULL;
  T_Noeud_C* x = *arbre;
  while(x!= NULL){
    y = x;
    printf("primer %d %d %d\n",x->valeur,x->suceseur,x->predeceseur );

    if(valeur < x->valeur){

      printf("entre %d %d %d\n",x->valeur,x->suceseur,x->predeceseur );
      x = x->gauche;
    }
    else{

      printf("entre %d %d %d\n",x->valeur,x->suceseur,x->predeceseur );

     x = x->droit;

    }
  }
    T_Noeud_C* noeud = cousu_creer_noeud(valeur);
    if(y == NULL){

      *arbre = noeud;

    }
    else if(valeur < y ->valeur){


    //  noeud->droit = y;
      noeud->gauche = y->gauche;
      y ->predeceseur= 0;
      y->gauche = noeud;


    }
    else{

      //noeud ->gauche = y;
      noeud->droit = y->droit;
       y ->suceseur = 0;
      y->droit = noeud;
    }

}
T_Noeud_C* trouver_gauche(T_Arbre_C *arbre){
  T_Noeud_C* plus_gauche = *arbre;
  while(plus_gauche->gauche != NULL){

    plus_gauche = plus_gauche->gauche;

  }
  return plus_gauche;
}
void cousu_infixe(T_Arbre_C *arbre){
  printf("PARCOURS INFIXE : _____________\n" );
  T_Noeud_C* courant = trouver_gauche(arbre);
  while(courant != NULL){

      printf("Noeud : %d \n", courant->valeur );
      if (courant->suceseur == 1){
        printf(" courant if %d \n", courant->valeur );
        courant = courant ->droit;
        printf(" courant if %d \n", courant->valeur );
      }
        else
            courant = trouver_gauche(&courant->droit);
            printf("courant    %d\n", courant->valeur );
  }
}

int main(int argc, char const *argv[]) {
  T_Arbre_C cousu = NULL;
  cousu_inserer(11,&cousu);
  cousu_inserer(2,&cousu);
  cousu_inserer(1,&cousu);
  cousu_inserer(6,&cousu);
  cousu_inserer(13,&cousu);
  cousu_inserer(17,&cousu);
  cousu_inserer(15,&cousu);
  cousu_inserer(4,&cousu);
  cousu_prefixe(cousu);
  cousu_infixe(&cousu);
  return 0;
}
