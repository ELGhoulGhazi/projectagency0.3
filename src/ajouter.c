#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"ajouter.h"
#include <gtk/gtk.h>

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

enum 
{
NOM ,
PRENOM,
JOUR, 
MOIS,
ANNEE, 
COLUMNS
}; 



void inscri (char nom[], char prenom[] ,char CIN[] ,char user[] ,char password[]) 
{
FILE *f;
int role=3 ;
f=fopen("/home/ggmghoul/Desktop/agency-master/src/users.txt","a");
if(f!=NULL)
{fprintf(f,"%s %s %d \n",user,password,role);
fclose(f);
}
}


void ajouteremployer (char nom[], char prenom[] ,int j ,int m,int y ,char user[] ,char password[])
{
FILE *f;
int role=2 ;
f=fopen("/home/ggmghoul/Desktop/agency-master/src/users.txt","a");
if(f!=NULL)
{fprintf(f,"%s %s %d \n",user,password,role);
fclose(f);
}
f=fopen("/home/ggmghoul/Desktop/agency-master/src/empinfo.txt","a");
if(f!=NULL)
{fprintf(f,"%s %s %d/%d/%d %s %s \n",nom,prenom,j,m,y,user,password);
fclose(f);
}
}

void afficheremp (GtkTreeView *liste)
{
GtkCellRenderer *render ;
GtkTreeViewColumn *column ; 
GtkTreeIter iter ; 

GtkListStore *store ;

char nom[30] ;
char prenom[30] ;
char j[30];
char m[30];
char y[30];  

store=NULL ; 
FILE* f ; 

store=gtk_tree_view_get_model(liste) ; 
if (store==NULL) 
{
render=gtk_cell_renderer_text_new () ; 
column =gtk_tree_view_column_new_with_attributes("NOM",render,"text",NOM,NULL) ; 
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column); 


render=gtk_cell_renderer_text_new () ; 
column =gtk_tree_view_column_new_with_attributes("PRENOM",render,"text",PRENOM,NULL) ; 
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column); 

render=gtk_cell_renderer_text_new () ; 
column =gtk_tree_view_column_new_with_attributes("JOUR",render,"text",JOUR,NULL) ; 
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column); 

render=gtk_cell_renderer_text_new () ; 
column =gtk_tree_view_column_new_with_attributes("MOIS",render,"text",MOIS,NULL) ; 
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column); 

render=gtk_cell_renderer_text_new () ; 
column =gtk_tree_view_column_new_with_attributes("ANNEE",render,"text",ANNEE,NULL) ; 
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column); 


store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING) ; 

f=fopen("/home/ggmghoul/Desktop/agency-master/src/empinfo.txt","r") ; 
if (f==NULL) 
{
return ; 
}
else 
{
f=fopen("/home/ggmghoul/Desktop/agency-master/src/empinfo.txt","a+") ;
 while(fscanf(f," %s %s %s %s %s \n" ,nom,prenom,j,m,y)!=EOF) 
{
gtk_list_store_append (store,&iter) ; 
gtk_list_store_set (store,&iter,nom,NOM,prenom,PRENOM,j,JOUR,m,MOIS,y,ANNEE,-1) ; 
}
fclose(f) ; 
gtk_tree_view_set_model(GTK_TREE_VIEW (liste),GTK_TREE_MODEL (store)); 
g_object_unref (store) ; 
}
}
}

/*
void supprimeremployer()
{
}
 

void modifieremployer (char nom[], char prenom[] ,char date ,char user[] ,char password[])
{
FILE *f;
int role=2 ;
f=fopen("/home/ggmghoul/Desktop/agency-master/src/users.txt","w+");
if(f!=NULL)
{fprintf(f,"%s %s %d \n",user,password,role);
fclose(f);
}

 
void supprimerclient ()
{
}

 
void modifierclient ()
{
}


 
*/
