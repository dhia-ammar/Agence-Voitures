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
    RESERVATION *reservations;

    printf("Bienvenue dans votre agence de location de voitures.\nClickez n'importe quelle touche pour commencer.");
    getchar();
    system("cls");
    voitures = (VOITURE *)malloc(sizeof(VOITURE));
    //clients = (CLIENT *)malloc(sizeof(CLIENT));

    /* 
    
                Do NOT TOUCH THE ABOVE


    */

    /*ajout_vt(voitures, &nb_voitures);

    printf("il y'a %i voitures \nListe des voitures:\n", nb_voitures);
    for (int i = 0; i < nb_voitures; i++)
    {
        voit = voitures + i;
        affich_voit(voit);
    }
    //clients = (CLIENT *)malloc(sizeof(CLIENT));
    ajout_vt(voitures, &nb_voitures);
    printf("il y'a %i voitures \nListe des voitures:\n", nb_voitures);
    for (int i = 0; i < nb_voitures; i++)
    {
        voit = voitures + i;
        affich_voit(voit);
    }
    printf("il y'a %i voitures \nListe des voitures:\n", nb_voitures);
    for (int i = 0; i < nb_voitures; i++)
    {
        voit = voitures + i;
        affich_voit(voit);
    }*/

    /*ajout_clt(clients, &nb_clt);

    printf("il y'a %i clients : ", nb_clt);
    for (int i = 0; i < nb_clt; i++)
    {
        clt = clients + i;
        affich_clt(clt);
    }
    ajout_clt(clients, &nb_clt);
    reservations = (RESERVATION *)malloc(sizeof(RESERVATION));
    for (int i = 0; i < nb_voitures; i++)
    {
        voit = voitures + i;
        affich_voit(voit);
    }
    printf("AFFICHAGE FINALE \n");
    for (int i = 0; i < nb_clt; i++)
    {
        clt = clients + i;
        affich_clt(clt);
    }*/
    //louer(clients, voitures, reservations, &nb_clt, nb_voitures, &nb_res);
    //louer(clients, voitures, reservations, &nb_clt, nb_voitures, &nb_res);
    /*printf("il y'a %i voitures \nListe des voitures:\n", nb_voitures);
    for (int i = 0; i < nb_voitures; i++)
    {
        voit = voitures + i;
        printf("voiture %i, modele %s marque %s , numero %s , couleur %s , ppj %f.2 assurence %f.2", i, voit->model, voit->marque, voit->numero, voit->couleur, voit->ppj, voit->assurance);
    }

    ajout_clt(clients, &nb_clt);
    printf("il y'a %i clients : ", nb_clt);
    for (int i = 0; i < nb_clt; i++)
    {
        clt = clients + i;
        printf("client %i nu cin : %s \n", i, clt->cin);
    }*/
}