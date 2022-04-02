#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ouvrier.h"
#include <gtk/gtk.h>

enum
{
	NOM,
	NUMERO,
	EMAIL,
	CIN,
	SEXE,
	COLUMNS
	
};

//ajouter un ouvrier
void ajouter_ouvrier(ouvrier o)
{

FILE *f;
f=fopen("ouvriers.txt","a+");
if (f!=NULL)
{
fprintf(f,"%s %s %s %s %s \n",o.Nomouvrier, o.Numeroouvrier, o.Emailouvrier, o.CINouvrier, o.Sexeouvrier );
fclose(f);
}
}
//afficher les ouvriers
void afficher_ouvrier(GtkWidget *liste)
{

	GtkCellRenderer *renderer; //afficher la cellule(cellule contient un texte, image, case a cocher
	GtkTreeViewColumn *column; //visualisation des colonnes
	GtkTreeIter iter; //c'est l'ensemble des elements de notre treeview
	GtkListStore *store;// créartion du modèle de type liste
	char nom[20],numero[20],email[20];
	char cin[20], sexe[20];
	
	store=NULL;

FILE *f;

store=gtk_tree_view_get_model(liste);

if (store==NULL)
{
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Nomouvrier",renderer,"text",NOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Numeroouvrier",renderer,"text",NUMERO,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Emailouvrier",renderer,"text",EMAIL,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("CINouvrier",renderer,"text",CIN,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Sexeouvrier",renderer,"text",SEXE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new();

store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);}

f=fopen("ouvriers.txt","r");
if (f==NULL)
{	
	return;
}
else {
f=fopen("ouvriers.txt","a+");
while(fscanf(f,"%s %s %s %s %s \n",nom,numero,email,cin,sexe)!=EOF)
{
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,NOM,nom,NUMERO,numero,EMAIL,email,CIN,cin,SEXE,sexe,-1);
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref (store);
}
}
//supprimer un ouvrier
void supprimer_ouvrier(ouvrier o)
{
	char nom[20],numero[20],email[20];
	char cin[20],sexe[20];

FILE *f,*g;
f=fopen("ouvriers.txt","r");
g=fopen("ouvriers2.txt","w");
if(f==NULL || g==NULL)
{
	return;
}
else{
while(fscanf(f,"%s %s %s %s %s \n",nom,numero,email,cin,sexe)!=EOF)
{
if (strcmp(o.Nomouvrier,nom)!=0||strcmp(o.Numeroouvrier,numero)!=0||strcmp(o.Emailouvrier,email)!=0||strcmp(o.CINouvrier,cin)!=0||strcmp(o.Sexeouvrier,sexe)!=0)
fprintf(g,"%s %s %s %s %s",nom,numero,email,cin,sexe);
}
fclose(f);
fclose(g);
remove("ouvriers.txt");
rename("ouvriers2.txt","ouvriers.txt");
}
}


//Chercher un ouvrier
int Chercher_ouvrier (char Cin[])

{
int trouveouvrier=-1;
FILE *f=NULL;

	char chnom[20],chnumero[20],chemail[20];
	char chcin[20],chsexe[20];


f=fopen("ouvriers.txt","r");
if(f!=NULL)
{
while(fscanf(f,"%s %s %s %s %s \n",chnom,chnumero,chemail,chcin,chsexe)!=EOF)
{
if (strcmp(chcin,Cin)==0)
{
trouveouvrier=1;
//printf("%s %s %s %s %s",chnom,chnumero,chemail,chcin,chsexe);
}
}
fclose(f);
}
return (trouveouvrier);
}
//Modifier un ouvrier

                                       
void modifier_ouvrier(char Cin[])
{
	char chnom[20],chnumero[20],chemail[20];
	char chcin[20],chsexe[20];
FILE *f=NULL;
FILE *p=NULL;

f=fopen("ouvries.txt","r");
p=fopen("temp.txt","w");
if(f!=NULL)
{
while(fscanf(f,"%s %s %s %s %s \n",chnom,chnumero,chemail,chcin,chsexe)!=EOF)
{
if (strcmp(chcin,Cin)==0)
{ 
printf("Nouveau Nom: ");
scanf("%s",chnom);
printf("Nouveau Numero: ");
scanf("%s",chnumero);
printf("Nouveau Email: ");
scanf("%s",chemail);
printf("Nouveau Cin: ");
scanf("%s",chcin);
printf("Nouveau Sexe: ");
scanf("%s",chsexe);
fprintf(p,"%s %s %s %s %s \n",chnom,chnumero,chemail,chcin,chsexe);
}
else
fprintf(p,"%s %s %s %s %s \n",chnom,chnumero,chemail,chcin,chsexe);
}
fclose(f);
fclose(p);
}
remove("ouvriers.txt");
rename("temp.txt","ouvriers.txt");

}
                                      
                                            
//SUpprimer un ouvrier
void Supprimer_ouvrier(char Cin[])
{
	char chnom[20],chnumero[20],chemail[20];
	char chcin[20],chsexe[20];
FILE *f=NULL;
FILE *p=NULL;

f=fopen("ouvriers.txt","r");
p=fopen("temp.txt","a+");
if(f!=NULL)
{
while(fscanf(f,"%s %s %s %s %s \n",chnom,chnumero,chemail,chcin,chsexe)!=EOF)
{
if (strcmp(chcin,Cin)!=0) 
fprintf(p,"%s %s %s %s %s \n",chnom,chnumero,chemail,chcin,chsexe);

}
fclose(f);
fclose(p);
}
remove("ouvriers.txt");
rename("temp.txt","ouvriers.txt");
}
/*////////////////////////////////////////////////////////////////////////////////////////////*/
      
/*////////////////////////////////////////////////////////////////////////////////////////////*/
/*fonction chercher ouvrier avec id */
int Chercher_ouvrier2 (int Id)

{
int trouveouvrier=-1;
FILE *f=NULL;

	int id,jour,mois,annee,valeurs;


f=fopen("absenteisme.txt","r");
if(f!=NULL)
{
while(fscanf(f,"%d %d %d %d %d \n",id,jour,mois,annee,valeurs)!=EOF)
{
if (strcmp(id,Id)==0)
{
trouveouvrier=1;
//printf("%d %d %d %d %d",id,jour,mois,annee,valeurs);
}
}
fclose(f);
}
return (trouveouvrier);
}

