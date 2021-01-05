#ifndef FONCTION_H_INCLUDED
#define FONCTION_H_INCLUDED

#include <gtk/gtk.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    int jour;
    int mois;
    int annee;
}date;
typedef struct
{
    int id;
    char nom[20];
    char prenom[20];
    char sexe[20];
    date date_naissance;
    char metier[20];



}ouvrier;

int count_abs(int id1);
void  ajout_ouvrier(ouvrier o);

void affichage_ouvrier(GtkWidget *treeview);

void suppression_ouvrier(int id);
void modification_ouvrier(ouvrier ouv_nouv,ouvrier ouv_modif);
//void modification_ouvrier(int id, ouvrier o2);
int recherche_id(int id,ouvrier *p);




#endif // FONCTION_H_INCLUDED

