/*PROTOTYPES_POLYNOMES.H*/

#ifndef PROTOTYPES_POLYNOMES_H_INCLUDED
#define PROTOTYPES_POLYNOMES_H_INCLUDED


typedef struct TMonome TMonome;
struct TMonome{
    int coef;
    int degre;
    TMonome *suivant;
};

typedef struct TPolynome TPolynome;
struct TPolynome{
    TMonome *debut;
    TMonome *fin;
    int taille;
};

int menu();

void initialisation(TPolynome *polynome);

int insererDansListe(TPolynome *liste , int coef , int degre);

int additionPolynome(TPolynome *liste1 , TPolynome *liste2 , TPolynome *liste3);

int soustractionPolynome(TPolynome *liste1 , TPolynome *liste2 , TPolynome *liste3);

int deriveePolynome(TPolynome *listeX , TPolynome *listeY);

void affichage (TPolynome *liste);

void libererPolynome(TPolynome *liste);

#endif // PROTOTYPES_POLYNOMES_H_INCLUDED


