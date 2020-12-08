#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "controle.h"

//ajouter voiture

void ajout_vt(VOITURE *tab_vt, int *nb_voitures)
{
    int n, m, i;
    VOITURE *voit;
    char num[15];
    printf("Combien de voitures voulez vous ajouter ? \n");
    scanf("%i", &n);
    while (n < 1)
    {
        printf("Le nombre entree est invalide. il faut entrer un nombre superieur ou egale a 1. Reesayez.\n");
        scanf("%i", &n);
    }

    getchar();
    if ((*nb_voitures == 0) && (n == 1))
    { //
    }
    else
    {
        tab_vt = (VOITURE *)realloc(tab_vt, ((*nb_voitures) + n) * sizeof(VOITURE));
    }
    m = *nb_voitures;
    for (int j = 0; j < n; j++)
    {
        voit = tab_vt + *nb_voitures + j;
        printf("entrez la marque de la voiture : ");
        fgets(voit->marque, 30, stdin);
        printf("entrez le modele de la voiture : ");
        fgets(voit->model, 30, stdin);
        printf("entrez le numero de la voiture : "); //doit etre unique
        fgets(num, 15, stdin);
        while (voiture_existe(tab_vt, m, num) == true)
        {
            printf("Ce numero de voiture existe deja. Il faut utiliser un numero unique/ Reesayez : ");
            fgets(num, 15, stdin);
        }
        strcpy(voit->numero, num);
        printf("entrez le couleur de la voiture : ");
        fgets(voit->couleur, 15, stdin);
        voit->loue = false;
        printf("entrez le prix de location par jour de la voiture : ");
        scanf("%f", &voit->ppj);
        printf("entrez le prix fixe d'assurance de la voiture : ");
        scanf("%f", &voit->assurance);
        getchar();
        m++;
    }
    *nb_voitures += n;
}

//ajouter un client
void ajout_clt(CLIENT *tab_clt, int *nb_clt)
{
    /*int i;
    bool valide;
    CLIENT *client;
    tab_clt = (CLIENT *)realloc(tab_clt, ((*nb_clt) + 1) * sizeof(CLIENT));

    client = tab_clt; //change
    printf("entrez le cin du client : ");
    fgets(client->cin, 12, stdin);
    /*do
    {
        printf("entrez le cin du client : ");
        fgets(client->cin, 12, stdin);
        printf("longuer %i \n", strlen(client->cin));
        valide = cntr_cin(client->cin);
    } while (valide == false);

    *nb_clt += 1;*/

    int n, i, m;
    CLIENT *clt;
    char cin[12];
    bool valide;

    printf("Combien de clients voulez vous ajouter ? \n");
    scanf("%i", &n);
    while (n < 1)
    {
        printf("Le nombre entree est invalide. il faut entrer un nombre superieur ou egale a 1. Reesayez.\n");
        scanf("%i", &n);
    }

    getchar();
    if ((*nb_clt == 0) && (n == 1))
    {
    }
    else
    {
        tab_clt = (CLIENT *)realloc(tab_clt, ((*nb_clt) + n) * sizeof(CLIENT));
    }
    m = *nb_clt;
    for (int j = 0; j < n; j++)
    {
        clt = tab_clt + m + j;
        do
        {
            printf("entrez le cin du client : ");
            fgets(clt->cin, 12, stdin);
            valide = cntr_cin(clt->cin);
        } while (valide == false);
        printf("entrez le nom du client : ");
        fgets(clt->nom, 30, stdin);
        printf("entrez le prenom du client : ");
        fgets(clt->prenom, 30, stdin);
        *nb_clt += 1;
    }
}
// afficher voiture
void affich_voit(VOITURE *voit, int i)
{
    printf("%i- modele %s marque %s , numero %s , couleur %s , ppj %.2f assurence %.2f", i + 1, voit->model, voit->marque, voit->numero, voit->couleur, voit->ppj, voit->assurance);
}
//afficher client
void affich_clt(CLIENT *clt, int i)
{
    printf("nom: %s prenom: %s cin : %s \n", clt->nom, clt->prenom, clt->cin);
}
//supprimer voiture
//supprimer client
//modifier voiture
//modifier client
//louer voiture
void louer(CLIENT *clients, VOITURE *voitures, RESERVATION *reservations, int *nb_clt, int nb_voit, int *nb_res)
{
    VOITURE *voit;
    RESERVATION *res;
    CLIENT *clt;
    char cin[12];
    if ((*nb_res != 0))
    {
        reservations = (RESERVATION *)realloc(reservations, ((*nb_res) + 1) * sizeof(RESERVATION));
    }
    reservations->client = clients;
    reservations->voiture = voitures;
    printf("Reservation avec SUCCESS!!! \n");
    affich_clt(reservations->client, 0);
    affich_voit(reservations->voiture, 0);
    /*printf("donner le cin du client : ");
    fgets(cin, 12, stdin);*/
}
//annuler une reservation