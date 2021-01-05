#include "absenteisme.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fonction.h"
#include <gtk/gtk.h>

int taux(int id,int annee)
{
    int s=0,n=0;
    abse a;
    FILE *f=NULL;
    f=fopen("absenteisme.txt","r");
    while(fscanf(f,"%d %d %d %d %d\n",&a.id,&a.jour,&a.mois,&a.annee,&a.valeur)!=EOF)
    {

       if(a.id==id && annee==a.annee)
       {
           n++;
           if(a.valeur==0)
          s++ ;

       }
    }

    fclose(f);
    return((float)s/n);

}
float taux_m(int id,int annee,int mois)
{
    int s=0,n=0;
    abse a;
    FILE *f=NULL;
    f=fopen("absenteisme.txt","r");
    while(fscanf(f,"%d %d %d %d %d\n",&a.id,&a.jour,&a.mois,&a.annee,&a.valeur)!=EOF)
    {
       if(a.id==id && annee==a.annee && a.mois==mois)
       {
           n++;
           if(a.valeur==0)
          s++ ;

       }
    }

    fclose(f);
    return((float)s/n);

}
int recherche(int id)
{
 int id1;
 float valeur;
    FILE *f=NULL;
    f=fopen("meilleur.txt","r");
    while(fscanf(f,"%d %f\n",&id1,&valeur)!=EOF)
    {

      if(id1==id)
            
                return(1);
            


    }
    return(0);

    fclose(f);

}
void meilleur(int mois,int annee)
{
    int id;
    abse a;
    FILE *f=NULL,*g=NULL;
    f=fopen("absenteisme.txt","r");
    g=fopen("meilleur.txt","w");
    while(fscanf(f,"%d %d %d %d %d\n",&a.id,&a.jour,&a.mois,&a.annee,&a.valeur)!=EOF)
    {
      if(a.mois==mois && a.annee==annee)
      {
           if(recherche(a.id) == 0)
            {
                fprintf(g,"%d %f\n",a.id,taux_m(a.id,annee,mois));
            }
      }
    }


    fclose(f);
    fclose(g);
}
void calcul(int *d)
{
 FILE *g=NULL;
 int a;
 float  m=2,b; 
 g=fopen("meilleur.txt","r");
    while(fscanf(g,"%d %f\n",&a, &b )!=EOF)
    {
      if(m>b)
       {
       m=b; 
       *d=a;
       }
    }
 fclose(g);
}




    

