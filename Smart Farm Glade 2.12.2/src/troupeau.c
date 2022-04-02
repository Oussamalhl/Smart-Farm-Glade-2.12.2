#ifdef HAVE_CONFIG_H
#include <config.h>
#endif
#include "troupeau.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<gtk/gtk.h>

enum
{ 
	EID,
	ETYPE,
	EJOUR,
	EMOIS,
	EANNEE,
	ESEXE,
	COLUMNS,
};
//AJOUTER
void ajoutertroupeaux(troupeaux a)
{

FILE *f;
f=fopen("troupeaux.txt","a+");

fprintf(f,"%s %s %d %d %d %s \n",a.identifiant,a.type,a.date.jour,a.date.mois,a.date.annee,a.sexe);
fclose(f);
}
//SUPPRIMER
void supprimertroupeaux(char identifiant [])
{
troupeaux a;
FILE *f1;
FILE *f2;

f1=fopen("troupeaux.txt","r");
f2=fopen("trou.txt","w");
while(fscanf(f1,"%s %s %d %d %d  %s \n",a.identifiant,a.type,&a.date.jour,&a.date.mois,&a.date.annee,a.sexe)!=EOF)
{if (strcmp(identifiant,a.identifiant)!=0)
fprintf(f2,"%s %s %d %d %d %s \n",a.identifiant,a.type,a.date.jour,a.date.mois,a.date.annee,a.sexe);
}
fclose(f1);
fclose(f2);
remove("troupeaux.txt");
rename("trou.txt","troupeaux.txt");

}
//MODIFIER                       
void modifiertroupeaux(troupeaux a1)
{
troupeaux a;
FILE *f1;
FILE *f2;

f1=fopen("troupeaux.txt","r");
f2=fopen("trou.txt","a");

if((f1!=NULL)&&(f2!=NULL))
{
while(fscanf(f1,"%s %s %d %d %d %s \n",a.identifiant,a.type,&a.date.jour,&a.date.mois,&a.date.annee,a.sexe)!=EOF)
	{
	if(strcmp(a.identifiant,a1.identifiant)==0)
		{
		fprintf(f2,"%s %s %d %d %d %s \n",a1.identifiant,a1.type,a1.date.jour,a1.date.mois,a1.date.annee,a1.sexe);
		}
	else
		{
		fprintf(f2,"%s %s %d %d %d %s \n",a.identifiant,a.type,a.date.jour,a.date.mois,a.date.annee,a.sexe);
		}
	}

}
fclose(f1);
fclose(f2);
remove("troupeaux.txt");
rename("trou.txt","troupeaux.txt");
}
//AFFICHAGE
void affichagetroupeaux(GtkWidget *liste)
{
GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	char id[30];
	char type[30];
	char jour[10];
	char mois[10];
	char annee[10];
	char sexe[30];
	store=NULL;
	FILE *f;
	store=gtk_tree_view_get_model (liste);
	if (store==NULL)
	{
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("identifiant", renderer, "text",EID,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("type", renderer, "text",ETYPE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);   

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("jour", renderer, "text",EJOUR,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column); 

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("mois", renderer, "text",EMOIS,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("annee", renderer, "text",EANNEE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("sexe", renderer, "text",ESEXE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	}
	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING,  G_TYPE_STRING,   G_TYPE_STRING, G_TYPE_STRING,  G_TYPE_STRING,  G_TYPE_STRING);
	f=fopen("troupeaux.txt","r");
	if(f==NULL)
	{
		return;
	}
	else
	{
		f= fopen("troupeaux.txt","a+");
		while(fscanf(f,"%s %s %s %s %s %s \n",id,type,jour,mois,annee,sexe)!=EOF)
		{
			gtk_list_store_append(store, &iter);
			gtk_list_store_set(store,&iter, EID, id, ETYPE, type, EJOUR,jour,EMOIS,mois,EANNEE,annee,ESEXE,sexe, -1);
		}
		fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
		g_object_unref (store);
	}
}
//AFFICHAGERECHERCHE
void affichagetroupeauxr(GtkWidget *liste)
{
GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	char id[30];
	char type[30];
	char jour[10];
	char mois[10];
	char annee[10];
	char sexe[30];
	store=NULL;
	FILE *f;
	store=gtk_tree_view_get_model (liste);
	if (store==NULL)
	{
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("identifiant", renderer, "text",EID,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("type", renderer, "text",ETYPE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);   

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("jour", renderer, "text",EJOUR,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column); 

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("mois", renderer, "text",EMOIS,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("annee", renderer, "text",EANNEE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("sexe", renderer, "text",ESEXE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	}
	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING,  G_TYPE_STRING,   G_TYPE_STRING, G_TYPE_STRING,  G_TYPE_STRING,  G_TYPE_STRING);
	f=fopen("troupeaux.txt","r");
	if(f==NULL)
	{
		return;
	}
	else
	{
		f= fopen("troupeauxrecherche.txt","a+");
		while(fscanf(f,"%s %s %s %s %s %s \n",id,type,jour,mois,annee,sexe)!=EOF)
		{
			gtk_list_store_append(store, &iter);
			gtk_list_store_set(store,&iter, EID, id, ETYPE, type, EJOUR,jour,EMOIS,mois,EANNEE,annee,ESEXE,sexe, -1);
		}
		fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
		g_object_unref (store);
	}
}
  //**********  REMPLIR FICHIER <--TABLEAU **************

void remlirfichier(troupeaux tab[],int nb)
{
int i;
FILE *f=NULL;
f=fopen("troupeaux.txt", "w+");
if("f!=NULL")
	{for (i=0;i<nb;i++)
		{fprintf(f,"%s %s %d %d %d %s \n",tab[i].identifiant,tab[i].type,tab[i].date.jour,tab[i].date.mois,tab[i].date.annee,tab[i].sexe);}

	}
fclose(f);
}
//**********  REMPLIR TABLEAU <--FICHIER **************

int remplirtab (troupeaux tab[],int nb)
{
    char id[20],type[20];
    char sexe[20];
    int jour,mois,annee;
    FILE* fichier ;
    int i=0;

    fichier = fopen("troupeaux.txt", "a+");


        while (fscanf(fichier,"%s %s %d %d %d %s \n",id,type,&jour,&mois,&annee,sexe)!=EOF)
        {
            nb++;
            strcpy(tab[i].identifiant,id);
            strcpy(tab[i].type,type);
	    tab[i].date.jour=jour;
            tab[i].date.mois=mois;
	    tab[i].date.annee=annee;
            strcpy(tab[i].sexe,sexe);
            i++;
	    
        }
        

        fclose(fichier);
	return(nb);
}
//RECHERCHER

int rechercher_troupeaux(char identifiant[])
{
troupeaux tabt[100];
int nb;
int ce,i;
FILE*f;
ce=0;
nb=remplirtab (tabt,nb);
for (i=0;i<nb;i++)
	{if (strcmp(identifiant,tabt[i].identifiant)==0)
		{
		ce=1;
		f=fopen("troupeauxrecherche.txt", "w+");
		if("f!=NULL")
			{fprintf(f,"%s %s %d %d %d %s \n",tabt[i].identifiant,tabt[i].type,tabt[i].date.jour,tabt[i].date.mois,tabt[i].date.annee,tabt[i].sexe);}
		fclose(f);		
		}
	}

return(ce);
}


//nombre troupeaux
void nbtoupeaux (int *c, int *p, int *v, int *m)
{
troupeaux a;
FILE*f;
f=fopen("troupeaux.txt","r");
while(fscanf(f,"%s %s %d %d %d %s \n",a.identifiant,a.type,&a.date.jour,&a.date.mois,&a.date.annee,a.sexe)!=EOF)
{
if(strcmp(a.type,"Vache")==0)
{
*v=*v+1;
}
else if(strcmp(a.type,"Poule")==0)
{
*p=*p+1;
}
else if(strcmp(a.type,"Mouton")==0)
{
*m=*m+1;
}
else if(strcmp(a.type,"Cheval")==0)
{
*c=*c+1;
}
}
}

troupeaux rechercher (char ID[])
{
troupeaux a;
FILE* f1;
f1=fopen("troupeaux.txt","r");
if(f1!=NULL)
	{
	while(fscanf(f1,"%s %s %d %d %d %s \n",a.identifiant,a.type,&a.date.jour,&a.date.mois,&a.date.annee,a.sexe)!=EOF)
	    {
	     if(strcmp(a.identifiant,ID)==0)
              {return(a);}
            }
	}
fclose(f1);
return;   
}

int rechercher_troupeauxl(char ID[])
{
troupeaux a;
FILE* f1;
f1=fopen("troupeaux.txt","r");
if(f1!=NULL)
	{
	while(fscanf(f1,"%s %s %d %d %d %s \n",a.identifiant,a.type,&a.date.jour,&a.date.mois,&a.date.annee,a.sexe)!=EOF)
	{
	if(strcmp(a.identifiant,ID)==0)
		{return 1;}
	}
	}
fclose(f1);
return 0;
}
