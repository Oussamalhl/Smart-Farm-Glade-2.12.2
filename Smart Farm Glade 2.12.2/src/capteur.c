#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "capteur.h"
#include <gtk/gtk.h>

enum
{
	ID,
	TYPE,
	MARQUE,
	D_AJOUT,
	COLUMNS
	
};

//ajouter un capteur
void ajouter_capteur(capteur c)
{

FILE *f;
f=fopen("capteurs.txt","a+");
if (f!=NULL)
{
fprintf(f,"%s %s %s %s \n",c.id, c.type, c.marque, c.d_ajout);
fclose(f);
}
}
//ajouter une valeur
void ajouter_valeur(char id[],int jj,int mm, int aa,char val[],char chemin[] )
{

FILE *f;
f=fopen(chemin,"a+");
if (f!=NULL)
{
fprintf(f,"%s %d %d %d %s \n ",id, jj,mm,aa,val);
fclose(f);
}
}
//afficher les capteurs
void afficher_capteur(GtkWidget *liste)
{

	GtkCellRenderer *renderer; //afficher la cellule(cellule contient un texte, image, case a cocher
	GtkTreeViewColumn *column; //visualisation des colonnes
	GtkTreeIter iter; //c'est l'ensemble des elements de notre treeview
	GtkListStore *store;// créartion du modèle de type liste
	char id[20],type[20],marque[20],d_ajout[20];

	
	store=NULL;

FILE *f;

store=gtk_tree_view_get_model(liste);

if (store==NULL)
{
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Id_Capteur",renderer,"text",ID,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Type_Capteur",renderer,"text",TYPE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Marque_Capteur",renderer,"text",MARQUE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Date_Ajout",renderer,"text",D_AJOUT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new();


store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);}

f=fopen("capteurs.txt","r");
if (f==NULL)
{	
	return;
}
else {
f=fopen("capteurs.txt","a+");
while(fscanf(f,"%s %s %s %s  \n",id,type,marque,d_ajout)!=EOF)
{
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,ID,id,TYPE,type,MARQUE,marque,D_AJOUT,d_ajout,-1);
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref (store);
}
}
//supprimer un capteur
void supprimer_capteur(capteur c)
{
	char id[20],type[20],marque[20],d_ajout[20];


FILE *f,*g;
f=fopen("capteurs.txt","r");
g=fopen("capteurs2.txt","w");
if(f==NULL || g==NULL)
{
	return;
}
else{
while(fscanf(f,"%s %s %s %s  \n",id,type,marque,d_ajout)!=EOF)
{
if (strcmp(c.id,id)!=0||strcmp(c.type,type)!=0||strcmp(c.marque,marque)!=0||strcmp(c.d_ajout,d_ajout)!=0)
fprintf(g,"%s %s %s %s \n",id,type,marque,d_ajout);
}
fclose(f);
fclose(g);
remove("capteurs.txt");
rename("capteurs2.txt","capteurs.txt");
}
}


//Chercher un capteur
int Chercher_capteur (char Id[])

{
int trouvecapteur=-1;
FILE *f=NULL;
char id[20],type[20],marque[20],d_ajout[20];



f=fopen("capteurs.txt","r");
if(f!=NULL)
{
while(fscanf(f,"%s %s %s %s \n", id,type,marque,d_ajout)!=EOF)
{
if (strcmp(id,Id)==0)
{
trouvecapteur=1;

}
}
fclose(f);
}
return (trouvecapteur);
}

/*char chercher_capteur (char Id[])

{
char text1[100]="";
FILE *f=NULL;
char id[20],type[20],marque[20],d_ajout[20];



f=fopen("capteurs.txt","r");
if(f!=NULL)
{
while(fscanf(f,"%s %s %s %s \n", id,type,marque,d_ajout)!=EOF)
{
if (strcmp(id,Id)==0)
{
sprintf(text1,"id=%s  type=%s  marque=%s  d_ajout=%s",id,type,marque,d_ajout);

}
}
fclose(f);
}
return (text1);
}*/

void Modifier_capteur(capteur c)
{
capteur c1;
char id[20],type[20],marque[20],d_ajout[20];
FILE *f;
FILE *tmp;
tmp=NULL;
f=fopen("capteurs.txt","r+");
tmp=fopen("tmp.txt","a+");
if (f!=NULL)
{
while (fscanf(f,"%s %s %s %s \n",c1.id,c1.type,c1.marque,c1.d_ajout)!=EOF)
 {if(strcmp(c.id,c1.id)==0) c1=c;
	
                fprintf(tmp,"%s %s %s %s \n",c1.id,c1.type,c1.marque,c1.d_ajout);
   
            }
    fclose(tmp);
    fclose(f);
	remove("capteurs.txt");
      rename("tmp.txt","capteurs.txt");
}
}

//SUpprimer un capteur
void Supprimer_capteur(char Id[])
{
char id[20],type[20],marque[20],d_ajout[20];
FILE *f=NULL;
FILE *p=NULL;

f=fopen("capteurs.txt","r");
p=fopen("tmp.txt","a+");
if(f!=NULL)
{
while(fscanf(f,"%s %s %s %s  \n",id,type,marque,d_ajout)!=EOF)
{
if (strcmp(id,Id)!=0) 
fprintf(p,"%s %s %s %s  \n",id,type,marque,d_ajout);

}
fclose(f);
fclose(p);
}
remove("capteurs.txt");
rename("tmp.txt","capteurs.txt");
}

void defectueux(char chemin[],char *h){
FILE *f;

 int a,b,c,d1,i,max;
 float e;
 int tab[100]={0};
 char g[200]="";

   f=fopen(chemin,"r");
for(i=0;i<100;i++){tab[i]=0;};
      if (f!=NULL ){
            while (fscanf(f,"%d   %d  %d  %d  %f\n",&a,&b,&c,&d1,&e)!=EOF){
                 if (e>45) tab[a]+=1;}
    max=tab[0];

   for (i=0;i<100;i++){
    if (tab[i]>max) {max=tab[i];
                    }

   };


for (i=0;i<100;i++)if (tab[i]==max) {sprintf(g,"le capteur de temperature avec l identifiant %d est le plus defaillant\n",i);
strcat(h,g);

}



fclose(f);

}
else exit(1);

f=fopen("humidite.txt","r");
for(i=0;i<100;i++){tab[i]=0;};
      if (f!=NULL ){
            while (fscanf(f,"%d   %d  %d  %d  %f\n",&a,&b,&c,&d1,&e)!=EOF){
                 if (e<0 || e>100) tab[a]+=1;}
    max=tab[0];

   for (i=0;i<100;i++){
    if (tab[i]>max) {max=tab[i];
                    }

   };


for (i=0;i<100;i++)if (tab[i]==max) {sprintf(g,"le capteur d'humidité avec l identifiant %d est le plus defaillant\n",i);
strcat(h,g);

}



fclose(f);

}
else exit(1);


};






