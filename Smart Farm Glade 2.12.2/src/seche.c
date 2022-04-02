#include "seche.h"
#include <stdio.h>


int annee_plus_seche(int Annee, int sec)


{

FILE *f=NULL;
int capId, capjour, capmois, capannee;
float capval=0,capsom=0;
float moy[20];
int i,j,n,plus_seche,annee,ann[50],A;

if(sec==1){

f=fopen("temperature.txt","r");
i=0;
j=0;
n=0;
if(f!=NULL)
{
while(fscanf(f,"%d %d %d %d %f",&capId, &capjour, &capmois, &capannee, &capval)!=EOF)
{
if(capannee==Annee)
{
capsom+=capval;
				//printf("\n%f %d",capval,capannee);
}
if (capannee==Annee+1)
{
ann[i]=Annee;
Annee+=1;
capannee=Annee;
moy[i]=capsom/365*9;
capsom=0;
i++;
n++;
}
}

plus_seche=0;
//Annee=0;
for (i=0; i<n; i++)
{
if(moy[i]>plus_seche)
{plus_seche=moy[i];
A=ann[i];


}
}


fclose(f);
return (A);
}
}

//////////////////////////////////////////////////////////////

else if (sec==2){

}
f=fopen("humidite.txt","r");
i=0;
j=0;
n=0;
if(f!=NULL)
{
while(fscanf(f,"%d %d %d %d %f",&capId, &capjour, &capmois, &capannee, &capval)!=EOF)
{
if(capannee==Annee)
{
capsom+=capval;
				//printf("\n%f %d",capval,capannee);
}
if (capannee==Annee+1)
{
ann[i]=Annee;
Annee+=1;
capannee=Annee;
moy[i]=capsom/365*9;
capsom=0;
i++;
n++;
}
}

plus_seche=0;
//Annee=0;
for (i=0; i<n; i++)
{
if(moy[i]>plus_seche)
{plus_seche=moy[i];
A=ann[i];


}
}


fclose(f);
return (A);
}

}
