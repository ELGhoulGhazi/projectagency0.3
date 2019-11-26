#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"ajouter.h"

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif


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


void ajouteremployer (char nom[], char prenom[] ,char date ,char user[] ,char password[])
{
FILE *f;
int role=2 ;
f=fopen("/home/ggmghoul/Desktop/agency-master/src/users.txt","a");
if(f!=NULL)
{fprintf(f,"%s %s %d \n",user,password,role);
fclose(f);
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
