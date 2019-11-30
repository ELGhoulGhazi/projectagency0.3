#include <gtk/gtk.h>

typedef struct
{
char nom[50]; 
char prenom[50] ;
char cin[50] ;
char user[50] ;
char password[50];
}client; 

typedef struct 
{
char nom[50] ;
char prenom[50] ;
int j ;
int m;
int y ;
char user[50] ;
char password[50];
}emp ;

void inscri (client c) ;


void ajouteremployer (emp e); 
void afficheremp (GtkTreeView *liste) ; 
void afficherclient (GtkTreeView *liste) ;
void affichervol (GtkTreeView *liste);
void afficherhyber (GtkTreeView *liste); 
void afficherloc (GtkTreeView *liste);  
//void supprimeremployer(); 
//void modifieremployer (); 
//void supprimerclient () ; 
//void modifierclient () ;  
