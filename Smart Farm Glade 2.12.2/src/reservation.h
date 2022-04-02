#include<gtk/gtk.h>
typedef struct date
{int jour,mois,annee;
}Date;


typedef struct rdvclient{
char IDclient[20];
int hr_resr;
Date dt_resr;
}ReservationClient;




int tableau_Reservation_client(char rs[20][10]);
void reservation_client (ReservationClient s);
