#include <stdio.h>
#include <stdlib.h>
#include "structures.h"
T_Noeud *abr_creer_noeud(int valeur){
  T_Noeud* tn = (T_Noeud*)malloc(sizeof(T_Noeud));
  if(tn == NULL)
      return NULL;
  tn ->valeur = valeur;
  tn->droit = NULL;
  tn->gauche=NULL;
  return tn;
}
void abr_prefixe(T_Arbre abr){

  printf("Noeud --> %d\n", abr->valeur);
  printf(" -----> FG : " );
  if(abr->gauche == NULL){printf("NULL ");}
  else{printf("%d ",abr->gauche->valeur);}
  printf(" -- FD : ");
  if(abr->droit == NULL){  printf("NULL \n"); }
  else{printf("%d \n",abr->droit->valeur);}
  if(abr->gauche != NULL){ abr_prefixe(abr->gauche);}
  if(abr->droit != NULL){ abr_prefixe(abr->droit);}
}
void abr_inserer(int valeur,T_Arbre *abr){
  T_Noeud* y = NULL;
  T_Noeud* x = *abr;
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
      *abr = abr_creer_noeud(valeur);

    }
    else if(valeur < y ->valeur){
      y->gauche = abr_creer_noeud(valeur);
    }
    else{
      y->droit = abr_creer_noeud(valeur);
    }

}
void abr_supprimer(int valeur,T_Arbre *abr){
  T_Noeud* pere = NULL;
  T_Noeud* noeud_tmp = *abr;
  while(noeud_tmp != NULL && noeud_tmp->valeur != valeur){
    pere = noeud_tmp;
    if(noeud_tmp->valeur < valeur){noeud_tmp = noeud_tmp->droit;}
    else
    noeud_tmp = noeud_tmp->gauche;
  }
  if(noeud_tmp -> gauche && noeud_tmp -> droit == NULL){
    // pas de fils
  //  printf("entre 1 %i\n", noeud_tmp->valeur );
    if(pere->gauche->valeur == valeur){
      pere->gauche = NULL;
    }
    else
    pere->droit = NULL;
  }
  else if(noeud_tmp ->gauche != NULL && noeud_tmp->droit != NULL){
    // deux fils
    //printf("entre 2\n" );
   T_Noeud*  fils_g = noeud_tmp->gauche;
   T_Noeud* fils_d = noeud_tmp->droit;

  //   printf("entre aqui\n" );
     if(fils_g->valeur < fils_d->valeur){
       fils_d->gauche = fils_g;
       pere ->gauche = fils_d;

     }
     else{

      fils_g->droit = fils_d;
      pere->droit = fils_g;
   }



  }
  else{
    //printf("entre 3\n" );
  // un fils
  T_Noeud* fils = NULL;
  if(noeud_tmp ->gauche != NULL){
    fils  = noeud_tmp->gauche;
  }
  else
  {fils = noeud_tmp->droit;}
  if(pere->gauche != NULL && pere->gauche->valeur == valeur){
    pere->gauche = fils;
  }
  else{
    pere->droit = fils;
  }
  }
free(noeud_tmp);
printf("Nodo suprimido correctamente ! \n" );

}

int main() {
  T_Arbre abr = NULL;
  abr_inserer(11,&abr);
  abr_inserer(2,&abr);
  abr_inserer(1,&abr);
  abr_inserer(6,&abr);
  abr_inserer(13,&abr);
  abr_inserer(17,&abr);
  abr_inserer(15,&abr);
  abr_prefixe(abr);
  abr_supprimer(13,&abr);
  abr_prefixe(abr);
  return 0;
}
