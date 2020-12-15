#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "maBib.h"
#include <conio.h>

void main()
{
    VOITURE *voitures, *voit;
    int nb_voitures = 0, nb_clt = 0, nb_res = 0, mp;
    CLIENT *clients, *clt;
    RESERVATION *reservations, *res;
    float caisse;
    system("cls");
    printf("Bienvenue dans votre agence de location de voitures.\nClickez n'importe quelle touche pour commencer.");
    getchar();
    system("cls");

    if ((nb_clt > 0) && (nb_voitures > 0))
    {
    }
    while (true)
    {
        printf("\t ***MENU PRINCIPAL*** \n");
        printf("0/ ajouter des clients \n");
        printf("1/ ajouter une voiture \n");
        if ((nb_clt > 0) && (nb_voitures > 0))
        {
            printf("2/ louer une voiture  \n");
        }
        if ((nb_clt > 0))
        {
            printf("3/ afficher la liste des clients \n");
        }
        if ((nb_voitures > 0))
        {
            printf("4/ afficher la liste des voitures \n");
        }
        if ((nb_res > 0))
        {
            printf("5/ afficher la liste des reservations \n");
        }
        if ((nb_clt > 0))
        {
            printf("6/ supprimer un client \n");
        }
        if ((nb_voitures > 0))
        {
            printf("7/ supprimer une voiture \n");
        }
        if ((nb_res > 0))
        {
            printf("8/ annuler une reservation \n");
        }
        if (nb_res > 0)
        {
            printf("9/ payer une reservation \n");
        }
        printf("10/ afficher le montant dans la caisse \n");

        if ((nb_clt == 0) || (nb_voitures == 0))
        {
            printf("Ajouter des voiture et des clients pour plus de choix.\n");
        }
        if ((nb_clt != 0) && (nb_voitures != 0) && (nb_res == 0))
        {
            printf("Ajouter des reservations pour plus de choix.\n");
        }

        printf("Saisissez un choix : ");
        scanf("%d", &mp);
        getchar();
        if (mp == 0)
        {
            clients = aj_client2(clients, &nb_clt);
            printf("il y'a %i clients:\n", nb_clt);
            for (int i = 0; i < nb_clt; i++)
            {
                clt = clients + i;
                affich_clt(clt);
                printf("---------------\n");
            }
            printf("Tapez n'importe quelle touche pour retourner au menu.");
            getchar();
            system("cls");
        }

        else if (mp == 1)
        {
            voitures = aj_voit2(voitures, &nb_voitures);
            printf("il y'a %i voitures:\n", nb_voitures);
            for (int i = 0; i < nb_voitures; i++)
            {
                voit = voitures + i;
                affich_voit(voit);
                printf("---------------\n");
            }
            printf("Tapez n'importe quelle touche pour retourner au menu.");
            getchar();
            system("cls");
        }

        else if ((mp == 2) && (nb_clt > 0) && (nb_voitures > 0))
        {
            reservations = louer(clients, voitures, reservations, nb_clt, nb_voitures, &nb_res);
            printf("Tapez n'importe quelle touche pour retourner au menu.");
            getchar();
            system("cls");
        }
        else if ((mp == 3) && (nb_clt > 0))
        {
            printf("Il y'a %i clients.\nLa liste des clients est : \n", nb_clt);
            for (int i = 0; i < nb_clt; i++)
            {
                clt = clients + i;
                affich_clt(clt);
                printf("---------------\n");
            }
            printf("****************************\n");
            printf("Tapez n'importe quelle touche pour retourner au menu.");
            getchar();
        }

        else if ((mp == 4) && (nb_voitures > 0))
        {
            printf("Il y'a %i voitures.\nLa liste des voitures est : \n", nb_voitures);
            for (int i = 0; i < nb_voitures; i++)
            {
                voit = voitures + i;
                affich_voit(voit);
                printf("---------------\n");
            }
            printf("****************************\n");
            printf("Tapez n'importe quelle touche pour retourner au menu.");
            getchar();
        }

        else if ((mp == 5) && (nb_res) > 0)
        {
            printf("La liste des reservations est : \n");
            for (int i = 0; i < nb_res; i++)
            {
                res = reservations + i;

                affich_res(res);
                printf("---------------\n");
            }
            printf("****************************\n");
            printf("Tapez n'importe quelle touche pour retourner au menu.");
            getchar();
        }

        else if ((mp == 6) && (nb_clt > 0))
        {
            clients = supprimer_client(clients, &nb_clt);
            printf("Il y'a %i clients.\nLa liste des clients est : \n", nb_clt);
            for (int i = 0; i < nb_clt; i++)
            {
                clt = clients + i;
                affich_clt(clt);
                printf("---------------\n");
            }
            printf("****************************\n");
            printf("Tapez n'importe quelle touche pour retourner au menu.");
            getchar();
            system("cls");
        }

        else if ((mp == 7) && (nb_voitures > 0))
        {
            voitures = supprimer_voiture(voitures, &nb_voitures);
            printf("Il y'a %i voitures.\nLa liste des voitures est : \n", nb_voitures);
            for (int i = 0; i < nb_voitures; i++)
            {
                voit = voitures + i;
                affich_voit(voit);
                printf("---------------\n");
            }
            printf("****************************\n");
            printf("Tapez n'importe quelle touche pour retourner au menu.");
            getchar();
            system("cls");
        }
        else if ((mp == 8) && (nb_res > 0))
        {
            reservations = supprimer_reservation(reservations, &nb_res);
            printf("La liste des reservations est : \n");
            for (int i = 0; i < nb_res; i++)
            {
                res = reservations + i;

                affich_res(res);
                printf("---------------\n");
            }
            printf("****************************\n");
            printf("Tapez n'importe quelle touche pour retourner au menu.");
            getchar();
            system("cls");
        }

        else if ((mp == 9) && (nb_res > 0))
        {
            payer(reservations, nb_res, &caisse);
            printf("Tapez n'importe quelle touche pour retourner au menu.");
            getchar();
            system("cls");
        }
        else if (mp == 10)
        {
            printf("Caisse =  %.2f DT\n", caisse);
            printf("Tapez n'importe quelle touche pour retourner au menu.");
            getchar();
            system("cls");
        }
        else
        {
            printf("Choix invalide!\nTapez n'importe quelle touche pour retourner au menu.");
            getchar();
            system("cls");
        }
    }
}