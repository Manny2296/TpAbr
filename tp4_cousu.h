 struct Noeud_C{
 int booleand;
 int booleang;
 struct Noeud_C* gauche;
 struct Noeud_C* droit;
};
typedef struct Noeud_C T_Noeud_C;
typedef struct Noeud_C* T_Arbre_C;
T_Noeud_C *cousu_creer_noeud(int valeur);
