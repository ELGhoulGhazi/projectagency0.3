#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"reservation.h"
#include <gtk/gtk.h>

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

int verifierdest (char depart[] ,char destination[], char heurededepart[][30] ,char compagnie[][30],char datealler[][30], char dateretour[][30] ) 
{
char depart1[30] ;
char destination1[30] ;
char heurededepart1[30] ;
char compagnie1[30] ;
char datealler1[30] ;
char dateretour1[30];

int a=1,b=1,c=0 ; 
int i ;

FILE *f ; 
f=fopen("/home/ggmghoul/Desktop/agency-master/src/voldispo.txt","r");
if(f!=NULL)
{
while(fscanf(f,"%s %s %s %s %s %s",depart1,destination1,heurededepart1,compagnie1,datealler1,dateretour1)!=EOF)
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
