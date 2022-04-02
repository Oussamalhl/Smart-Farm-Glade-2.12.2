#include<gtk/gtk.h>



typedef struct client{
char Nomclient[20],Prenomclient[20],Emailclient[20];
char IDclient[20], Numeroclient[20];
}Client;




void ajouter_client (Client c);
void afficher_client(GtkWidget *liste);
void supprimer_client(Client c);


int Chercher_client (char Id[]);

void Ajouter_client (Client *C);

void Supprimer_client(char Id[]);

void Modifier_client(char Id[]); 

void afficher_client();

void modifier_client(char Id[]);

int tableau_modif_client_disponible(char id_client[20][10]);

