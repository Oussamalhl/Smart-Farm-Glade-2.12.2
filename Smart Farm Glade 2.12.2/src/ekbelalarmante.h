#include <gtk/gtk.h>

typedef struct
{
    int jour;
    int mois;
    int annee;
}Naissance;

typedef struct
{
    char id[20];
    Naissance date_naissance;
    char type[20];
    char valeur[20];
    char marque[20];
}Capteur;

void afficher_capteur_alarmant(GtkWidget *liste);
