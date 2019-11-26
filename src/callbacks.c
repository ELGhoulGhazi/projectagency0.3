#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif


#include <gtk/gtk.h>

#include <stdio.h> 
#include<string.h>
#include<stdlib.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "verifier.h"
#include "ajouter.h"


 
void
on_ggbuttonVisiteur_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

GtkWidget *Home ,*Visiteur ;

Home=lookup_widget(objet_graphique,"Home");
Visiteur=create_ModeVisiteur();
gtk_widget_show(Visiteur);
gtk_widget_hide(Home);
}


 
void
on_buttonConnect_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data) 
{
GtkWidget *Home ,*Visiteur ;

Visiteur=lookup_widget(objet_graphique,"ModeVisiteur");
Home=create_Home(); 
gtk_widget_show(Home);
gtk_widget_hide(Visiteur);
}


void
on_buttonInscriV_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

GtkWidget *inscription ,*Visiteur ;

Visiteur=lookup_widget(objet_graphique,"ModeVisiteur");
inscription=create_Inscription();
gtk_widget_show(inscription);
gtk_widget_hide(Visiteur);
}


 

void
on_buttonAGC_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

GtkWidget *Admin ,*GClients ;

Admin=lookup_widget(objet_graphique,"ModeAdmin");
GClients=create_GestionAClient(); 
gtk_widget_show(GClients);
gtk_widget_hide(Admin);

}



void
on_buttonAGE_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Admin ,*GEmp;

Admin=lookup_widget(objet_graphique,"ModeAdmin");
GEmp=create_GestionAEmployes(); 
gtk_widget_show(GEmp);
gtk_widget_hide(Admin);
}


void
on_ggbuttonLogin_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
FILE *f;
int role;
char user[100];
char password[100];
int c ; 

GtkWidget *Home ,*Admin ,*Employe ,*Client ; 

GtkWidget *input,*input1,*output; 

input=lookup_widget(objet_graphique,"ggenetryUser");
input1=lookup_widget(objet_graphique,"ggentryPass");
Home=lookup_widget(objet_graphique,"Home");

strcpy(user,gtk_entry_get_text(GTK_ENTRY(input)));
strcpy(password,gtk_entry_get_text(GTK_ENTRY(input1)));
output=lookup_widget(objet_graphique,"labelwrong");
c=verifier(user,password);

if (c==1)
{Admin=create_ModeAdmin();
gtk_widget_show(Admin);
gtk_widget_hide(Home);
}

else if (c==2)
{Employe=create_ModeEmploye();
gtk_widget_show(Employe);
gtk_widget_hide(Home);
}

else if (c==3)
{Client=create_ModeClient();
gtk_widget_show(Client);
gtk_widget_hide(Home);
}
else 
{
gtk_label_set_text(GTK_LABEL(output)," Unable to Connect ! ");
}
/*GtkWidget *Home ,*Visiteur ;

Home=lookup_widget(objet_graphique,"Home");
Visiteur=create_ModeVisiteur(); 
gtk_widget_show(Visiteur);
gtk_widget_hide(Home);*/
}





void
on_ggbuttonIinscription_clicked        (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Home ,*inscription; 

Home=lookup_widget(objet_graphique,"Home");
inscription=create_Inscription();
gtk_widget_show(inscription);
gtk_widget_hide(Home);
}




void
on_buttonDecoA_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Home ,*Admin;

Admin=lookup_widget(objet_graphique,"ModeAdmin");
Home=create_Home();
gtk_widget_show(Home);
gtk_widget_hide(Admin);
}




void
on_buttoninscriconnect_clicked         (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Home ,*inscription;

inscription=lookup_widget(objet_graphique,"Inscription");
Home=create_Home();
gtk_widget_show(Home);
gtk_widget_hide(inscription);
}



void
on_buttonACretour_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *GestionClient ,*Admin;

GestionClient=lookup_widget(objet_graphique,"GestionAClient");
Admin=create_ModeAdmin();
gtk_widget_show(Admin);
gtk_widget_hide(GestionClient);
}


void
on_buttonEAretour_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *GestionEmp ,*Admin;

GestionEmp=lookup_widget(objet_graphique,"GestionAEmployes");
Admin=create_ModeAdmin();
gtk_widget_show(Admin);
gtk_widget_hide(GestionEmp);
}

  
void
on_buttonValiderinscri_clicked         (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

GtkWidget *Home ,*inscription ;

FILE *f;

char user[20];
char password[20];
char nom[50];
char prenom[50];  
char CIN[20] ;

GtkWidget *inputuser,*inputpass ,*inputnom ,*inputprenom ,*inputcin ;  


inputnom=lookup_widget(objet_graphique,"entryinscrinom"); 
inputprenom=lookup_widget(objet_graphique,"entryinscriprenom");
inputcin=lookup_widget(objet_graphique,"entryinscricin"); 
inputuser=lookup_widget(objet_graphique,"entryinscriptionuser");
inputpass=lookup_widget(objet_graphique,"entryinscriptionpass");
inscription=lookup_widget(objet_graphique,"Inscription");

strcpy(nom,gtk_entry_get_text(GTK_ENTRY(inputnom)));
strcpy(prenom,gtk_entry_get_text(GTK_ENTRY(inputprenom)));
strcpy(CIN,gtk_entry_get_text(GTK_ENTRY(inputcin)));
strcpy(user,gtk_entry_get_text(GTK_ENTRY(inputuser)));
strcpy(password,gtk_entry_get_text(GTK_ENTRY(inputpass)));

inscri(nom,prenom,CIN,user,password);
inscription=lookup_widget(objet_graphique,"Inscription");
Home=create_Home(); 
gtk_widget_show(Home);
gtk_widget_hide(inscription);



}


void
on_buttonEGC_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *GestionClient ,*Emp;

Emp=lookup_widget(objet_graphique,"ModeEmploye");
GestionClient=create_GestionEClient();
gtk_widget_show(GestionClient);
gtk_widget_hide(Emp);
}


void
on_buttonEPrestations_clicked          (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Pres ,*Emp;

Emp=lookup_widget(objet_graphique,"ModeEmploye");
Pres=create_Prestations();
gtk_widget_show(Pres);
gtk_widget_hide(Emp);
}


void
on_buttonEGFactures_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Fact ,*Emp;

Emp=lookup_widget(objet_graphique,"ModeEmploye");
Fact=create_Factures();
gtk_widget_show(Fact);
gtk_widget_hide(Emp);
}




void
on_buttonretourCE_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *GestionClient ,*Emp;

GestionClient=lookup_widget(objet_graphique,"GestionEClient");
Emp=create_ModeEmploye();
gtk_widget_show(Emp);
gtk_widget_hide(GestionClient);
}


void
on_buttonretourPE_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Pres ,*Emp;

Pres=lookup_widget(objet_graphique,"Prestations");
Emp=create_ModeEmploye();
gtk_widget_show(Emp);
gtk_widget_hide(Pres);
}


void
on_buttonretourFE_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Fact ,*Emp;

Fact=lookup_widget(objet_graphique,"Factures");
Emp=create_ModeEmploye();
gtk_widget_show(Emp);
gtk_widget_hide(Fact);
}

void
on_buttonDecoEmp_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Home ,*Emp;

Emp=lookup_widget(objet_graphique,"ModeEmploye");
Home=create_Home();
gtk_widget_show(Home);
gtk_widget_hide(Emp);
}


void
on_buttondecoclient_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Home ,*Client;

Client=lookup_widget(objet_graphique,"ModeClient");
Home=create_Home();
gtk_widget_show(Home);
gtk_widget_hide(Client);
}


void
on_buttonAEMajouter_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *ajoutemp ,*Gemp;

Gemp=lookup_widget(objet_graphique,"GestionAEmployes");
ajoutemp=create_ajouteremp();
gtk_widget_show(ajoutemp);
gtk_widget_hide(Gemp);

}

