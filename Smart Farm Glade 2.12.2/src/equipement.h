#include<gtk/gtk.h>



typedef struct equipement{
char IDequipement[20];
char Typeequipement[20];
char Dateequipement[20];
char Etatequipement[20];
char Statusequipement[20];
}Equipement;



int Chercher_equipement (char Id[]);
void Supprimer_equipement(char Id[]);
void Modifier_equipement(char Id[]);
void afficher_equipement(GtkWidget *liste);
void ajouter_equipement(Equipement e);
void modifier_equipement(char Id[]);

void Ajouter_equipement (Equipement *E);
void supprimer_equipement(Equipement e);
void afficher_equipement();

