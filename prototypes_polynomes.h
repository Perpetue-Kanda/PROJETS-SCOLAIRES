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

int insertion(TPolynome *polynome , int coef , int degre);

int addition(TPolynome *polynome1 , TPolynome *polynome2 , TPolynome *somme);

int soustraction(TPolynome *polynome1 , TPolynome *polynome2 , TPolynome *difference);

int derivee(TPolynome *polynome , TPolynome *deriv);

void affichage(TPolynome *polynome);

void liberation(TPolynome *polynome);

#endif // PROTOTYPES_POLYNOMES_H_INCLUDED


