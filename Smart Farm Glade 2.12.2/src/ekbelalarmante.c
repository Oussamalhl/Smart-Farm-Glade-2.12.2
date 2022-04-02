#include "ekbelalarmante.h"
#include "callbacks.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <gtk/gtk.h>

enum{
ID,
VALEUR,
DATE_NAISSANCE,
TYPE,
MARQUE,
COLUMNS
};
void afficher_capteur_alarmant(GtkWidget *liste)
{
Capteur c;
float max1=50, min1=0, min2=40, max2=90;
char DATE[30];
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
store = NULL;
FILE *fp;


store = gtk_tree_view_get_model(liste);
if (store == NULL)
{
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Id",renderer,"text",ID,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Valeur",renderer,"text",VALEUR,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Date de Capteur",renderer,"text",DATE_NAISSANCE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Type",renderer,"text",TYPE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Marque",renderer,"text",MARQUE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
}
	store = gtk_list_store_new(COLUMNS, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
	fp = fopen("capteurs.bin", "rb");

	if(fp==NULL)
	{
	return;
	}

	else
	{
		fp = fopen("capteurs.bin", "ab+");	
		while(fread(&c, sizeof(c), 1, fp))
		{
		 if( ((strcmp(c.type,"Temperature")==0)&&((atoi(c.valeur)<min1) || (atoi(c.valeur)>max1)))||((strcmp(c.type,"Humidite")==0)&&((atoi(c.valeur)<min2) || (atoi(c.valeur)>max2))) ){
		sprintf(DATE, "%d/%d/%d", c.date_naissance.jour,c.date_naissance.mois,c.date_naissance.annee);
		
		gtk_list_store_append(store, &iter);
		gtk_list_store_set(store, &iter, ID, c.id, VALEUR, c.valeur,DATE_NAISSANCE, DATE, TYPE, c.type,  MARQUE, c.marque,-1);
		}
		}
		fclose(fp);
		gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
		g_object_unref(store);
	}

}


