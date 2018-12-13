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
  printf("Noeud --> %d  suc %d prec %d\n", arbre->valeur,arbre->suceseur,arbre->predeceseur );
  printf(" -----> FG : " );
  if(arbre->gauche == NULL){printf("NULL ");}
  else{printf("%d  suc %d prec %d ",arbre->gauche->valeur,arbre->suceseur,arbre->predeceseur);}
  printf(" -- FD : ");
  if( arbre->droit == NULL){  printf("NULL \n"); }
  else{printf("%d   suc %d prec %d \n",arbre->droit->valeur,arbre->suceseur,arbre->predeceseur);}
  if(arbre->gauche != NULL){ cousu_prefixe(arbre->gauche);}
  if(arbre->droit != NULL){ cousu_prefixe(arbre->droit);}
}
void cousu_inserer(int valeur,T_Arbre_C *arbre){
  T_Noeud_C* y = NULL;
  T_Noeud_C* x = *arbre;
  while(x!= NULL){
    y = x;
    if(valeur < x->valeur){
      x = x->gauche;
    }
    else{
      x = x->droit;
    }
  }

    if(y == NULL){

      *arbre = cousu_creer_noeud(valeur);

    }
    else if(valeur < y ->valeur){
      y->gauche = cousu_creer_noeud(valeur);
      y ->predeceseur= 0 ;
      //  y->predeceseur = 0;
      y->gauche->suceseur = y->suceseur;


// 1101




    }
    else{

      y->droit = cousu_creer_noeud(valeur);
       y ->suceseur = 0;


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
  return 0;
}
