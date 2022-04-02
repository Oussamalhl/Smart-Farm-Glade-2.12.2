#include<gtk/gtk.h>



typedef struct {
char Nomouvrier[20],Numeroouvrier[20],Emailouvrier[20];
char CINouvrier[20], Sexeouvrier[20];
}ouvrier;




void ajouter_ouvrier (ouvrier o);
void afficher_ouvrier(GtkWidget *liste);
void supprimer_ouvrier(ouvrier o);


int Chercher_ouvrier(char Cin[]);
int Chercher_ouvrier2 (int Id);//utiliser dans la tache 2

void Ajouter_ouvrier (ouvrier *O);

void Supprimer_ouvrier(char Cin[]);

void Modifier_ouvrier(char Cin[]); 

void afficher_ouvrier();

void modifier_ouvrier(char Cin[]);

