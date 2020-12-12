#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "maBib.h"
#include "controle.h"

//void ajout_vt(VOITURE *, int *);
//void ajout_clt(CLIENT *, int *);
void affich_voit(VOITURE *);
void affich_clt(CLIENT *);
RESERVATION *louer(CLIENT *, VOITURE *, RESERVATION *, int, int, int *);
void affiche_date(DATE *);
int recherche_voit(VOITURE *, int, char[15]);
int recherche_clt(CLIENT *, int, char[12]);
DATE *ajout_date(DATE *, int);
//void aj_vt(VOITURE *, int *);
//void aj_clt(VOITURE *, int *);
CLIENT *aj_client2(CLIENT *, int *);
VOITURE *aj_voit2(VOITURE *, int *);
void affich_res(RESERVATION *);