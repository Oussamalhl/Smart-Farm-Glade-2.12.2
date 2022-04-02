#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "client.h"
#include <gtk/gtk.h>

enum
{
	NOM,
	PRENOM,
	EMAIL,
	ID,
	NUMERO,
	COLUMNS
	
};

//ajouter un client
void ajouter_client(Client c)
{

FILE *f;
f=fopen("clients.txt","a+");
if (f!=NULL)
{
fprintf(f,"%s %s %s %s %s \n",c.Nomclient, c.Prenomclient, c.Emailclient, c.IDclient, c.Numeroclient);
fclose(f);
}
}
//afficher les clients
void afficher_client(GtkWidget *liste)
{

	GtkCellRenderer *renderer; //afficher la cellule(cellule contient un texte, image, case a cocher
	GtkTreeViewColumn *column; //visualisation des colonnes
	GtkTreeIter iter; //c'est l'ensemble des elements de notre treeview
	GtkListStore *store;// créartion du modèle de type liste
	char nom[20],prenom[20],email[20];
	char id[20], numero[20];
	
	store=NULL;

FILE *f;

store=gtk_tree_view_get_model(liste);

if (store==NULL)
{
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Nomclient",renderer,"text",NOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Prenomclient",renderer,"text",PRENOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Emailclient",renderer,"text",EMAIL,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("IDclient",renderer,"text",ID,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Numeroclient",renderer,"text",NUMERO,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new();

store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);}

f=fopen("clients.txt","r");
if (f==NULL)
{	
	return;
}
else {
f=fopen("clients.txt","a+");
while(fscanf(f,"%s %s %s %s %s \n",nom,prenom,email,id,numero)!=EOF)
{
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,NOM,nom,PRENOM,prenom,EMAIL,email,ID,id,NUMERO,numero,-1);
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref (store);
}
}
//supprimer un client
void supprimer_client(Client c)
{
	char nom[20],prenom[20],email[20];
	char id[20], numero[20];

FILE *f,*g;
f=fopen("clients.txt","r");
g=fopen("clients2.txt","w");
if(f==NULL || g==NULL)
{
	return;
}
else{
while(fscanf(f,"%s %s %s %s %s \n",nom,prenom,email,id,numero)!=EOF)
{
if (strcmp(c.Nomclient,nom)!=0||strcmp(c.Prenomclient,prenom)!=0||strcmp(c.Emailclient,email)!=0||strcmp(c.IDclient,id)!=0||strcmp(c.Numeroclient,numero)!=0)
fprintf(g,"%s %s %s %s %s",nom,prenom,email,id,numero);
}
fclose(f);
fclose(g);
remove("clients.txt");
rename("clients2.txt","clients.txt");
}
}


//Chercher un client
int Chercher_client (char Id[])

{
int trouveclient=-1;
FILE *f=NULL;
char chId[20], chNum[20];
char Rnom[20],Rprenom[20],Remail[20];



f=fopen("clients.txt","r");
if(f!=NULL)
{
while(fscanf(f,"%s %s %s %s %s \n",Rnom,Rprenom,Remail,chId,chNum)!=EOF)
{
if (strcmp(chId,Id)==0)
{
trouveclient=1;
//printf("%s %s %s %s %s",Rnom,Rprenom,Remail,chId,chNum);
}
}
fclose(f);
}
return (trouveclient);
}



//SUpprimer un client
void Supprimer_client(char Id[])
{
char chId[20], Rnum[20];
char Rnom[20],Rprenom[20],Remail[20];
FILE *f=NULL;
FILE *p=NULL;

f=fopen("clients.txt","r");
p=fopen("temp.txt","a+");
if(f!=NULL)
{
while(fscanf(f,"%s %s %s %s %s \n",Rnom,Rprenom,Remail,chId,Rnum)!=EOF)
{
if (strcmp(chId,Id)!=0) 
fprintf(p,"%s %s %s %s %s \n",Rnom,Rprenom,Remail,chId,Rnum);

}
fclose(f);
fclose(p);
}
remove("clients.txt");
rename("temp.txt","clients.txt");
}


//Modifer un client

void modifier_client(char Id[])
{
char chId[20], Rnum[20];
char Rnom[20],Rprenom[20],Remail[20];
FILE *f=NULL;
FILE *p=NULL;

f=fopen("clients.txt","r");
p=fopen("temp.txt","w");
if(f!=NULL)
{
while(fscanf(f,"%s %s %s %s %s \n",Rnom,Rprenom,Remail,chId,Rnum)!=EOF)
{
if (strcmp(chId,Id)==0)
{ 
printf("Nouveau Nom: ");
scanf("%s",Rnom);
printf("Nouveau Prenom: ");
scanf("%s",Rprenom);
printf("Nouveau Email: ");
scanf("%s",Remail);
printf("Nouveau Id: ");
scanf("%s",chId);
printf("Nouveau Numero: ");
scanf("%s",Rnum);
fprintf(p,"%s %s %s %s %s \n",Rnom,Rprenom,Remail,chId,Rnum);
}
else
fprintf(p,"%s %s %s %s %s \n",Rnom,Rprenom,Remail,chId,Rnum);
}
fclose(f);
fclose(p);
}
remove("clients.txt");
rename("temp.txt","clients.txt");

}



int tableau_modif_client_disponible(char id_modif[20][10])
{
FILE* f=fopen("clients.txt","r");


int nc=0;
char nom[20],prenom[20],email[20];
char id[20], numero[20];


if(f!=NULL)
{
while (fscanf(f,"%s %s %s %s %s ",nom,prenom,email,id,numero)!=EOF)
{
//strcat(id,nom);
//strcat(id,prenom);
strcpy(id_modif[nc],id);
nc++;
}
}

fclose(f);
return nc;
}


