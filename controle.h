#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

struct voiture
{
    char marque[30];
    char model[30];
    char numero[15];  // identifiant unique
    char couleur[15]; //couleur de la voiture
    float ppj;        //prix par jour
    float assurance;  //prix fixe d'assurance pour chaque locataire
};
typedef struct voiture VOITURE;

struct date
{
    int jour;
    int mois;
    int annee;
};
typedef struct date DATE;

struct client
{
    char cin[12];
    char nom[30];
    char prenom[30];
};
typedef struct client CLIENT;

struct reservation
{
    int duree;        //duree de la location
    DATE *ddl;        //date de debut de location
    DATE *dfl;        //date de fin de location calculé automatiquement ddl +duree
    VOITURE *voiture; //voiture loue par le client
    CLIENT *client;   //client
    float facture;    // prix total de la location total=nbjours *ppj+assurence
    bool paye;        //le client a paye la facture ou non
};

typedef struct reservation RESERVATION;

//validation de la date
bool cntr_date(int j, int m, int a)
{
    switch (m)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        if ((j > 31) || (j < 1))
        {
            printf("jour invalide. Le jour doit etre compris entre 1 et 31. Reesayez \n");
            return false;
        }

        break;
    case 2:
        if (a % 4 == 0)
        {
            if ((j > 29) || (j < 1))
            {
                printf("jour invalide. Le jour doit etre compris entre 1 et 29. Reesayez \n");
                return false;
            }
        }
        else
        {
            if ((j > 28) || (j < 1))
            {
                printf("jour invalide. Le jour doit etre compris entre 1 et 28. Reesayez \n");
                return false;
            }
        }
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        if ((j > 30) || (j < 1))
        {
            printf("jour invalide. Le jour doit etre compris entre 1 et 30. Reesayez \n");
            return false;
        }
        break;
    default:
        printf("mois invalide. Reesayez \n");
        return false;
        break;
    }
    return true;
}
//validation num cin
bool cntr_cin(char *cin)
{
    int len, i;
    len = strlen(cin);
    if (len != 9)
    {
        printf("Le numero de CIN doit contenir exactement 8 chiffres. Reesayez\n");
        return false;
    }
    else
    {
        for (i = 0; i < len - 1; i++)
        {
            if ((cin[i] < '0') || (cin[i] > '9'))
            {
                printf("Le numero de CIN ne doit contenir que des chiffres. Reesayez\n");
                return false;
            }
        }
    }
    return true;
}
//voiture unique:recherche selon num si la voiture existe
bool voiture_existe(VOITURE *tab_vt, int nb_vt, char *num)
{
    int i;
    VOITURE *voit;
    for (i = 0; i < nb_vt; i++)
    {
        voit = tab_vt + i;
        if (strcmp(num, voit->numero) == 0)
        {
            return true;
        }
    }
    return false;
}