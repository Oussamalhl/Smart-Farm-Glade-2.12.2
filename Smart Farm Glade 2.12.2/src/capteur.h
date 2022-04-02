#include<gtk/gtk.h>



typedef struct {
char id[30];
char type[30];
char marque[30];
char d_ajout[30];
}capteur;




void ajouter_capteur (capteur c);
void afficher_capteur(GtkWidget *liste);



int Chercher_capteur (char Id[]);
char chercher_capteur (char Id[]);
void supprimer_capteur(capteur c);
void Supprimer_client(char Id[]);

void Modifier_capteur(capteur c); 


