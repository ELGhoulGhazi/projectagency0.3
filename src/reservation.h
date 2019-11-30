#include <gtk/gtk.h>


typedef struct 
{
char pays[50]; 
char hotel[50]; 
char prix[50]; 
}hyber; 

typedef struct 
{
char marque[50]; 
char prix[50];  
}loc; 


int verifierdest (char depart[] ,char destination[], char heurededepart[50][50] ,char compagnie[50][50],char datealler[50][50], char dateretour[50][50],char prix[]) ; 
void ajoutervol (char depart[] ,char destination[], char heurededepart[] ,char compagnie[],char datealler[], char dateretour[],char prix[]) ; 
void ajouterhybergement(hyber h); 
void ajouterlocation(loc l);

//void affichervol (GtkTreeView *liste);

//int departdestdispo (char depart[][30] ,char destination[][30]);
