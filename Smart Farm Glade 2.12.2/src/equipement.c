#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "equipement.h"
#include <gtk/gtk.h>

enum
{
	IDENTIFIANTEQ,
	TYPEEQ,
	DATEEQ,
	ETAT,
	STATUS,
	COLUMNS
	
};

//ajouter un equipement
void ajouter_equipement(Equipement e)
{

FILE *f;
f=fopen("equipements.txt","a+");
if (f!=NULL)
{
fprintf(f,"%s %s %s %s %s \n",e.IDequipement, e.Typeequipement, e.Dateequipement, e.Etatequipement, e.Statusequipement);
fclose(f);
}
}
//afficher les equipements
void afficher_equipement(GtkWidget *liste)
{

	GtkCellRenderer *renderer; //afficher la cellule(cellule contient un texte, image, case a cocher
	GtkTreeViewColumn *column; //visualisation des colonnes
	GtkTreeIter iter; //c'est l'ensemble des elements de notre treeview
	GtkListStore *store;// créartion du modèle de type liste
	char ideq[20];
	char typeeq[20];
	char dateeq[20];
	char etat[20];
	char status[20];
	
	store=NULL;

FILE *f;

store=gtk_tree_view_get_model(liste);

if (store==NULL)
{
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("IDequipement",renderer,"text",IDENTIFIANTEQ,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Typeequipement",renderer,"text",TYPEEQ,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Dateequipement",renderer,"text",DATEEQ,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Etatequipement",renderer,"text",ETAT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Statusequipement",renderer,"text",STATUS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);}

f=fopen("equipements.txt","r");
if (f==NULL)
{	
	return;
}
else {
f=fopen("equipements.txt","a+");
while(fscanf(f,"%s %s %s %s %s \n",ideq,typeeq,dateeq,etat,status)!=EOF)
{
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,IDENTIFIANTEQ,ideq,TYPEEQ,typeeq,DATEEQ,dateeq,ETAT,etat,STATUS,status,-1);
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref (store);
}
}
//supprimer un equipement
void supprimer_equipement(Equipement e)
{
	char ideq[20];
	char typeeq[20];
	char dateeq[20];
	char etat[20];
	char status[20];


FILE *f,*g;
f=fopen("equipements.txt","r");
g=fopen("equipements2.txt","w");
if(f==NULL || g==NULL)
{
	return;
}
else{
while(fscanf(f,"%s %s %s %s %s \n",ideq,typeeq,dateeq,etat,status)!=EOF)
{
if (strcmp(e.IDequipement,ideq)!=0||strcmp(e.Typeequipement,typeeq)!=0||strcmp(e.Dateequipement,dateeq)!=0||strcmp(e.Etatequipement,etat)!=0||strcmp(e.Statusequipement,status)!=0)
fprintf(g,"%s %s %s %s %s ",ideq,typeeq,dateeq,etat,status);
}
fclose(f);
fclose(g);
remove("equipements.txt");
rename("equipements2.txt","equipements.txt");
}
}


//Chercher un equipement
int Chercher_equipement (char Id[])

{
int trouveequipement=-1;
FILE *f=NULL;

	char chideq[20];
	char chtypeeq[20];
	char chdateeq[20];
	char chetat[20];
	char chstatus[20];



f=fopen("equipements.txt","r");
if(f!=NULL)
{
while(fscanf(f,"%s %s %s %s %s \n",chideq,chtypeeq,chdateeq,chetat,chstatus)!=EOF)
{
if (strcmp(chideq,Id)==0)
{
trouveequipement=1;
//printf("%s %s %s %s %s",chideq,chtypeeq,chdateeq,chetat,chstatus);
}
}
fclose(f);
}
return (trouveequipement);
}



//supprimer un equipement
void Supprimer_equipement(char Id[])
{
	char chideq[20];
	char chtypeeq[20];
	char chdateeq[20];
	char chetat[20];
	char chstatus[20];
FILE *f=NULL;
FILE *p=NULL;

f=fopen("equipements.txt","r");
p=fopen("temp.txt","a+");
if(f!=NULL)
{
while(fscanf(f,"%s %s %s %s %s \n",chideq,chtypeeq,chdateeq,chetat,chstatus)!=EOF)
{
if (strcmp(chideq,Id)!=0) 
fprintf(p,"%s %s %s %s %s \n",chideq,chtypeeq,chdateeq,chetat,chstatus);

}
fclose(f);
fclose(p);
}
remove("equipements.txt");
rename("temp.txt","equipements.txt");
}
//Modifer un equipement

void modifier_equipement(char Id[])
{
	char chideq[20];
	char chtypeeq[20];
	char chdateeq[20];
	char chetat[20];
	char chstatus[20];
FILE *f=NULL;
FILE *p=NULL;

f=fopen("equipements.txt","r");
p=fopen("temp.txt","w");
if(f!=NULL)
{
while(fscanf(f,"%s %s %s %s %s \n",chtypeeq,chdateeq,chetat,chstatus,chideq)!=EOF)
{
if (strcmp(chideq,Id)==0)
{ 
printf("Nouveau Typeeq: ");
scanf("%s",chtypeeq);
printf("Nouveau Dateeq: ");
scanf("%s",chdateeq);
printf("Nouveau Etat: ");
scanf("%s",chetat);
printf("Nouveau Status: ");
scanf("%s",chstatus);
printf("Nouveau IDeq: ");
scanf("%s",chideq);
fprintf(p,"%s %s %s %s %s \n",chtypeeq,chdateeq,chetat,chstatus,chideq);
}
else
fprintf(p,"%s %s %s %s %s \n",chtypeeq,chdateeq,chetat,chstatus,chideq);
}
fclose(f);
fclose(p);
}
remove("equipements.txt");
rename("temp.txt","equipements.txt");

}

