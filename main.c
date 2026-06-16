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

    TPolynome *derivee = (TPolynome*)malloc(sizeof(TPolynome));
    if (derivee == NULL){
        return -1;
    }

    initialisation(polynome1);
    initialisation(polynome2);
    initialisation(somme);
    initialisation(difference);
    initialisation(derivee);

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
                for (int i = 1 ; i <= degreP1 + 1 ; i++){
                   
                    printf("Entrez l'élément %d : \n",i);
                    printf("Coefficient : \n");
                    scanf("%d",&coef);
                    printf("Degré : \n");
                    scanf("%d",&deg);
                    insererDansListe(polynome1 , coef , deg);
                }
                break;
            case 2:
                printf("-----INSERTION DU 2eme POLYNOME----- \n");
                do{
                    printf("Veuillez rentrer le degré du polynome \n");
                    scanf("%d",&degreP2);
                }while(degreP2 < 0);

                printf("Veuillez remplir dans l'ordre décroissant\n\n");
                for (int i = 1 ; i <= degreP2 + 1 ; i++){
                    printf("Entrez l'élément %d : \n",i);
                    printf("Coefficient : \n");
                    scanf("%d",&coef);
                    printf("Degré : \n");
                    scanf("%d",&deg);
                    insererDansListe(polynome2 , coef , deg);
                }
                break;
                
            case 3:
                printf("-----ADDITION DE POLYNOMES-----\n");
                additionPolynome(polynome1 , polynome2 ,somme);
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
                    soustractionPolynome(polynome1 , polynome2, difference);
                    printf("Après soustraction :\n");
                    affichage(difference);
                }
                else{
                    soustractionPolynome(polynome1 , polynome2, difference);
                    printf("Après soustraction :\n");
                    affichage(difference);
                }
                break;

            case 5:
                printf("-----DERIVEES-----\n");

                printf("Dérivée du polynome 1 :\n");
                deriveePolynome(polynome1 ,derivee);
                affichage(derivee);
                initialisation(derivee);

                printf("Dérivée du polynome 2 :\n");
                deriveePolynome(polynome2 , derivee);
                affichage(derivee);
                initialisation(derivee);

                printf("Dérivée de la somme :\n");
                deriveePolynome(somme , derivee);
                affichage(derivee);
                initialisation(derivee);

                printf("Dérivée de la différence :\n");
                deriveePolynome(difference , derivee);
                affichage(derivee);
                break;

            case 6:
                printf("-----AFFICHAGE-----\n\n");

                printf("Polynome 1 :\n");
                affichage(polynome1 );
                printf("Polynome 2 :\n");
                affichage(polynome2 );
                printf("Somme :\n");
                affichage(somme);
                printf("Différence :\n");
                affichage(difference);
                break;

            case 7:
                libererPolynome(polynome1);
                libererPolynome(polynome2);
                libererPolynome(somme);
                libererPolynome(difference);
                libererPolynome(derivee);

                printf("Au revoir !\n");
                break;
                
            default:
                printf("Choix invalide\n");
                
        }
    }while(choix != 7);

    return 0;
}