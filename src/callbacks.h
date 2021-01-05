#include <gtk/gtk.h>


void
on_ajouter_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_buttonRetour_clicked                (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_treeviewListeOuvriers_row_activated (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_buttonListe_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonAjouter_clicked               (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonMeilleur_clicked              (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonTaux_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data);



void
on_RetourListe_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data);


void
on_modifierOuvrier_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_supprimerOuvrier_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonModifier_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonSupprimer_clicked             (GtkButton       *objet,
                                        gpointer         user_data);

void
on_MeilleurOuvrier_clicked             (GtkWidget      *button,
                                        gpointer         user_data);
////////////////////////////////////////////////////////////////////
void
on_ajoutRetour_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_modifRetour_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_suppRetour_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_meilleurRetour_clicked              (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_tauxRetour_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_checkbuttonSupp_clicked             (GtkButton       *button,
                                        gpointer         user_data);
