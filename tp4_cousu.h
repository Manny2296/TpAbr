#include "tp4_abr.h"
#ifndef TP4_COUSU_H_INCLUDED
#define TP4_COUSU_H_INCLUDED

struct Noeud_C{
 int successeur;
 int predecesseur;
 int valeur;
 struct Noeud_C* gauche;
 struct Noeud_C* droit;
};

typedef struct Noeud_C T_Noeud_C;
typedef struct Noeud_C* T_Arbre_C;

T_Noeud_C *cousu_creer_noeud(int valeur);
void cousu_inserer(int valeur,T_Arbre_C *arbre);
void cousu_prefixe(T_Arbre_C arbre);
void cousu_infixe(T_Arbre_C *arbre);
void abr_to_cousu(T_Arbre abr, T_Arbre_C *clone, T_Noeud* parent);
void detruire_arbre_cousu(T_Arbre_C *arbre);


#endif // TP4_COUSU_H_INCLUDED
