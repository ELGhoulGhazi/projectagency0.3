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
DATEDERECRUTEMENT,
USER, 
PASSWORD, 
COLUMNS,
CIN 
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
f=fopen("/home/ggmghoul/Desktop/agency-master/src/client.txt","a");
if(f!=NULL)
{fprintf(f,"%s %s %s %s %s \n",nom,prenom,CIN,user,password);
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
char user[30];
char password[30];  
char date[30]; 
store=NULL ; 
FILE* f ; 

store=gtk_tree_view_get_model(liste) ; 
if (store==NULL) 
{
render=gtk_cell_renderer_text_new () ; 
column =gtk_tree_view_column_new_with_attributes("nom",render,"text",NOM,NULL) ; 
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column); 


render=gtk_cell_renderer_text_new () ; 
column =gtk_tree_view_column_new_with_attributes("prenom",render,"text",PRENOM,NULL) ; 
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column); 

render=gtk_cell_renderer_text_new () ; 
column =gtk_tree_view_column_new_with_attributes("date",render,"text",DATEDERECRUTEMENT,NULL) ; 
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column); 

render=gtk_cell_renderer_text_new () ; 
column =gtk_tree_view_column_new_with_attributes("user",render,"text",USER,NULL) ; 
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column); 

render=gtk_cell_renderer_text_new () ; 
column =gtk_tree_view_column_new_with_attributes("password",render,"text",PASSWORD,NULL) ; 
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
 while(fscanf(f," %s %s %s %s %s \n" ,nom,prenom,date,user,password)!=EOF) 
{
gtk_list_store_append (store,&iter) ; 
gtk_list_store_set (store,&iter,NOM,nom,PRENOM,prenom,DATEDERECRUTEMENT,date,USER,user,PASSWORD,password,-1) ; 
}
fclose(f) ; 
gtk_tree_view_set_model(GTK_TREE_VIEW (liste),GTK_TREE_MODEL (store)); 
g_object_unref (store) ; 
}
}
}


/*
void afficherclient (GtkTreeView *liste)
{
GtkCellRenderer *render ;
GtkTreeViewColumn *column ; 
GtkTreeIter iter ; 

GtkListStore *store ;

char nom[30] ;
char prenom[30] ;
char cin[30]; 
char user[30]; 
char password[30];   

store=NULL ; 
FILE* f ; 

store=gtk_tree_view_get_model(liste) ; 
if (store==NULL) 
{
render=gtk_cell_renderer_text_new () ; 
column =gtk_tree_view_column_new_with_attributes("nom",render,"text",NOM,NULL) ; 
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column); 


render=gtk_cell_renderer_text_new () ; 
column =gtk_tree_view_column_new_with_attributes("prenom",render,"text",PRENOM,NULL) ; 
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column); 


render=gtk_cell_renderer_text_new () ; 
column =gtk_tree_view_column_new_with_attributes("cin",render,"text",CIN,NULL) ; 
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column); 

render=gtk_cell_renderer_text_new () ; 
column =gtk_tree_view_column_new_with_attributes("user",render,"text",USER,NULL) ; 
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column); 

render=gtk_cell_renderer_text_new () ; 
column =gtk_tree_view_column_new_with_attributes("password",render,"text",PASSWORD,NULL) ; 
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column); 

store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING) ; 

f=fopen("/home/ggmghoul/Desktop/agency-master/src/client.txt","r") ; 
if (f==NULL) 
{
return ; 
}
else 
{
f=fopen("/home/ggmghoul/Desktop/agency-master/src/client.txt","a+") ;
 while(fscanf(f," %s %s %s %s %s \n" ,nom,prenom,cin,user,password)!=EOF) 
{
gtk_list_store_append (store,&iter) ; 
gtk_list_store_set (store,&iter,NOM,nom,PRENOM,prenom,CIN,cin,USER,user,PASSWORD,password,-1) ; 
}
fclose(f) ; 
gtk_tree_view_set_model(GTK_TREE_VIEW (liste),GTK_TREE_MODEL (store)); 
g_object_unref (store) ; 
}
}
}



void supprimeremployer(char nom[], char prenom[] ,int j ,int m,int y ,char user[] ,char password[])
{

FILE *f;
FILE *f1
int role;
int a=1,b=1;
char user1[20] ; 
char password1[20] ; 

f=fopen("/home/ggmghoul/Desktop/agency-master/src/users.txt","r");
if (f!=NULL)
{
while(fscanf(f," %s %s %d \n" ,user1,password1,&role)!=EOF)
{
a=strcmp(user,user1);
   b=strcmp(password,password1);  
if ((a!=0) && (b!=0))
   { 
      f1=fopen("/home/ggmghoul/Desktop/agency-master/src/empty.txt","a"); 
    if(f1!=NULL)
        {
          fprintf(f1,"%s %s %d \n",user1,password1,role);
          fclose(f1);
        }
    }
}

f=fopen("/home/ggmghoul/Desktop/agency-master/src/users.txt","w");
if(f1!=NULL)
        {
          fprintf(f,"/0\n");
          fclose(f);
        }


f1=fopen("/home/ggmghoul/Desktop/agency-master/src/empty.txt","r");
if (f!=NULL)
{
while(fscanf(f1," %s %s %d \n" ,user1,password1,&role)!=EOF)
{
      f=fopen("/home/ggmghoul/Desktop/agency-master/src/users.txt","a"); 
    if(f1!=NULL)
        {
          fprintf(f,"%s %s %d \n",user1,password1,role);
          fclose(f);
        }
    }
}

   
 
}
f=fopen("/home/ggmghoul/Desktop/agency-master/src/empinfo.txt","a");
if(f!=NULL)
{fprintf(f,"%s %s %d/%d/%d %s %s \n",nom,prenom,j,m,y,user,password);
fclose(f);
}
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
