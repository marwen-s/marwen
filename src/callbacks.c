#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fonction.h"
#include <stdlib.h>
#include <stdio.h>
#include <glib.h>
#include <absenteisme.h>

ouvrier ouv_modif;

//////////////////////////////////////////////////////////////////////////
void
on_ajouter_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
ouvrier ouv;

GtkWidget *date;
GtkWidget *id;
GtkWidget *nom;
GtkWidget *prenom;
GtkWidget *metier;
GtkWidget *femme;
GtkWidget *csid, *csnom, *csprenom, *csmetier, *notifajout;
date=lookup_widget(objet_graphique, "calendarAjout");
guint year, month, day;
int y=0,m=0,d=0;
gtk_calendar_get_date(GTK_CALENDAR(date),&year,&month,&day);
y=year;
m=month+1;
d=day;
id=lookup_widget(objet_graphique,"entryId");
nom=lookup_widget(objet_graphique,"entryNom");
prenom=lookup_widget(objet_graphique,"entryPrenom");
metier=lookup_widget(objet_graphique,"entryMetier");
csid=lookup_widget(objet_graphique, "csid");
csnom=lookup_widget(objet_graphique, "csnom");
csprenom=lookup_widget(objet_graphique, "csprenom");
csmetier=lookup_widget(objet_graphique, "csmetier");
notifajout=lookup_widget(objet_graphique, "notifajout");
ouv.date_naissance.jour=d;
ouv.date_naissance.mois=m;
ouv.date_naissance.annee=y;
femme=lookup_widget(objet_graphique,"radiobutton1");
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(femme)))
    strcpy(ouv.sexe,"femme");
else
    strcpy(ouv.sexe,"homme");

gtk_label_set_text(GTK_LABEL(notifajout),"");
gtk_label_set_text(GTK_LABEL(csid),"");
gtk_label_set_text(GTK_LABEL(csnom),"");
gtk_label_set_text(GTK_LABEL(csprenom),"");
gtk_label_set_text(GTK_LABEL(csmetier),"");

if ((strcmp(gtk_entry_get_text(GTK_ENTRY(nom)),"") != 0)&&(strcmp(gtk_entry_get_text(GTK_ENTRY(id)),"") != 0)&&(strcmp(gtk_entry_get_text(GTK_ENTRY(prenom)),"") != 0)&&(strcmp(gtk_entry_get_text(GTK_ENTRY(metier)),"") != 0))
{
ouv.id=atoi(gtk_entry_get_text(GTK_ENTRY(id)));
strcpy(ouv.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(ouv.prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));
strcpy(ouv.metier,gtk_entry_get_text(GTK_ENTRY(metier)));
ajout_ouvrier(ouv);
 gtk_label_set_text(GTK_LABEL(notifajout),"ajouté avec succes");
}
else
{
if(strcmp(gtk_entry_get_text(GTK_ENTRY(id)),"") == 0)
gtk_label_set_text(GTK_LABEL(csid),"Champ obligatoire");
if(strcmp(gtk_entry_get_text(GTK_ENTRY(nom)),"") == 0)
gtk_label_set_text(GTK_LABEL(csnom),"Champ obligatoire");
if(strcmp(gtk_entry_get_text(GTK_ENTRY(prenom)),"") == 0)
gtk_label_set_text(GTK_LABEL(csprenom),"Champ obligatoire");
if(strcmp(gtk_entry_get_text(GTK_ENTRY(metier)),"") == 0)
gtk_label_set_text(GTK_LABEL(csmetier),"Champ obligatoire");
}
}

//////////////////////////////////////////////////////////////////////////
void
on_buttonRetour_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{

GtkWidget *window1,*window2;
window1=lookup_widget(objet,"windowTaux");
gtk_widget_destroy(window1);
window2=lookup_widget(objet,"windowListe");
window2=create_windowGRH();
gtk_widget_show(window2);

}

//////////////////////////////////////////////////////////////////////////

void
on_treeviewListeOuvriers_row_activated (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)

{

GtkTreeIter iter;
gchar* id;
gchar* nom;
gchar* prenom;
gchar* sexe;

gchar* jour;
gchar* mois;
gchar* annee;

gchar* metier;


GtkWidget *window_main;
GtkWidget *objet_main;
GtkWidget *window_suppression;

char msg[100];

GtkWidget *input1,*input2,*input3,*input4,*input5,*input6,*input7,*input8;
char JOUR[5],MOIS[5],ANNEE[5];

GtkWidget *output;
ouvrier ouv;

GtkTreeModel *model = gtk_tree_view_get_model(treeview);
if(gtk_tree_model_get_iter(model,&iter,path))
	{
	 
	gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&id,1,&nom,2,&prenom,3,&sexe,4,&jour,5,&mois,6,&annee,7,&metier,-1);
 
	
  ouv.id=atoi(id);
 
	strcpy(ouv.nom,nom);
	strcpy(ouv.prenom,prenom);
	strcpy(ouv.sexe,sexe);
	
ouv.date_naissance.jour=atoi(jour);
ouv.date_naissance.mois=atoi(mois);
ouv.date_naissance.annee=atoi(annee);
 
        strcpy(ouv.metier,metier);
 
 

    objet_main=&treeview->parent.widget;

    window_main=lookup_widget(objet_main,"windowListe");
    gtk_widget_destroy(window_main);

    window_suppression = create_windowSupprimer ();
    gtk_widget_show(window_suppression);


    input1=lookup_widget(window_suppression,"idSupp");
    input2=lookup_widget(window_suppression,"nomSupp");
    input3=lookup_widget(window_suppression,"prenomSupp");
    input4=lookup_widget(window_suppression,"sexeSupp");
    input5=lookup_widget(window_suppression,"jourSupp");
    input6=lookup_widget(window_suppression,"moisSupp");
    input7=lookup_widget(window_suppression,"anneeSupp");
    input8=lookup_widget(window_suppression,"metierSupp");
    

    char ch[20];
    sprintf(ch, "%d",ouv.id);
    sprintf(JOUR,"%d",ouv.date_naissance.jour);
    sprintf(MOIS,"%d",ouv.date_naissance.mois);
    sprintf(ANNEE,"%d",ouv.date_naissance.annee);

    gtk_label_set_text(GTK_LABEL(input1),ch);
    gtk_label_set_text(GTK_LABEL(input2),ouv.nom);
    gtk_label_set_text(GTK_LABEL(input3),ouv.prenom);
    gtk_label_set_text(GTK_LABEL(input4),ouv.sexe);
    gtk_label_set_text(GTK_LABEL(input5),JOUR);
    gtk_label_set_text(GTK_LABEL(input6),MOIS);
    gtk_label_set_text(GTK_LABEL(input7),ANNEE);
    gtk_label_set_text(GTK_LABEL(input8),metier);



    
	}











/*

GtkTreeIter iter;
//gint* id;
gchar* nom;
gchar* prenom;
//gint* sexe;
gchar* metier;
//date* dates;
ouvrier ouv;



GtkTreeModel *model = gtk_tree_view_get_model(treeview);

if(gtk_tree_model_get_iter(model,&iter,path))
{

//gtk_tree_model_get (GTK_LIST_STORE(model),&iter,0,&id,1,&nom,2,&prenom,3,&sexe,4,&metier,5,&dates,-1);
gtk_tree_model_get (GTK_LIST_STORE(model),&iter,0,&nom,1,&prenom,2,&metier,-1);
//ouv.id=(int)id;
strcpy(ouv.nom,nom);
strcpy(ouv.prenom,prenom);
//ouv.sexe=(int)sexe;
strcpy(ouv.metier,metier);

//ouv.date_naissance=dates;


suppression_ouvrier(ouv.id);
affichage_ouvrier(treeview);
}

*/

}





//////////////////////////////////////////////////////////////////////////
void
on_buttonListe_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget  *fenetre_grh; 
GtkWidget *fenetre_liste;
GtkWidget *treeview;

fenetre_grh=lookup_widget(objet,"windowGRH");

gtk_widget_destroy(fenetre_grh);
fenetre_liste=lookup_widget(objet,"windowListe");
fenetre_liste=create_windowListe();

gtk_widget_show(fenetre_liste);

treeview=lookup_widget(fenetre_liste,"treeviewListeOuvriers");

affichage_ouvrier(treeview);
}










void
on_buttonAjouter_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window1,*window2;
window1=lookup_widget(objet,"windowGRH");
gtk_widget_destroy(window1);
window2=lookup_widget(objet,"windowAjouter");
window2=create_windowAjouter();
gtk_widget_show(window2);
}


void
on_buttonMeilleur_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window1,*window2;
window1=lookup_widget(objet,"windowGRH");
gtk_widget_destroy(window1);
window2=lookup_widget(objet,"windowMeilleur");
window2=create_windowMeilleur();
gtk_widget_show(window2);
}


void
on_buttonTaux_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window1,*window2;
window1=lookup_widget(objet,"windowGRH");
gtk_widget_destroy(window1);
window2=lookup_widget(objet,"windowTaux");
window2=create_windowTaux();
gtk_widget_show(window2);
}





void
on_RetourListe_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window1,*window2;

window2=lookup_widget(objet,"windowGRH");
window2=create_windowGRH();
gtk_widget_show(window2);
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void
on_modifierOuvrier_clicked             (GtkButton       *objet,
                                        gpointer         user_data)
{
ouvrier ouv;

    GtkWidget *input1,*input2,*input3,*input4,*input5,*input6,*input7,*input8;

    GtkWidget *output;
    char msg[100];

    GtkWidget *window_modification;

    window_modification=lookup_widget(objet,"windowModifier");


    input1=lookup_widget(objet,"entryIdModif");
    input2=lookup_widget(objet,"entryNomModif");
    input3=lookup_widget(objet,"entryPrenomModif");
    input4=lookup_widget(objet,"comboSexeModif");
    input5=lookup_widget(objet,"spinJourModif");
    input6=lookup_widget(objet,"spinMoisModif");
    input7=lookup_widget(objet,"spinAnneeModif");
    input8=lookup_widget(objet,"entryMetierModif");



    ouv.id=atoi(gtk_entry_get_text(GTK_ENTRY(input1)));
    strcpy(ouv.nom,gtk_entry_get_text(GTK_ENTRY(input2)));
    strcpy(ouv.prenom,gtk_entry_get_text(GTK_ENTRY(input3)));
    strcpy(ouv.sexe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input4)));
    ouv.date_naissance.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input5));
    ouv.date_naissance.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input6));
    ouv.date_naissance.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input7));
    strcpy(ouv.metier,gtk_entry_get_text(GTK_ENTRY(input8)));
  
    

    modification_ouvrier(ouv,ouv_modif);

    // Pour le message de validation
    //output = lookup_widget(objet, "label_validation_modification") ;
    //msg_validation(ouv_modif.id,msg,"modification");
    //gtk_label_set_text(GTK_LABEL(output),msg);

}


void
on_supprimerOuvrier_clicked            (GtkButton       *objet,
                                        gpointer         user_data)
{
 GtkWidget *input1;
    int ouv_id_supp;
    GtkWidget *output;
    char msg[100];


    input1=lookup_widget(objet,"idSupp");
    ouv_id_supp=atoi(gtk_label_get_text(GTK_LABEL(input1)));
    //strcpy(ouv_id_supp,gtk_label_get_label(GTK_LABEL(input1)));
    suppression_ouvrier(ouv_id_supp);
    

    // Pour le message de validation
 //   output = lookup_widget(objet, "label_validation_suppression") ;
   // msg_validation(p_id_supp,msg,"suppression");
   // gtk_label_set_text(GTK_LABEL(output),msg);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void
on_buttonModifier_clicked              (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *window_main;
GtkWidget *window_modification;

GtkWidget *treeView1;
GtkTreeSelection *selection ;
GtkTreeModel *model;
GtkTreeIter iter;
gchar* id;
gchar* nom;
gchar* prenom;
gchar* sexe;
gchar* jour;
gchar* mois;
gchar* annee;
gchar* metier;
ouvrier ouv;
gint index_sexe=-1;


GtkWidget *input1,*input2, *input3,*input4,*input5,*input6,*input7, *input8;


	window_main=lookup_widget(objet,"windowListe");

    treeView1=lookup_widget(window_main,"treeviewListeOuvriers");
    selection=gtk_tree_view_get_selection(GTK_TREE_VIEW(treeView1));

    if(gtk_tree_selection_get_selected(selection,&model,&iter)) {

        
        gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&id,1,&nom,2,&prenom,3,&sexe,4,&jour,5,&mois,6,&annee,7,&metier,-1);
        

ouv_modif.id=atoi(id);
strcpy(ouv_modif.nom,nom);
strcpy(ouv_modif.prenom,prenom);
strcpy(ouv_modif.sexe,sexe);	
ouv_modif.date_naissance.jour=atoi(jour);
ouv_modif.date_naissance.mois=atoi(mois);
ouv_modif.date_naissance.annee=atoi(annee);
strcpy(ouv_modif.metier,metier);

    }

    gtk_widget_destroy(window_main);

    window_modification=create_windowModifier();
	gtk_widget_show(window_modification);


    input1=lookup_widget(window_modification,"entryIdModif");
    input2=lookup_widget(window_modification,"entryNomModif");
    input3=lookup_widget(window_modification,"entryPrenomModif");
    input4=lookup_widget(window_modification,"comboSexeModif");
    input5=lookup_widget(window_modification,"spinJourModif");
    input6=lookup_widget(window_modification,"spinMoisModif");
    input7=lookup_widget(window_modification,"spinAnneeModif");
    input8=lookup_widget(window_modification,"entryMetierModif");

    char ch[20];
    sprintf(ch, "%d",ouv_modif.id);
    gtk_entry_set_text(GTK_ENTRY(input1),ch);

    //gtk_entry_set_text(GTK_ENTRY(input1),ouv_modif.id);
    gtk_entry_set_text(GTK_ENTRY(input2),ouv_modif.nom);
    gtk_entry_set_text(GTK_ENTRY(input3),ouv_modif.prenom);

        if(strcmp(ouv_modif.sexe,"homme")==0)
            index_sexe=0;
        else //if(strcmp(ouv_modif.sexe,"femme")==0)
            index_sexe=1;

    gtk_combo_box_set_active(GTK_COMBO_BOX(input4),index_sexe);
    gtk_spin_button_set_value(GTK_SPIN_BUTTON(input5),ouv_modif.date_naissance.jour);
    gtk_spin_button_set_value(GTK_SPIN_BUTTON(input6),ouv_modif.date_naissance.mois);
    gtk_spin_button_set_value(GTK_SPIN_BUTTON(input7),ouv_modif.date_naissance.annee);
    gtk_entry_set_text(GTK_ENTRY(input8),ouv_modif.metier);



}


void
on_buttonSupprimer_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_MeilleurOuvrier_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{

GtkWidget *input1, *input2, *input3;
int a,b,c;
char ch[20];
input1=lookup_widget(objet,"spinAnnee");
input2=lookup_widget(objet,"spinMois");
input3=lookup_widget(objet,"labelIdMeilleur");

a=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input1));
b=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input2));
meilleur(b,a);
calcul(&c);
sprintf(ch,"%d", c);
gtk_label_set_text(GTK_LABEL(input3),ch);


}


void
on_ajoutRetour_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window1,*window2,*treeview1;
window1=lookup_widget(objet,"windowAjouter");
gtk_widget_destroy(window1);
window2=lookup_widget(objet,"windowListe");
window2=create_windowListe();
gtk_widget_show(window2);

treeview1=lookup_widget(window2,"treeviewListeOuvriers");
affichage_ouvrier(treeview1);
}


void
on_modifRetour_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window1,*window2,*treeview1;
window1=lookup_widget(objet,"windowModifier");
gtk_widget_destroy(window1);
window2=lookup_widget(objet,"windowListe");
window2=create_windowListe();
gtk_widget_show(window2);

treeview1=lookup_widget(window2,"treeviewListeOuvriers");
affichage_ouvrier(treeview1);
}


void
on_suppRetour_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window1,*window2,*treeview1;
window1=lookup_widget(objet,"windowSupprimer");
gtk_widget_destroy(window1);
window2=lookup_widget(objet,"windowListe");
window2=create_windowListe();
gtk_widget_show(window2);

treeview1=lookup_widget(window2,"treeviewListeOuvriers");
affichage_ouvrier(treeview1);
}


void
on_meilleurRetour_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window1,*window2, *treeview1;
window1=lookup_widget(objet,"windowMeilleur");
gtk_widget_destroy(window1);
window2=lookup_widget(objet,"windowListe");
window2=create_windowListe();
gtk_widget_show(window2);

treeview1=lookup_widget(window2,"treeviewListeOuvriers");
affichage_ouvrier(treeview1);
}


void
on_tauxRetour_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window1,*window2,*treeview1 ;
window1=lookup_widget(objet,"windowTaux");
gtk_widget_destroy(window1);
window2=lookup_widget(objet,"windowListe");
window2=create_windowListe();
gtk_widget_show(window2);

treeview1=lookup_widget(window2,"treeviewListeOuvriers");
affichage_ouvrier(treeview1);
}


void
on_checkbuttonSupp_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{

}

