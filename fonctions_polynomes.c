/*FONCTIONS_POLYNOMES.C*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prototypes_polynomes.h"


/*fonction qui permet d'afficher le menu et qui retourne
le choix de l'utilisateur*/
int menu()
{
    int choix;
    printf("********MENU POLYNOMES**********\n");
    printf("1 - INSERTION DU PREMIER POLYNOME\n");
    printf("2 - INSERTION DU SECOND POLYNOME\n");
    printf("3 - ADDITION \n");
    printf("4 - SOUSTRACTION \n");
    printf("5 - DERIVEE \n");
    printf("6 - AFFICHAGE\n");
    printf("7 - QUITTER\n");
    do{
        printf("Faites votre choix :\n");
        scanf("%d",&choix);
    }while(choix < 1 || choix > 7);

    return choix;
}

/*Fonction permettant d'initialiser les listes*/
void initialisation(TPolynome *polynome)
{
    polynome -> debut = NULL;
    polynome -> fin = NULL;
    polynome -> taille = 0;

}

/*Fonction permettant l'insertion des monomes de chaque polynome*/
int insererDansListe(TPolynome *polynome , int coef , int degre)
{
    if (polynome -> taille == 0){
        TMonome *monome = (TMonome*)malloc(sizeof(TMonome));
        if (monome == NULL){
            return -1;
        }

        monome-> coef = coef;
        monome-> degre = degre;
        monome -> suivant = NULL;
        polynome -> debut = monome;
        polynome -> fin = monome;
        polynome -> taille++;

    return 0;
    }

    else{
        TMonome *monome = (TMonome*)malloc(sizeof(TMonome));
        if (monome == NULL){
            return -1;
        }

        monome -> coef = coef;
        monome -> degre = degre;
        monome -> suivant = NULL;
        polynome -> fin -> suivant = monome;
        polynome -> fin = monome;
        polynome -> taille ++;

    return 0;

    }

}

/*Fonction permettant l'addition de deux polynomes*/
int additionPolynome(TPolynome *polynome1 , TPolynome *polynome2 , TPolynome *somme)
{

    if (polynome1 -> taille == 0 || polynome2 -> taille == 0){
        return -1;
    }

    TMonome  *courant1 = polynome1 -> debut ;
    TMonome  *courant2 = polynome2 -> debut ;

    while(courant1 != NULL && courant2 != NULL)
    {
        if (courant1 -> degre == courant2 -> degre){
            insererDansListe(somme , courant1->coef + courant2->coef ,courant1->degre);
            courant1 = courant1 -> suivant;
            courant2 = courant2 -> suivant;
        }
        else if(courant1 -> degre > courant2 -> degre){
            insererDansListe(somme , courant1 -> coef , courant1 -> degre);
            courant1 = courant1 -> suivant;
        }
        else{
            insererDansListe(somme , courant2 -> coef , courant2 -> degre);
            courant2 = courant2 -> suivant;
        }
    }

    while(courant1 != NULL)
    {
        insererDansListe(somme , courant1 -> coef , courant1 -> degre);
        courant1 = courant1 -> suivant;
    }

    while (courant2 != NULL)
    {
        insererDansListe(somme , courant2 -> coef , courant2 -> degre);
        courant2 = courant2 -> suivant ;
    }

    return 0;

} 

/*Fonction permettant la soustraction de deux polynomes*/
int soustractionPolynome(TPolynome *polynome1 , TPolynome *polynome2 , TPolynome *difference)
{
    if (polynome1 -> taille == 0 || polynome2 -> taille == 0){
        return -1;
    }

    TMonome *courant1 = polynome1-> debut ;
    TMonome *courant2 = polynome2 -> debut ;

    while(courant1 != NULL && courant2 != NULL)
    {
        if (courant1 -> degre == courant2 -> degre){
            insererDansListe(difference , courant1->coef - courant2->coef ,courant1->degre);
            courant1 = courant1 -> suivant;
            courant2 = courant2 -> suivant;
        }
        else if(courant1 -> degre > courant2 -> degre){
            insererDansListe(difference , courant1 -> coef , courant1 -> degre);
            courant1 = courant1 -> suivant;
        }
        else{
            insererDansListe(difference , (courant2 -> coef)*-1 , courant2 -> degre);
            courant2 = courant2 -> suivant;
        }
    }

    while(courant1 != NULL)
    {
        insererDansListe(difference , courant1 -> coef , courant1 -> degre);
        courant1 = courant1 -> suivant;
    }

    while (courant2 != NULL)
    {
        insererDansListe(difference , (courant2 -> coef)*-1 , courant2 -> degre);
        courant2 = courant2 -> suivant ;
    }

    return 0;

} 

/*Fonction permettant de dériver les polynomes*/
int deriveePolynome(TPolynome *polynome , TPolynome *derivee)
{
    if (polynome -> taille == 0){
        return -1;
    }

    TMonome *courant = polynome->debut ;
    while(courant != NULL)
    {
        if (courant->degre > 0){
            insererDansListe(derivee , (courant->coef * courant->degre) , courant->degre - 1);
        }
        courant = courant -> suivant;
    }
    return 0;
} 

/*Affichage général*/
void affichage (TPolynome *polynome){
    if (polynome -> taille == 0){
        printf("La liste est vide pour le moment \n");
    }

    TMonome *courant = polynome -> debut ;
    while (courant != NULL){
        printf("(%dX^%d)",courant->coef , courant->degre);
        courant = courant -> suivant;
        if (courant != NULL){
            printf(" + ");
        }
        else{
            printf("\n");
        }
    }
} 

/*Fonction permettant de libérer la mémoire*/
void libererPolynome(TPolynome *polynome)
{
    TMonome *courant = polynome -> debut;
    while(courant != NULL){
        free(courant);
        courant = courant -> suivant;
    }

    free(polynome);

}


