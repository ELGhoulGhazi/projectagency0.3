#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"reservation.h"
#include <gtk/gtk.h>

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

enum
{
DEPART , 
 DESTINATION , 
COMPAGNIE , 
HEUREDEDEPART , 
DATEALLER ,
DATERETOUR ,
PRIX ,
PAYS ,
HOTEL

}; 


int verifierdest (char depart[] ,char destination[], char heurededepart[50][50] ,char compagnie[50][50],char datealler[50][50], char dateretour[50][50],char prix[] ) 
{
char depart1[30] ;
char destination1[30] ;
char heurededepart1[30] ;
char compagnie1[30] ;
char datealler1[30] ;
char dateretour1[30];
char prix1[30] ;

int a=1,b=1,c=0 ; 
int i ;

FILE *f ; 
f=fopen("/home/ggmghoul/Desktop/agency-master/src/voldispo.txt","r");
if(f!=NULL)
{
while(fscanf(f,"%s %s %s %s %s %s %s \n",depart1,destination1,heurededepart1,compagnie1,datealler1,dateretour1,prix1)!=EOF)
{
a=strcmp(depart,depart1) ; 
  b=strcmp(destination,destination1) ;

if (a==0 && b==0) 
{
strcpy(compagnie[i],compagnie1) ; 
strcpy(heurededepart[i],heurededepart1) ;
strcpy(datealler[i],datealler1) ;
strcpy(dateretour[i],dateretour1) ;
c++ ;
} 
}
}
fclose(f); 
return c ; 

 
}

void ajoutervol (char depart[] ,char destination[], char heurededepart[] ,char compagnie[],char datealler[], char dateretour[],char prix[]) 
{
FILE *f;

f=fopen("/home/ggmghoul/Desktop/agency-master/src/voldispo.txt","a");
if(f!=NULL)
{fprintf(f,"%s %s %s %s %s %s %s \n",depart,destination,heurededepart,compagnie,datealler,dateretour,prix);
fclose(f);
}
}

/*
void affichervol (GtkTreeView *liste)
{
GtkCellRenderer *render ;
GtkTreeViewColumn *column ; 
GtkTreeIter iter ; 

GtkListStore *store ;

char depart[30] ;
char destination[30] ;
char compagnie[30];
char heure[30];
char da[30];
char dr[30] ; 


store=NULL ; 
FILE* f ; 

store=gtk_tree_view_get_model(liste) ; 
if (store==NULL) 
{
render=gtk_cell_renderer_text_new () ; 
column =gtk_tree_view_column_new_with_attributes("Depart",render,"text",DEPART,NULL) ; 
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column); 


render=gtk_cell_renderer_text_new () ; 
column =gtk_tree_view_column_new_with_attributes("Destination",render,"text",DESTINATION,NULL) ; 
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column); 


render=gtk_cell_renderer_text_new () ; 
column =gtk_tree_view_column_new_with_attributes("Heure",render,"text",HEUREDEDEPART,NULL) ; 
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column); 

render=gtk_cell_renderer_text_new () ; 
column =gtk_tree_view_column_new_with_attributes("Compagnie",render,"text",COMPAGNIE,NULL) ; 
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column); 

render=gtk_cell_renderer_text_new () ; 
column =gtk_tree_view_column_new_with_attributes("Date d'aller",render,"text",DATEALLER,NULL) ; 
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column); 

render=gtk_cell_renderer_text_new () ; 
column =gtk_tree_view_column_new_with_attributes("Date de retour",render,"text",DATERETOUR,NULL) ; 
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column); 

store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING) ; 

f=fopen("/home/ggmghoul/Desktop/agency-master/src/voldispo.txt","r") ; 
if (f==NULL) 
{
return ; 
}
else 
{
f=fopen("/home/ggmghoul/Desktop/agency-master/src/voldispo.txt","a+") ;
 while(fscanf(f," %s %s %s %s %s %s \n" ,depart,destination,heure,compagnie,da,dr)!=EOF) 
{
gtk_list_store_append (store,&iter) ; 
gtk_list_store_set (store,&iter,DEPART,depart,DESTINATION,destination,HEUREDEDEPART,heure,COMPAGNIE,compagnie,DATEALLER,da,DATERETOUR,dr,-1) ; 
}
fclose(f) ; 
gtk_tree_view_set_model(GTK_TREE_VIEW (liste),GTK_TREE_MODEL (store)); 
g_object_unref (store) ; 
}
}
}*/

void ajouterhybergement (hyber h)
{
FILE *f;

f=fopen("/home/ggmghoul/Desktop/agency-master/src/hyberdispo.txt","a");
if(f!=NULL)
{fprintf(f,"%s %s %s \n",h.pays,h.hotel,h.prix);
fclose(f);
}
}
/*
void afficherhybergement (GtkTreeView *liste)
{
GtkCellRenderer *render ;
GtkTreeViewColumn *column ; 
GtkTreeIter iter ; 

GtkListStore *store ;

hyber h ; 


store=NULL ; 
FILE* f ; 

store=gtk_tree_view_get_model(liste) ; 
if (store==NULL) 
{
render=gtk_cell_renderer_text_new () ; 
column =gtk_tree_view_column_new_with_attributes("Pays",render,"text",PAYS,NULL) ; 
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column); 


render=gtk_cell_renderer_text_new () ; 
column =gtk_tree_view_column_new_with_attributes("Hotel",render,"text",HOTEL,NULL) ; 
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column); 


render=gtk_cell_renderer_text_new () ; 
column =gtk_tree_view_column_new_with_attributes("Prix",render,"text",PRIX,NULL) ; 
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column); 


store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING) ; 

f=fopen("/home/ggmghoul/Desktop/agency-master/src/hyberdispo.txt","r") ; 
if (f==NULL) 
{
return ; 
}
else 
{
f=fopen("/home/ggmghoul/Desktop/agency-master/src/hyberdispo.txt","a+") ;
 while(fscanf(f," %s %s %s \n" ,h.pays,h.hotel,h.prix)!=EOF) 
{
gtk_list_store_append (store,&iter) ; 
gtk_list_store_set (store,&iter,PAYS,h.pays,HOTEL,h.hotel,PRIX,h.prix,-1) ; 
}
fclose(f) ; 
gtk_tree_view_set_model(GTK_TREE_VIEW (liste),GTK_TREE_MODEL (store)); 
g_object_unref (store) ; 
}
}
}
*/

void ajouterlocation (loc l)
{
FILE *f;

f=fopen("/home/ggmghoul/Desktop/agency-master/src/locdispo.txt","a");
if(f!=NULL)
{fprintf(f,"%s %s \n",l.marque,l.prix);
fclose(f);
}
}
/*
int departdestdispo (char depart[][30] ,char destination[][30]) 
{
FILE *f ;
int n=0, i ; 
char depart1[30] ;
char destination1[30] ;
char heurededepart1[30] ;
char compagnie1[30] ;
char datealler1[30] ;
char dateretour1[30];


f=fopen("/home/ggmghoul/Desktop/agency-master/src/voldispo.txt","r");
if(f!=NULL)
{
while(fscanf(f,"%s %s %s %s %s %s",depart1,destination1,heurededepart1,compagnie1,datealler1,dateretour1)!=EOF)
{ 
n++ ; 
}
while(fscanf(f,"%s %s %s %s %s %s",depart1,destination1,heurededepart1,compagnie1,datealler1,dateretour1)!=EOF)
{ 
 for (i=0 ;i<n ;i++) 
    {
        strcpy(depart[i],depart1) ; 
        strcpy(destination[i],destination1) ;
    }
}
}
fclose(f) ; 
return n ; 

}*/
