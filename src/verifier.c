#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include"verifier.h"

int verifier(char user[],char password[])
{
FILE *f;
int role,a=1,b=1,c=-1 ; 
char user1[20] ; 
char password1[20] ; 
f=fopen("/home/ggmghoul/Desktop/agency-master/src/users.txt","r"); 
if (f!=NULL)
{
while(fscanf(f,"%s %s %d",user1, password1,&role)!=EOF)
{
a=strcmp(user,user1);
   b=strcmp(password,password1);
if (a==0 && b==0)
     c =role;
}
}
fclose(f);
return c;
}




