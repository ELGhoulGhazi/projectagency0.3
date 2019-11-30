#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif


#include <gtk/gtk.h>

#include <stdio.h> 
#include<string.h>
#include<stdlib.h>

#include <gtk/gtkclist.h>
//#include <gtk/gdkkeysyms.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "verifier.h"
#include "ajouter.h"
#include "reservation.h"


 
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

GtkWidget *Admin ,*GClients,*treeview ;

Admin=lookup_widget(objet_graphique,"ModeAdmin");
GClients=create_GestionAClient(); 
gtk_widget_show(GClients);
gtk_widget_hide(Admin);

treeview=lookup_widget(GClients,"treeviewAclient");
afficherclient(treeview) ; 

}



void
on_buttonAGE_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Admin ,*GEmp,*treeview ; 

Admin=lookup_widget(objet_graphique,"ModeAdmin");
GEmp=create_GestionAEmployes(); 
gtk_widget_show(GEmp);
gtk_widget_hide(Admin); 

treeview=lookup_widget(GEmp,"treeviewemp");
afficheremp(treeview) ; 
}


void
on_ggbuttonLogin_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
FILE *f;
int role;
int c ; 
cverif v ; 

GtkWidget *Home ,*Admin ,*Employe ,*Client ; 

GtkWidget *input,*input1,*output; 

input=lookup_widget(objet_graphique,"ggenetryUser");
input1=lookup_widget(objet_graphique,"ggentryPass");
Home=lookup_widget(objet_graphique,"Home");

strcpy(v.user,gtk_entry_get_text(GTK_ENTRY(input)));
strcpy(v.password,gtk_entry_get_text(GTK_ENTRY(input1)));
output=lookup_widget(objet_graphique,"labelwrong");
c=verifier(v);

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

client c ; 

GtkWidget *inputuser,*inputpass ,*inputnom ,*inputprenom ,*inputcin ;  


inputnom=lookup_widget(objet_graphique,"entryinscrinom"); 
inputprenom=lookup_widget(objet_graphique,"entryinscriprenom");
inputcin=lookup_widget(objet_graphique,"entryinscricin"); 
inputuser=lookup_widget(objet_graphique,"entryinscriptionuser");
inputpass=lookup_widget(objet_graphique,"entryinscriptionpass");
inscription=lookup_widget(objet_graphique,"Inscription");

strcpy(c.nom,gtk_entry_get_text(GTK_ENTRY(inputnom)));
strcpy(c.prenom,gtk_entry_get_text(GTK_ENTRY(inputprenom)));
strcpy(c.cin,gtk_entry_get_text(GTK_ENTRY(inputcin)));
strcpy(c.user,gtk_entry_get_text(GTK_ENTRY(inputuser)));
strcpy(c.password,gtk_entry_get_text(GTK_ENTRY(inputpass)));

inscri(c);
inscription=lookup_widget(objet_graphique,"Inscription");
Home=create_Home(); 
gtk_widget_show(Home);
gtk_widget_hide(inscription);



}


void
on_buttonEGC_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *GestionClient ,*Emp ,*treeview;

Emp=lookup_widget(objet_graphique,"ModeEmploye");
GestionClient=create_GestionEClient();
gtk_widget_show(GestionClient);
gtk_widget_hide(Emp);

treeview=lookup_widget(GestionClient,"treeviewEclient");
afficherclient(treeview) ; 
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


void
on_buttonretourajoutadmin_clicked      (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *ajoutemp ,*Gemp,*treeview;

ajoutemp=lookup_widget(objet_graphique,"ajouteremp");
Gemp=create_GestionAEmployes();
gtk_widget_show(Gemp);
gtk_widget_hide(ajoutemp);


treeview=lookup_widget(Gemp,"treeviewemp");
afficheremp(treeview) ; 


}


void
on_buttonvaliderajouteremploye_clicked (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *ajoutemp ,*Gemp;

FILE *f;

emp e ; 

GtkWidget *inputuser,*inputpass ,*inputnom ,*inputprenom ,*inputj,*inputm,*inputy ,*treeview ;  


inputnom=lookup_widget(objet_graphique,"entrynomemp"); 
inputprenom=lookup_widget(objet_graphique,"entryprenomemp");
inputj=lookup_widget(objet_graphique,"jour"); 
inputm=lookup_widget(objet_graphique,"mois"); 
inputy=lookup_widget(objet_graphique,"years"); 
inputuser=lookup_widget(objet_graphique,"entryuseremp");
inputpass=lookup_widget(objet_graphique,"entrypassemp");
ajoutemp=lookup_widget(objet_graphique,"ajouteremp");


strcpy(e.nom,gtk_entry_get_text(GTK_ENTRY(inputnom)));
strcpy(e.prenom,gtk_entry_get_text(GTK_ENTRY(inputprenom)));
e.j=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(inputj));
e.m=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(inputm));
e.y=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(inputy));

strcpy(e.user,gtk_entry_get_text(GTK_ENTRY(inputuser)));
strcpy(e.password,gtk_entry_get_text(GTK_ENTRY(inputpass)));

ajouteremployer(e);


Gemp=create_GestionAEmployes();
gtk_widget_show(Gemp);
gtk_widget_hide(ajoutemp);

treeview=lookup_widget(Gemp,"treeviewemp");
afficheremp(treeview) ; 
}


void
on_buttonCVols_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
int i ,n ; 
char depart[30][30] ;
char destination[30][30]; 


GtkWidget *vol ,*Client; //, *comboboxdepart ,*comboboxdestination ;

Client=lookup_widget(objet_graphique,"ModeClient");
vol=create_Vols();
gtk_widget_show(vol);
gtk_widget_hide(Client);
/*
comboboxdepart=lookup_widget(objet_graphique,"comboboxentrydepart");
comboboxdestination=lookup_widget(objet_graphique,"comboboxentrydestination");


n=departdestdispo(depart,destination);  
for(i=0 ;i<n ;i++) 
{
gtk_combo_box_append_text (GTK_COMBO_BOX (comboboxdepart),depart[i]) ;
gtk_combo_box_append_text (GTK_COMBO_BOX (comboboxdestination),destination[i]) ;
}*/

}


void
on_buttonCLocation_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *loc ,*Client;

Client=lookup_widget(objet_graphique,"ModeClient");
loc=create_Location();
gtk_widget_show(loc);
gtk_widget_hide(Client);
}


void
on_buttonCHyber_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *hyber ,*Client;

Client=lookup_widget(objet_graphique,"ModeClient");
hyber=create_Hybergement();
gtk_widget_show(hyber);
gtk_widget_hide(Client);
}

void
on_buttonretourVC_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *vol ,*Client;

vol=lookup_widget(objet_graphique,"Vols");
Client=create_ModeClient();
gtk_widget_show(Client);
gtk_widget_hide(vol);
}




void
on_buttonretourHC_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *hyber ,*Client;

hyber=lookup_widget(objet_graphique,"Hybergement");
Client=create_ModeClient();
gtk_widget_show(Client);
gtk_widget_hide(hyber);
}


void
on_buttonretourLC_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *loc ,*Client;

loc=lookup_widget(objet_graphique,"Location");
Client=create_ModeClient();
gtk_widget_show(Client);
gtk_widget_hide(loc);
}


void
on_buttonEvols_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *evol ,*pres ,*treeview;

pres=lookup_widget(objet_graphique,"Prestations");
evol=create_VolsE();
gtk_widget_show(evol);
gtk_widget_hide(pres);

//treeview=lookup_widget(evol,"treeviewvol");
//affichervol(treeview) ; 



}


void
on_buttonELocation_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *eloc ,*pres;

pres=lookup_widget(objet_graphique,"Prestations");
eloc=create_LocationE();
gtk_widget_show(eloc);
gtk_widget_hide(pres);
}


void
on_buttonEHyber_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *ehyber ,*pres;

pres=lookup_widget(objet_graphique,"Prestations");
ehyber=create_HybergementE();
gtk_widget_show(ehyber);
gtk_widget_hide(pres);

}


void
on_buttonretourVP_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *evol ,*pres;

evol=lookup_widget(objet_graphique,"VolsE");
pres=create_Prestations();
gtk_widget_show(pres);
gtk_widget_hide(evol);

}


void
on_buttonretourHP_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *ehyber ,*pres;

ehyber=lookup_widget(objet_graphique,"HybergementE");
pres=create_Prestations();
gtk_widget_show(pres);
gtk_widget_hide(ehyber);

}


void
on_buttonretourLP_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *eloc ,*pres;

eloc=lookup_widget(objet_graphique,"LocationE");
pres=create_Prestations();
gtk_widget_show(pres);
gtk_widget_hide(eloc);

}


void
on_buttonmsgA_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *message ,*admin;

admin=lookup_widget(objet_graphique,"ModeAdmin");
message=create_message();
gtk_widget_show(message);
gtk_widget_hide(admin);
}


void
on_buttonrecA_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *rec ,*admin;

admin=lookup_widget(objet_graphique,"ModeAdmin");
rec=create_reclamation();
gtk_widget_show(rec);
gtk_widget_hide(admin);
}


void
on_buttonmsgE_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *message ,*emp;

emp=lookup_widget(objet_graphique,"ModeEmploye");
message=create_messageE();
gtk_widget_show(message);
gtk_widget_hide(emp);
}


void
on_buttonrecE_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *rec ,*emp;

emp=lookup_widget(objet_graphique,"ModeEmploye");
rec=create_reclamationE();
gtk_widget_show(rec);
gtk_widget_hide(emp);
}


void
on_buttonrecC_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *rec ,*client;

client=lookup_widget(objet_graphique,"ModeClient");
rec=create_reclamer();
gtk_widget_show(rec);
gtk_widget_hide(client);
}


void
on_buttonmsgC_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *contact ,*client;

client=lookup_widget(objet_graphique,"ModeClient");
contact=create_contacter();
gtk_widget_show(contact);
gtk_widget_hide(client);
}


void
on_buttonretourmsg_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *message ,*admin;

message=lookup_widget(objet_graphique,"message");
admin=create_ModeAdmin();
gtk_widget_show(admin);
gtk_widget_hide(message);
}


void
on_buttonretourrec_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *rec ,*admin;

rec=lookup_widget(objet_graphique,"reclamation");
admin=create_ModeAdmin();
gtk_widget_show(admin);
gtk_widget_hide(rec);

}


void
on_buttonretourCC_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *contact ,*client;

contact=lookup_widget(objet_graphique,"contacter");
client=create_ModeClient();
gtk_widget_show(client);
gtk_widget_hide(contact);
}


void
on_buttonretourRC_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *rec ,*client;

rec=lookup_widget(objet_graphique,"reclamer");
client=create_ModeClient();
gtk_widget_show(client);
gtk_widget_hide(rec);

}


void
on_buttonretourME_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *message ,*emp;

message=lookup_widget(objet_graphique,"messageE");
emp=create_ModeEmploye();
gtk_widget_show(emp);
gtk_widget_hide(message);
}


void
on_buttonretourRE_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *rec ,*emp;

rec=lookup_widget(objet_graphique,"reclamationE");
emp=create_ModeEmploye();
gtk_widget_show(emp);
gtk_widget_hide(rec);
}


void
on_buttonretourLV_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *locv ,*visiteur;

locv=lookup_widget(objet_graphique,"Locationvisiteur");
visiteur=create_ModeVisiteur();
gtk_widget_show(visiteur);
gtk_widget_hide(locv);

}


void
on_buttonconnecterVL_clicked           (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Home ,*locv ;

locv=lookup_widget(objet_graphique,"Locationvisiteur");
Home=create_Home(); 
gtk_widget_show(Home);
gtk_widget_hide(locv);
}


void
on_buttoninscriVL_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *inscri ,*locv ;

locv=lookup_widget(objet_graphique,"Locationvisiteur");
inscri=create_Inscription(); 
gtk_widget_show(inscri);
gtk_widget_hide(locv);

}


void
on_buttonhyberV_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *hyberv ,*visiteur;

visiteur=lookup_widget(objet_graphique,"ModeVisiteur");
hyberv=create_Hybergementvisiteur();
gtk_widget_show(hyberv);
gtk_widget_hide(visiteur);
}


void
on_buttonlocationV_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *locv ,*visiteur;

visiteur=lookup_widget(objet_graphique,"ModeVisiteur");
locv=create_Locationvisiteur();
gtk_widget_show(locv);
gtk_widget_hide(visiteur);
}


void
on_buttonvolsV_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *volv ,*visiteur;

visiteur=lookup_widget(objet_graphique,"ModeVisiteur");
volv=create_Volsvisiteur();
gtk_widget_show(volv);
gtk_widget_hide(visiteur);
}


void
on_buttonconnecterVV_clicked           (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Home ,*volv ;

volv=lookup_widget(objet_graphique,"Volsvisiteur");
Home=create_Home(); 
gtk_widget_show(Home);
gtk_widget_hide(volv);

}


void
on_buttoninscriVV_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *inscri ,*volv ;

volv=lookup_widget(objet_graphique,"Volsvisiteur");
inscri=create_Inscription(); 
gtk_widget_show(inscri);
gtk_widget_hide(volv);

}


void
on_buttonretourVV_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *volv ,*visiteur;

volv=lookup_widget(objet_graphique,"Volsvisiteur");
visiteur=create_ModeVisiteur();
gtk_widget_show(visiteur);
gtk_widget_hide(volv);
}


void
on_buttoninscriVH_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *inscri ,*hyberv ;

hyberv=lookup_widget(objet_graphique,"Hybergementvisiteur");
inscri=create_Inscription(); 
gtk_widget_show(inscri);
gtk_widget_hide(hyberv);

}


void
on_buttonconnecterVH_clicked           (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Home ,*hyberv ;

hyberv=lookup_widget(objet_graphique,"Hybergementvisiteur");
Home=create_Home(); 
gtk_widget_show(Home);
gtk_widget_hide(hyberv);

}


void
on_buttonretourHV_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *hyberv ,*visiteur;

hyberv=lookup_widget(objet_graphique,"Hybergementvisiteur");
visiteur=create_ModeVisiteur();
gtk_widget_show(visiteur);
gtk_widget_hide(hyberv);
}

void
on_buttonvalidervol_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

}


void
on_buttonrecherchevol_clicked          (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *comboboxdepart ,*comboboxdestination ,*combocompagnie , *comboheure ,*comboda ,*combodr; 
char depart[30] ;
char destination[30] ;
char compagnie[50][50] ;
char heure[50][50] ;
char da[50][50] ;
char dr[50][50] ; 
char prix[30]; 
int n,i; 
comboboxdepart=lookup_widget(objet_graphique,"comboboxentrydepart");
comboboxdestination=lookup_widget(objet_graphique,"comboboxentrydestination");
comboheure=lookup_widget(objet_graphique,"comboboxheuredepart");
combocompagnie=lookup_widget(objet_graphique,"comboboxcompagnie");
comboda=lookup_widget(objet_graphique,"comboboxdateA");
combodr=lookup_widget(objet_graphique,"comboboxdateR");

strcpy(depart,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxdepart)));
strcpy(destination,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxdestination)));

n=verifierdest(depart,destination,heure,compagnie,da,dr,prix);
 if (n!=0) 
  {
    for (i=0 ;i<n ;i++)
       {
         gtk_combo_box_append_text (GTK_COMBO_BOX (comboheure),_(heure[i]));
         gtk_combo_box_append_text (GTK_COMBO_BOX (combocompagnie),_(compagnie[i]));
         gtk_combo_box_append_text (GTK_COMBO_BOX (comboda),_(da[i]));
         gtk_combo_box_append_text (GTK_COMBO_BOX (combodr),_(dr[i]));
       }
  }

}


void
on_buttonajoutvol_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *vole ,*ajoutvol ;

vole=lookup_widget(objet_graphique,"VolsE");
ajoutvol=create_ajoutervol(); 
gtk_widget_show(ajoutvol);
gtk_widget_hide(vole);
}


void
on_buttonvaliderajoutvol_clicked       (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *ajoutvol ,*vole;

FILE *f;

char depart[30] ;
char destination[30];
char heurededepart[30] ;
char compagnie[30];
char datealler[30];
char dateretour[30];
char prix[30];

GtkWidget *inputdepart,*inputdesti ,*inputheure ,*inputddepart ,*inpudretour,*inputprix, *inputcomp ;  


inputdepart=lookup_widget(objet_graphique,"entrydepart"); 
inputdesti=lookup_widget(objet_graphique,"entrydesti");
inputheure=lookup_widget(objet_graphique,"entryheure"); 
inputcomp=lookup_widget(objet_graphique,"entrycomp"); 
inputddepart=lookup_widget(objet_graphique,"entrydatealler"); 
inpudretour=lookup_widget(objet_graphique,"entrydateretour");
inputprix=lookup_widget(objet_graphique,"entryprix");

ajoutvol=lookup_widget(objet_graphique,"ajoutervol");


strcpy(depart,gtk_entry_get_text(GTK_ENTRY(inputdepart)));
strcpy(destination,gtk_entry_get_text(GTK_ENTRY(inputdesti)));
strcpy(heurededepart,gtk_entry_get_text(GTK_ENTRY(inputheure)));
strcpy(compagnie,gtk_entry_get_text(GTK_ENTRY(inputcomp)));
strcpy(datealler,gtk_entry_get_text(GTK_ENTRY(inputddepart)));
strcpy(dateretour,gtk_entry_get_text(GTK_ENTRY(inpudretour)));
strcpy(prix,gtk_entry_get_text(GTK_ENTRY(inputprix)));

ajoutervol(depart,destination,heurededepart,compagnie,datealler,dateretour,prix);


vole=create_VolsE();
gtk_widget_show(vole);
gtk_widget_hide(ajoutvol);

}



void
on_buttonretourajoutvolgvol_clicked    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *vole ,*ajoutvol ;

ajoutvol=lookup_widget(objet_graphique,"ajoutervol");
vole=create_VolsE(); 
gtk_widget_show(vole);
gtk_widget_hide(ajoutvol);
}


void
on_buttonajouthyber_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *hyber ,*ajouthyber ;

hyber=lookup_widget(objet_graphique,"HybergementE");
ajouthyber=create_ajouterhyber(); 
gtk_widget_show(ajouthyber);
gtk_widget_hide(hyber);
}




void
on_buttonajoutlocation_clicked         (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *loc ,*ajoutloc ;

loc=lookup_widget(objet_graphique,"LocationE");
ajoutloc=create_ajouterloc(); 
gtk_widget_show(ajoutloc);
gtk_widget_hide(loc);
}




void
on_buttonretourajouthyberhyber_clicked (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *hyber ,*ajouthyber ;

ajouthyber=lookup_widget(objet_graphique,"ajouterhyber");
hyber=create_HybergementE(); 
gtk_widget_show(hyber);
gtk_widget_hide(ajouthyber);
}


void
on_buttonvaliderhyber_clicked          (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *ajouthyber ,*hyberg;

FILE *f;

hyber h ;

GtkWidget *inputpays,*inputhotel ,*inputprix ;  


inputpays=lookup_widget(objet_graphique,"comboboxentrypayshyber"); 
inputhotel=lookup_widget(objet_graphique,"entryajouthotel");
inputprix=lookup_widget(objet_graphique,"entryajoutprixhyber"); 

ajouthyber=lookup_widget(objet_graphique,"ajouterhyber");

strcpy(h.pays,gtk_combo_box_get_active_text(GTK_COMBO_BOX(inputpays)));
strcpy(h.hotel,gtk_entry_get_text(GTK_ENTRY(inputhotel)));
strcpy(h.prix,gtk_entry_get_text(GTK_ENTRY(inputprix)));


ajouterhybergement(h);


hyberg=create_HybergementE();
gtk_widget_show(hyberg);
gtk_widget_hide(ajouthyber);

}


void
on_buttonretourajoutlocloc_clicked     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *loc ,*ajoutloc ;

ajoutloc=lookup_widget(objet_graphique,"ajouterloc");
loc=create_LocationE(); 
gtk_widget_show(loc);
gtk_widget_hide(ajoutloc);
}


void
on_buttonvaliderlocajout_clicked       (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *ajoutloc ,*loca;

FILE *f;

loc l ; 

GtkWidget *inputmarq,*inputprix ;  


 
inputmarq=lookup_widget(objet_graphique,"entrymarque");
inputprix=lookup_widget(objet_graphique,"entryprixloc"); 

ajoutloc=lookup_widget(objet_graphique,"ajouterloc");

strcpy(l.marque,gtk_entry_get_text(GTK_ENTRY(inputmarq)));
strcpy(l.prix,gtk_entry_get_text(GTK_ENTRY(inputprix)));


ajouterlocation(l);


loca=create_LocationE();
gtk_widget_show(loca);
gtk_widget_hide(ajoutloc);

}

