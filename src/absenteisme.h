typedef struct
{
    int id;
    int jour;
    int mois;
    int annee;
    int valeur;
}abse;

int taux(int id,int annee);
float taux_m(int id,int annee,int mois);
int recherche(int id);
void meilleur(int mois,int annee);
void calcul(int *c);
