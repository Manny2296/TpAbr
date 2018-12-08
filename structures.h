#include <stdlib.h>
#include <stdio.h>

struct Noeud{
int valeur;
struct Noeud* gauche;
struct Noeud* droit;
};
typedef struct Noeud T_Noeud;
typedef struct Noeud* T_Arbre;
T_Noeud *abr_creer_noeud(int valeur);
void abr_prefixe(T_Arbre abr);
void abr_inserer(int valeur,T_Arbre *abr);
void abr_supprimer(int valeur,T_Arbre *abr);
