 struct Noeud_C{
 int suceseur;
 int predeceseur;
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
