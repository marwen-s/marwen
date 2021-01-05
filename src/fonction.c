#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fonction.h"
#include <gtk/gtk.h>

enum
{
ID,
NOM,
PRENOM,
SEXE,
JOUR,
MOIS,
ANNEE,
METIER,
COLUMNS
};





////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void  ajout_ouvrier(ouvrier o)
{
    FILE *f=NULL;
    f=fopen("ouvrier.txt","a");
    if(f!=NULL)
    {
        fprintf(f,"%d %s %s %s %d %d %d %s\n",o.id, o.nom,o.prenom,o.sexe,o.date_naissance.jour,o.date_naissance.mois,o.date_naissance.annee, o.metier);
        fclose(f);
    }
    else
        printf("NOT FOUND");
}



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void affichage_ouvrier(GtkWidget *treeview){


GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

char id[20];
char nom[20];
char prenom[20];
 char sexe[20];
//date date_naissance;
char jour[20];
char mois[20];
char annee[20];
    
char metier[20];
    
ouvrier ouv;

//int presence;
 FILE *f;  
 

f = fopen("ouvrier.txt", "a+");

store=NULL;
store=gtk_tree_view_get_model(treeview);

if (store==NULL)
{

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("id",renderer, "text", ID,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("nom",renderer, "text", NOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("prenom",renderer, "text", PRENOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("sexe",renderer, "text", SEXE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("jour",renderer,"text",JOUR,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(treeview),column);
                 
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("mois",renderer,"text",MOIS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(treeview),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("annee",renderer,"text",ANNEE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(treeview),column);


renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("metier",renderer, "text", METIER,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);


store= gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

f = fopen("ouvrier.txt", "r");

if(f==NULL){return;}
else
{ 
//f = fopen("ouvrier.txt", "a+");


while (fscanf(f,"%d %s %s %s %d %d %d %s\n",&ouv.id, ouv.nom,ouv.prenom,ouv.sexe,&ouv.date_naissance.jour,&ouv.date_naissance.mois,&ouv.date_naissance.annee, ouv.metier)!=EOF)
{

    sprintf(id,"%d",ouv.id);

    strcpy(nom,ouv.nom);
    strcpy(prenom,ouv.prenom);
    strcpy(metier,ouv.metier);
    strcpy(sexe,ouv.sexe);

 sprintf(jour,"%d",ouv.date_naissance.jour);
 sprintf(mois,"%d",ouv.date_naissance.mois);
 sprintf(annee,"%d",ouv.date_naissance.annee);

gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,ID,id,NOM,nom,PRENOM,prenom,SEXE,sexe,JOUR,jour,MOIS,mois,ANNEE,annee, METIER,metier,-1);
}

 fclose(f);
}
gtk_tree_view_set_model(GTK_TREE_VIEW(treeview), GTK_TREE_MODEL(store));
g_object_unref(store);
 
}

}


////////////////////////////////////////////////////////////////////////////////////////////////
void suppression_ouvrier(int id )
{
    FILE *f=NULL;
    FILE *tmp=NULL;
    ouvrier o1;
    f=fopen("ouvrier.txt","r");
    tmp=fopen("tmp.txt","w");
    if(f!=NULL)
    {
while (fscanf(f,"%d %s %s %s %d %d %d %s\n",&o1.id, o1.nom,o1.prenom,o1.sexe,&o1.date_naissance.jour,&o1.date_naissance.mois,&o1.date_naissance.annee, o1.metier)!=EOF)      

       {
        if(o1.id!=id)
        {
 fprintf(tmp,"%d %s %s %s %d %d %d %s\n",o1.id, o1.nom,o1.prenom,o1.sexe,o1.date_naissance.jour,o1.date_naissance.mois,o1.date_naissance.annee, o1.metier);          

        }

       }
        fclose(f);
        fclose(tmp);
        remove("ouvrier.txt");
        rename("tmp.txt","ouvrier.txt");

    }
    else
        printf("NOT FOUND");
}


///////////////////////////////////////////////////////////////////////////////////////////////

void modification_ouvrier(ouvrier ouv_nouv,ouvrier ouv_modif) {

 
    FILE *f=NULL;
    FILE *tmp=NULL;
 
    ouvrier ouv;



    f=fopen("ouvrier.txt","r");


    tmp=fopen("tmp.txt","w");


    if (f!=NULL) {

      
        while(fscanf(f,"%d %s %s %s %d %d %d %s\n",&ouv.id, ouv.nom,ouv.prenom,ouv.sexe,&ouv.date_naissance.jour,&ouv.date_naissance.mois,&ouv.date_naissance.annee, ouv.metier)!=EOF){
            if ( ouv.id == ouv_modif.id ) {
fprintf(tmp,"%d %s %s %s %d %d %d %s\n",ouv_nouv.id, ouv_nouv.nom,ouv_nouv.prenom,ouv_nouv.sexe,ouv_nouv.date_naissance.jour,ouv_nouv.date_naissance.mois,ouv_nouv.date_naissance.annee, ouv_nouv.metier);}
            else {
fprintf(tmp,"%d %s %s %s %d %d %d %s\n",ouv.id, ouv.nom,ouv.prenom,ouv.sexe,ouv.date_naissance.jour,ouv.date_naissance.mois,ouv.date_naissance.annee, ouv.metier);}
            }
        }

        fclose(f);
        fclose(tmp);
        remove("ouvrier.txt");
        rename("tmp.txt","ouvrier.txt");
}

///////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
/*
void modification_ouvrier(int id ,ouvrier o2)
{
    suppression_ouvrier(id);
    ajout_ouvrier( o2);
}
int recherche_id(int id,ouvrier *p)
{
    FILE *f=NULL;
    ouvrier o1;
    int test;
    f=fopen("ouvrier.txt","r");
    test=0;
    if(f!=NULL)
    {
       while(fscanf(f,"%d %s %s %s %s %d %d %d\n",&o1.id,o1.metier,o1.nom,o1.prenom,o1.sexe,&o1.date_naissance.jour
                    ,&o1.date_naissance.mois,&o1.date_naissance.annee )!=EOF)
       {
         if(o1.id == id )
        {
          *p=o1;
          test=1;
          break;
        }

       }
        fclose(f);
        }
        else
        printf("not founded");
        return(test);
}


/////////////////////////////////////////////////////////////////////////////////////////////
 int count_abs(int id1, annee1)
{
    int id,jour,mois,annee,valeur;
    int nbre=0;

    FILE *f=NULL;
    ouvrier o1;
    f=fopen("absenteisme.txt","r");
    if(f!=NULL)
    {
       while(fscanf(f,"%d %d %d %d %d\n",id,jour,mois,annee,valeur )!=EOF)
       {
         if(id1==id && valeur==0 && annee==annee1)
        {

          nbre+=1;

        }

       }
        fclose(f);
        }
        else
        printf("not founded");
    return(nbre);
}
*/

