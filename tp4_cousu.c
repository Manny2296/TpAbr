#include <stdio.h>
#include <stdlib.h>
#include <tp4_cousu.h>
T_Noeud_C* cousu_creer_noeud(int valeur){
  T_Noeud_C* noeud_c = malloc(size_of(T_Noeud_C));
  noeud_c->booleand = 1;
  noeud_c->booleang = 1;
  noeud_c->gauche = NULL;
  noeud_c->droit = NULL;
  noeud_c->valeur = valeur;
  return noeud_c;
}
void cousu_prefixe(T_Arbre_C arbre){
  printf("Noeud --> %d\n", abr->valeur);
  printf(" -----> FG : " );
  if(abr->booleand == 1){printf("NULL ");}
  else{printf("%d ",abr->gauche->valeur);}
  printf(" -- FD : ");
  if(abr->booleang == 1){  printf("NULL \n"); }
  else{printf("%d \n",abr->droit->valeur);}
  if(abr->booleang != 1){ cousu_prefixe(abr->gauche);}
  if(abr->booleand != 1){ cousu_prefixe(abr->droit);}
}
