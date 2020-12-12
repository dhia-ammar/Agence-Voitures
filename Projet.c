#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "maBib.h"
#include <conio.h>

void main()
{
    /*char *cin;
    int j, m, a;
    bool valide;
    do
    {
        cin = (char *)malloc(12 * sizeof(char));
        printf("entrez le cin : ");
        fgets(cin, 12, stdin);
        printf("longuer %i \n", strlen(cin));
        valide = cntr_cin(cin);
    } while (cntr_cin(cin) == false);*/

    VOITURE *voitures, *voit;
    int nb_voitures = 0, nb_clt = 0, nb_res = 0;
    CLIENT *clients, *clt;
    RESERVATION *reservations, *res;
    system("cls");
    printf("Bienvenue dans votre agence de location de voitures.\nClickez n'importe quelle touche pour commencer.");
    getchar();
    system("cls");
    //voitures = (VOITURE *)malloc(sizeof(VOITURE));
    //clients = (CLIENT *)malloc(sizeof(CLIENT));

    /* 
    
                Do NOT TOUCH THE ABOVE


    */

    clients = aj_client2(clients, &nb_clt);
    printf("il y'a %i clients:\n", nb_clt);
    for (int i = 0; i < nb_clt; i++)
    {
        clt = clients + i;
        affich_clt(clt);
        printf("---------------\n");
    }
    voitures = aj_voit2(voitures, &nb_voitures);
    printf("il y'a %i voitures:\n", nb_voitures);
    for (int i = 0; i < nb_voitures; i++)
    {
        voit = voitures + i;
        affich_voit(voit);
        printf("---------------\n");
    }

    reservations = louer(clients, voitures, reservations, nb_clt, nb_voitures, &nb_res);
    reservations = louer(clients, voitures, reservations, nb_clt, nb_voitures, &nb_res);
    printf("************************\n");
    for (int i = 0; i < nb_res; i++)
    {
        res = reservations + i;
        affich_res(res);
    }
}