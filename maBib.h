#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "controle.h"

//ajouter voiture

/*void ajout_vt(VOITURE *tab_vt, int *nb_voitures)
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
        printf("entrez le prix de location par jour de la voiture : ");
        scanf("%f", &voit->ppj);
        printf("entrez le prix fixe d'assurance de la voiture : ");
        scanf("%f", &voit->assurance);
        getchar();
        n++;
    }
    *nb_voit = n;
}*/
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
/*void aj_client(CLIENT *clients, int *nb_clt)
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
}*/
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
/*void ajout_clt(CLIENT *tab_clt, int *nb_clt)
{
    int i;
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

    *nb_clt += 1;

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
}*/
// afficher voiture
void affich_voit(VOITURE *voit)
{
    printf("numero: %smarque: %smodele: %scouleur: %sppj: %.1f assurence: %.1f \n", voit->numero, voit->marque, voit->model, voit->couleur, voit->ppj, voit->assurance);
}
//afficher client
void affich_clt(CLIENT *clt)
{
    printf("nom: %sprenom: %scin : %s \n", clt->nom, clt->prenom, clt->cin);
    fflush(stdout);
}
//afficher date
void affiche_date(DATE *date)
{
    printf("%i/%i/%i \n", date->jour, date->mois, date->annee);
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
//ajouter deux dates
DATE *ajout_date(DATE *debut, int duree)
{
    int jour, mois, an;
    DATE *fin;
    int jours[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    jour = debut->jour;
    mois = debut->mois;
    an = debut->annee;
    jour += duree;
    fin = (DATE *)malloc(sizeof(DATE));
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
    fin->annee = an;
    fin->jour = jour;
    fin->mois = mois;
    return fin;
}

bool voit_dispo(RESERVATION *reservations, int nb_res, VOITURE *voit, DATE *ddl, DATE *dfl)
{

    RESERVATION *res;
    for (int i = 0; i < nb_res; i++)
    {
        res = reservations + i;
        if (res->voiture == voit)
        {
            if ((comp_date(dfl, res->ddl) != -1) && (comp_date(ddl, res->dfl) != 1))
            {
                return false;
            }
        }
    }
    return true;
}

//louer voiture
RESERVATION *louer(CLIENT *clients, VOITURE *voitures, RESERVATION *reservations, int nb_clt, int nb_voit, int *nb_res)
{
    VOITURE *voit;
    RESERVATION *res, *tab_res, *r;
    CLIENT *clt;
    DATE *date1, *date2;
    char cin[12], num[15];
    int n = *nb_res, i;

    tab_res = (RESERVATION *)malloc((n + 1) * sizeof(RESERVATION));
    if (nb_res > 0)
    {
        for (int i = 0; i < n; i++)
        {
            r = reservations + i;
            res = tab_res + i;
            res->duree = r->duree;
            res->ddl = r->ddl;
            res->dfl = r->dfl;
            res->voiture = r->voiture;
            res->client = r->client;
            res->facture = r->facture;
            res->paye = r->paye;
        }
    }

    res = tab_res + n;
    printf("donner le cin du client : ");
    fgets(cin, 12, stdin);
    while ((recherche_clt(clients, nb_clt, cin) == -1))
    {
        printf("le client n'existe pas. Reesayez: \n");
        fgets(cin, 12, stdin);
    }
    i = recherche_clt(clients, nb_clt, cin);
    res->client = clients + i;
    do
    {
        printf("donner le numero de la voiture a louer : ");
        fgets(&num, 15, stdin);
        while (recherche_voit(voitures, nb_voit, num) == -1)
        {
            printf("Cette voiture n'existe pas. Donner un numero valide: ");
            fgets(&num, 15, stdin);
        }
        i = recherche_voit(voitures, nb_voit, num);
        res->voiture = voitures + i;

        date1 = (DATE *)malloc(sizeof(DATE));
        printf("Donner la date de debut de location : ");
        scanf("%i%i%i", &date1->jour, &date1->mois, &date1->annee);
        while (cntr_date(date1->jour, date1->mois, date1->annee) == false)
        {
            scanf("%i%i%i", &date1->jour, &date1->mois, &date1->annee);
        }
        date2 = (DATE *)malloc(sizeof(DATE));
        res->ddl = date1;
        printf("Donner la duree de reservation en jours : ");
        scanf("%i", &res->duree);
        getchar();
        res->dfl = ajout_date(date1, res->duree);
        if (voit_dispo(reservations, n, res->voiture, res->ddl, res->dfl) == false)
        {
            printf("Cette voiture n'est pas disponible pour cette datte. \nChangez de date ou changez la voiture.\n");
        }

    } while (voit_dispo(reservations, n, res->voiture, res->ddl, res->dfl) == false);
    printf("Reservation avec SUCCESS!!! \n");
    affich_clt(res->client);
    affich_voit(res->voiture);
    printf("Date de debut de location : ");
    affiche_date(res->ddl);
    printf("Date de fin de location : ");
    affiche_date(res->dfl);
    res->facture = (res->voiture->ppj) * res->duree + res->voiture->assurance;
    printf("Facture : %.2f \n", res->facture);
    *nb_res = n + 1;
    return tab_res;
}

//afficher les reservations

void affich_res(RESERVATION *res)
{
    printf("Client: \n");
    affich_clt(res->client);
    printf("Voiture : \n");
    affich_voit(res->voiture);
    printf("Date de debut de location : ");
    affiche_date(res->ddl);
    printf("Date de fin de location : ");
    affiche_date(res->dfl);
    printf("Total = %.2f DT \n", res->facture);
}

//supprimer client
CLIENT *supprimer_client(CLIENT *clients, int *nb_client)
{
    int n = *nb_client;
    CLIENT *clts, *clt, *c;
    char cin[12], conf[10];
    int j;

    printf("Donner le cin du client a supprimer: ");
    fgets(cin, 12, stdin);
    if ((recherche_clt(clients, n, cin) == -1))
    {
        printf("le client n'existe pas.\nTapez n'importe quelle touche pour retourner au menu.");
        getchar();
        return clients;
    }
    else
    {
        j = recherche_clt(clients, n, cin);
        clt = clients + j;
        affich_clt(clt);
        printf("Etes vous sur que vous voulez supprimer ce cienlt?\nTapez oui pour confirmer. ");
        fgets(conf, 10, stdin);
        if (strcmp(conf, "oui"))
        {
            clts = (CLIENT *)malloc((n - 1) * sizeof(CLIENT));
            for (int i = 0, k = 0; i < n - 1; k++)
            {
                clt = clts + i;
                if (k != j)
                {
                    c = clients + k;
                    strcpy(clt->cin, c->cin);
                    strcpy(clt->nom, c->nom);
                    strcpy(clt->prenom, c->prenom);
                    i++;
                }
            }
        }
        else
        {
            printf("Vous n'avez pas confirmez la suppression.\nTapez n'importe quelle touche pour retourner au menu.");
            getchar();
            return clients;
        }
    }
    n--;
    *nb_client = n;
    return clts;
}

//supprimer voiture
VOITURE *supprimer_voiture(VOITURE *voitures, int *nb_voiture)
{
    int n = *nb_voiture, i, j, k;
    VOITURE *voits, *voit, *v;
    char num[15], conf[10];

    printf("Donner le numero de la voiture a supprimer: ");
    fgets(num, 15, stdin);
    if ((recherche_voit(voitures, n, num) == -1))
    {
        printf("la voiture n'existe pas.\nTapez n'importe quelle touche pour retourner au menu.");
        getchar();
        return voitures;
    }
    else
    {

        j = recherche_voit(voitures, n, num);
        voit = voitures + j;
        affich_voit(voit);
        printf("Etes vous sur que vous voulez supprimer cette voiture?\nTapez oui pour confirmer. ");
        fgets(conf, 10, stdin);
        if (strcmp(conf, "oui"))
        {
            voits = (VOITURE *)malloc((n - 1) * sizeof(VOITURE));
            for (int i = 0, k = 0; i < n - 1; k++)
            {
                voit = voits + i;
                if (k != j)
                {
                    v = voitures + k;
                    strcpy(voit->marque, v->marque);
                    strcpy(voit->model, v->model);
                    strcpy(voit->numero, v->numero);
                    strcpy(voit->couleur, v->couleur);
                    voit->ppj = v->ppj;
                    voit->assurance = v->assurance;
                    i++;
                }
            }
        }
        else
        {
            printf("Vous n'avez pas confirmez la suppression.\nTapez n'importe quelle touche pour retourner au menu.");
            getchar();
            return voitures;
        }
    }
    n--;
    *nb_voiture = n;
    return voits;
}
//supprimer reservation
RESERVATION *supprimer_reservation(RESERVATION *reservations, int *nb_res)
{
    RESERVATION *tab_res, *res, *r;
    int i, j, k, n = *nb_res;
    char conf[10];
    printf("Liste de reservations : \n");
    for (int l = 0; l < n; l++)
    {
        r = reservations + l;
        printf("%i - ", l + 1);
        affich_res(r);
    }
    printf("Donner le numero de reservation que vous voulez annuler : ");
    scanf("%i", &j);
    getchar();
    if (j > n)
    {
        printf("Cette Reservation n'existe pas.\nTapez n'importe quelle touche pour retourner au menu.");
        return reservations;
    }
    else
    {
        j--;
        r = reservations + j;
        affich_res(r);
        printf("Etes vous sur que vous voulez supprimer cette reservation?\nTapez oui pour confirmer. ");
        fgets(conf, 10, stdin);
        if (strcmp(conf, "oui"))
        {
            tab_res = (RESERVATION *)malloc((n - 1) * sizeof(RESERVATION));
            for (i = 0, k = 0; i < n - 1; k++)
            {
                res = tab_res + i;
                if (k != j)
                {
                    r = reservations + k;
                    res->duree = r->duree;
                    res->ddl = r->ddl;
                    res->dfl = r->dfl;
                    res->voiture = r->voiture;
                    res->client = r->client;
                    res->facture = r->facture;
                    res->paye = r->paye;
                    i++;
                }
            }
        }
        else
        {
            printf("Vous n'avez pas confirmez la suppression.\nTapez n'importe quelle touche pour retourner au menu.");
            getchar();
            return reservations;
        }
    }
    n--;
    *nb_res = n;
    return tab_res;
}
int comp_date(DATE *date1, DATE *date2)
{
    if (date1->annee > date2->annee)
    {
        return 1;
    }
    else if (date1->annee < date2->annee)
    {
        return -1;
    }
    else
    {
        if (date1->mois > date2->mois)
        {
            return 1;
        }
        else if (date1->mois < date2->mois)
        {
            return -1;
        }
        else
        {
            if (date1->jour > date2->jour)
            {
                return 1;
            }
            else if (date1->jour < date2->jour)
            {
                return -1;
            }
            else
            {
                return 0;
            }
        }
    }
}
