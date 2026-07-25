/*MAIN.C*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prototypes_polynomes.h"

int main()
{
    system("chcp 65001 > nul"); //Pour l'affichage des lettres avec accent

    int choix, degreP1 ,degreP2 , coef , deg , reponse;

    TPolynome *polynome1 = (TPolynome*)malloc(sizeof(TPolynome));
    if (polynome1 == NULL){
        return -1;
    }

    TPolynome *polynome2 = (TPolynome*)malloc(sizeof(TPolynome));
    if (polynome2== NULL){
        return -1;
    }

    TPolynome *somme = (TPolynome*)malloc(sizeof(TPolynome));
    if (somme == NULL){
        return -1;
    }

    TPolynome *difference = (TPolynome*)malloc(sizeof(TPolynome));
    if (difference == NULL){
        return -1;
    }

    TPolynome *deriv = (TPolynome*)malloc(sizeof(TPolynome));
    if (deriv == NULL){
        return -1;
    }

    initialisation(polynome1);
    initialisation(polynome2);
    initialisation(somme);
    initialisation(difference);
    initialisation(deriv);

    do{
        choix = menu();
        switch(choix)
        {
            case 1:
                printf("-----INSERTION DU 1er POLYNOME----- \n");
                do{
                    printf("Veuillez rentrer le degré du polynome \n");
                    scanf("%d",&degreP1);
                }while(degreP1 < 0);

                printf("Veuillez remplir dans l'ordre décroissant\n\n");
                for (int i = 0 ; i <= degreP1  ; i++){
                   
                    printf("Entrez l'élément %d : \n",i+1);
                    printf("Coefficient : \n");
                    scanf("%d",&coef);
                    printf("Degré : \n");
                    scanf("%d",&deg);
                    insertion(polynome1 , coef , deg);
                }
                break;
            case 2:
                printf("-----INSERTION DU 2eme POLYNOME----- \n");
                do{
                    printf("Veuillez rentrer le degré du polynome \n");
                    scanf("%d",&degreP2);
                }while(degreP2 < 0);

                printf("Veuillez remplir dans l'ordre décroissant\n\n");
                for (int i = 0 ; i <= degreP2 ; i++){
                    printf("Entrez l'élément %d : \n",i+1);
                    printf("Coefficient : \n");
                    scanf("%d",&coef);
                    printf("Degré : \n");
                    scanf("%d",&deg);
                    insertion(polynome2 , coef , deg);
                }
                break;
                
            case 3:
                printf("-----ADDITION DE POLYNOMES-----\n");
                addition(polynome1 , polynome2 ,somme);
                printf("Après addition :\n");
                affichage(somme);
                break;
                
                
            case 4:
                printf("-----SOUSTRACTION DE POLYNOMES-----\n");
                printf("Dans quel ordre voulez vous effectuer la soustraction ?\n");
                printf("Polynome 1 - Polynome 2 , Tapez 0\n");
                printf("Polynome 2 - Polynome 1 , Tapez 1\n");
                scanf("%d",&reponse);
                if (reponse == 0){
                    soustraction(polynome1 , polynome2, difference);
                    printf("Après soustraction :\n");
                    affichage(difference);
                }
                else{
                    soustraction(polynome2 , polynome1, difference);
                    printf("Après soustraction :\n");
                    affichage(difference);
                }
                break;

            case 5:
                printf("-----DERIVEES-----\n");

                printf("Dérivée du polynome 1 :\n");
                derivee(polynome1 ,deriv);
                affichage(deriv);
                initialisation(deriv);

                printf("Dérivée du polynome 2 :\n");
                derivee(polynome2 , deriv);
                affichage(deriv);
                initialisation(deriv);

                printf("Dérivée de la somme :\n");
                derivee(somme , deriv);
                affichage(deriv);
                initialisation(deriv);

                printf("Dérivée de la différence :\n");
                derivee(difference , deriv);
                affichage(deriv);
                break;

            case 6:
                printf("-----AFFICHAGE-----\n\n");

                printf("POLYNOME 1 :\n");
                affichage(polynome1 );
                printf("POLYNOME 2 :\n");
                affichage(polynome2 );
                printf("SOMME :\n");
                affichage(somme);
                printf("DIFFERENCE :\n");
                affichage(difference);
                break;

            case 7:
                liberation(polynome1);
                liberation(polynome2);
                liberation(somme);
                liberation(difference);
                liberation(deriv);

                printf("Au revoir !\n");
                break;
                
            default:
                printf("Choix invalide\n");
                
        }
    }while(choix != 7);

    return 0;
}