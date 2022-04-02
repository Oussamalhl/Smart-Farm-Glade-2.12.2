#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"reservation.h"
#include <gtk/gtk.h>
/*
int tableau_Reservation_client(ReservationClient tab[])
{
int n=0;
FILE* f=fopen("clientsreserve.txt","r");
if (f!=NULL)
{
while(fscanf(f,"%s %s %s %s %d %d %d"),tab[n].IDclient,tab[n].Nomclient,tab[n].Prenomclient,tab[n].Numeroclient,tab[n].dt_resr.Jour,tab[n].dt_resr.Mois,tab[n].dt_resr.Annee!=EOF)
{n++;}
fclose(f);
}
return n;
}

verifier_reservation(ReservationClient cr)
{}
*/

int tableau_client_disponible(char rs[20][10])
{
FILE* f=fopen("clientsnonreserve.txt","r");
//if (f==NULL)f=fopen("clients.txt","r");


int nc=0;

char nom[20],prenom[20],email[20];
char id[20], numero[20];
if(f!=NULL)
{
while (fscanf(f,"%s %s %s %s %s",nom,prenom,email,id,numero)!=EOF)
{
//strcat(id,nom);
//strcat(id,prenom);
strcpy(rs[nc],id);
nc++;
}
}
fclose(f);
return nc;
}




void reservation_client (ReservationClient rc)
{
FILE* f=fopen("clientsreserve.txt","a");
//FILE* g=fopen("clientsnonreserve.txt","a");
FILE* h=fopen("clients.txt","r");
FILE* p=fopen("temp.txt","a+");

char nom[20],prenom[20],email[20];
char id[20], numero[20];

if(f!=NULL)
{fprintf(f,"%d %d %d %s %d\n",rc.dt_resr.jour,rc.dt_resr.mois,rc.dt_resr.annee,rc.IDclient,rc.hr_resr);

while (fscanf(h,"%s %s %s %s %s ",nom,prenom,email,id,numero)!=EOF)
{
if (strcmp(id,rc.IDclient)!=0)
{
fprintf(p,"%s %s %s %s %s\n",nom,prenom,email,id,numero);
}
}
}
remove("clientsnonreserve.txt");
rename("temp.txt","clientsnonreserve.txt");
fclose(f);
fclose(p);
fclose(h);

}
