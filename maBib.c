#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "maBib.h"
#include "controle.h"

void ajout_vt(VOITURE *, int *);
void ajout_clt(CLIENT *, int *);
void affich_voit(VOITURE *, int);
void affich_clt(CLIENT *, int);
void louer(CLIENT *, VOITURE *, RESERVATION *, int *, int, int *);