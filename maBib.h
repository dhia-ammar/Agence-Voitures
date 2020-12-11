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

void aj_vt(VOITURE *voitures, int *nb_voit)
{
    int n = *nb_voit, m;
    VOITURE *voit;
    char num[15];

    printf("Combien de voitures voulez vous ajouter ? \n");
    scanf("%i", &m);
    while (m < 1)
    {
        printf("Le nombre entree est invalide. il faut entrer un nombre superieur ou egale a 1. Reesayez.\n");
        scanf("%i", &m);
    }
    if ((n != 0) || (m != 1))
    {
        voitures = (VOITURE *)realloc(voitures, (n + m) * sizeof(VOITURE));
    }
    getchar();

    for (int i = 0; i < m; i++)
    {
        voit = (voitures + n);
        printf("entrez la marque de la voiture : ");
        fgets(voit->marque, 30, stdin);
        printf("entrez le modele de la voiture : ");
        fgets(voit->model, 30, stdin);
        printf("entrez le numero de la voiture : "); //doit etre unique
        fgets(num, 15, stdin);
        while (voiture_existe(voitures, n, num) == true)
        {
            printf("Ce numero de voiture existe deja. Il faut utiliser un numero unique \n Reesayez : ");
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
        n++;
    }
    *nb_voit = n;
}
VOITURE *aj_voit2(VOITURE *voitures, int *nb_voit)
{
    int n = *nb_voit, m;
    VOITURE *voit, *vts, *v;
    char num[15];

    printf("Combien de voitures voulez vous ajouter ? \n");
    scanf("%i", &m);
    while (m < 1)
    {
        printf("Le nombre entree est invalide. il faut entrer un nombre superieur ou egale a 1. Reesayez.\n");
        scanf("%i", &m);
    }
    getchar();
    m += n;
    vts = (VOITURE *)malloc(m * sizeof(VOITURE));

    for (int i = 0; i < m; i++)
    {
        voit = (vts + i);
        if (i < n)
        {
            v = voitures + i;
            strcpy(voit->marque, v->marque);
            strcpy(voit->model, v->model);
            strcpy(voit->numero, v->numero);
            strcpy(voit->couleur, v->couleur);
            voit->loue = v->loue;
            voit->ppj = v->ppj;
            voit->assurance = v->assurance;
        }

        else
        {
            printf("entrez la marque de la voiture : ");
            fgets(voit->marque, 30, stdin);
            printf("entrez le modele de la voiture : ");
            fgets(voit->model, 30, stdin);
            printf("entrez le numero de la voiture : "); //doit etre unique
            fgets(num, 15, stdin);
            while (voiture_existe(voitures, n, num) == true)
            {
                printf("Ce numero de voiture existe deja. Il faut utiliser un numero unique \n Reesayez : ");
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
        }
    }

    *nb_voit = m;
    return vts;
}
//ajouter un client
void aj_client(CLIENT *clients, int *nb_clt)
{
    int n, m;
    CLIENT *clt;
    char cin[12];
    bool valide;
    n = *nb_clt;
    printf("Combien de clients voulez vous ajouter ? \n");
    scanf("%i", &m);
    while (m < 1)
    {
        printf("Le nombre entree est invalide. il faut entrer un nombre superieur ou egale a 1. Reesayez.\n");
        scanf("%i", &m);
    }
    if ((n != 0) || (m != 1))
    {
        clients = (CLIENT *)realloc(clients, (n + m) * sizeof(CLIENT));
    }
    getchar();
    for (int i = 0; i < m; i++)
    {
        clt = clients + n;
        do
        {
            printf("entrez le cin du client : ");
            fgets(clt->cin, 12, stdin);
            fflush(stdin);
            valide = cntr_cin(clt->cin);
        } while (valide == false);
        printf("entrez le nom du client : ");
        fgets(&clt->nom, 30, stdin);
        fflush(stdin);
        printf("entrez le prenom du client : ");
        fgets(&clt->prenom, 30, stdin);
        fflush(stdin);
        n++;
    }
    *nb_clt = n;
}
CLIENT *aj_client2(CLIENT *clients, int *nb_clt)
{
    int n, m;
    CLIENT *clt, *clts, *c;
    char cin[12];
    bool valide;

    n = *nb_clt;
    printf("Combien de clients voulez vous ajouter ? \n");
    scanf("%i", &m);
    while (m < 1)
    {
        printf("Le nombre entree est invalide. il faut entrer un nombre superieur ou egale a 1. Reesayez.\n");
        scanf("%i", &m);
    }
    m += n;
    clts = (CLIENT *)malloc(m * sizeof(CLIENT));
    getchar();

    for (int i = 0; i < m; i++)
    {
        clt = clts + i;
        if (i < n)
        {
            c = clients + i;
            strcpy(clt->cin, c->cin);
            strcpy(clt->nom, c->nom);
            strcpy(clt->prenom, c->prenom);
        }
        else
        {
            do
            {
                printf("entrez le cin du client : ");
                fgets(clt->cin, 12, stdin);
                valide = cntr_cin(clt->cin);
            } while (valide == false);
            printf("entrez le nom du client : ");
            fgets(&clt->nom, 30, stdin);
            printf("entrez le prenom du client : ");
            fgets(&clt->prenom, 30, stdin);
        }
    }
    *nb_clt = m;
    return clts;
}
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
    m = *nb_clt;
    m += n;
    getchar();
    if ((*nb_clt != 0) || (n != 1))
    {

        tab_clt = (CLIENT *)realloc(tab_clt, m * sizeof(CLIENT));
        printf("REALLOCING size %i \n", m);
    }
    //affich_clt(tab_clt);
    //affich_clt(tab_clt + 1);

    for (clt = tab_clt + *nb_clt; clt < tab_clt + *nb_clt + n; clt++)
    {
        do
        {
            printf("entrez le cin du client : ");
            fgets(clt->cin, 12, stdin);
            valide = cntr_cin(clt->cin);
        } while (valide == false);
        printf("entrez le nom du client : ");
        fgets(&clt->nom, 30, stdin);
        printf("entrez le prenom du client : ");
        fgets(&clt->prenom, 30, stdin);
    }
    *nb_clt += n;
}
// afficher voiture
void affich_voit(VOITURE *voit)
{
    printf("numero: %s marque: %s modele: %s \n couleur: %s  ppj: %.1f assurence: %.1f \n", voit->numero, voit->marque, voit->model, voit->couleur, voit->ppj, voit->assurance);
}
//afficher client
void affich_clt(CLIENT *clt)
{
    printf("nom: %s prenom: %s cin : %s \n", clt->nom, clt->prenom, clt->cin);
    fflush(stdout);
}
//afficher date
void affiche_date(DATE *date)
{
    printf("%i/%i/%i", date->jour, date->mois, date->annee);
}
//recherche client :recharche si un client existe deja en utlisant le CIN
int recherche_clt(CLIENT *clients, int nb_clt, char cin[12])
{
    CLIENT *clt;
    for (int i = 0; i < nb_clt; i++)
    {
        clt = clients + i;
        if (strcmp(cin, clt->cin) == 0)
        {
            return i;
        }
    }
    return -1;
}

//recherche voit :recharche si une voit existe deja en utlisant le num
int recherche_voit(VOITURE *voitures, int nb_voit, char num[15])
{
    VOITURE *voit;
    for (int i = 0; i < nb_voit; i++)
    {
        voit = voitures + i;
        if (strcmp(num, voit->numero) == 0)
        {
            return i;
        }
    }
    return -1;
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
    DATE *date1;
    char cin[12], num[15];
    if ((*nb_res != 0))
    {
        reservations = (RESERVATION *)realloc(reservations, ((*nb_res) + 1) * sizeof(RESERVATION));
    }
    printf("donner le cin du client : ");
    fgets(cin, 12, stdin);
    if ((recherche_clt(clients, (*nb_clt), cin) == -1))
    {
        printf("le client n'existe pas");
        /* A AJOUTER
        Le client n'existe pas voulez vous ajouter ce client */
    }
    else
    {
        reservations->client = clients + (recherche_clt(clients, (*nb_clt), cin[12]));
    }
    printf("donner le numero de la voiture a louer : ");
    fgets(num, 15, stdin);
    while (recherche_voit(voitures, nb_voit, num) == -1)
    {
        printf("Cette voiture n'existe pas. Donner un numero valide: ");
        fgets(num, 15, stdin);
    }
    reservations->voiture = voitures + recherche_voit(voitures, nb_voit, num);

    /*reservations->client = clients;
    reservations->voiture = voitures;*/
    date1 = (DATE *)malloc(sizeof(DATE));
    date1->jour = 13;
    date1->mois = 11;
    date1->annee = 1999;

    reservations->ddl = date1;
    printf("Reservation avec SUCCESS!!! \n");
    affich_clt(reservations->client);
    affich_voit(reservations->voiture);
    affiche_date(reservations->ddl);

    printf("donner le cin du client : ");
    fgets(cin, 12, stdin);
}
//annuler une reservation
//ajouter deux dates
DATE ajout_date(DATE debut, int duree)
{
    int jour, mois, an;
    DATE fin;
    int jours[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    jour = debut.jour;
    mois = debut.mois;
    an = debut.annee;
    jour += duree;

    while (jour > jours[mois - 1])
    {
        jour -= jours[mois - 1];
        if ((an % 4 == 0) && (mois == 2)) //si fevrier 29 jours
        {
            jour--;
        }

        if (mois < 12)
        {
            mois++;
        }
        else
        {
            mois = 1;
            an++;
        }
    }
    fin.annee = an;
    fin.jour = jour;
    fin.mois = mois;
    return fin;
}