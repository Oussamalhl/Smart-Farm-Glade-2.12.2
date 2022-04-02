#include<gtk/gtk.h>
typedef struct
{
int jour;
int mois;
int annee;
}DATE;


typedef struct
{
char type[20];
char identifiant[20];
char sexe[20];
DATE date;
}troupeaux;

void ajoutertroupeaux(troupeaux a);
void supprimertroupeaux(char identifiant []);
void affichagetroupeaux(GtkWidget *liste);
void affichagetroupeauxr(GtkWidget *liste);
void modifiertroupeaux(troupeaux a);
int rechercher_troupeaux(char identifiant[]);
void nbtoupeaux (int *c, int *p, int *v, int *m);
int remplirtab (troupeaux tab[],int nb);
void remlirfichier(troupeaux tab[],int nb);
troupeaux rechercher (char ID[]);
int rechercher_troupeauxl(char ID[]);

