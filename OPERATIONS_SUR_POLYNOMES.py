"""
Ce programme permet d'effectuer quelques opérations mathématiques par rapport
aux polynomes du n-ième degré
"""

#Fonction de création d'un polynome
def creation():
    polynome = []
    deg = int(input("Entrez le degré du polynome : "))
    while deg < 0:
        deg = int(input("Le degré du polynome doit etre supérieur ou égal à zéro : "))

    for i in range (deg+1):
        coef = int(input(f"Veuillez entrer le coefficient du monome de degré {i} : "))
        polynome.append(coef)

    return polynome

#Fonction d'addition
def addition(polynome_1, polynome_2):
    somme = []
    if len(polynome_1) == len(polynome_2):
        for i in range(0, len(polynome_1)):
            for j in range(i, len(polynome_1)):
                if i != j:
                    continue
                else:
                    somme.append(polynome_1[i] + polynome_2[j])
    elif len(polynome_1) > len(polynome_2):
        for i in range(0, len(polynome_2)):
            for j in range(i, len(polynome_2)):
                if i != j:
                    continue
                else:
                    somme.append(polynome_1[i] + polynome_2[j])
        for k in range(len(polynome_1) - len(polynome_2) + 1, len(polynome_1)):
            somme.append(polynome_1[k])
    else:
        for i in range(0, len(polynome_1)):
            for j in range(i, len(polynome_1)):
                if i != j:
                    continue
                else:
                    somme.append(polynome_1[i] + polynome_2[j])
        for k in range(len(polynome_2) - len(polynome_1) + 1, len(polynome_2)):
            somme.append(polynome_2[k])

    return somme

#Fonction de soustraction
def soustraction(polynome_1, polynome_2):
    difference = []
    if len(polynome_1) == len(polynome_2):
        for i in range(0, len(polynome_1)):
            for j in range(i, len(polynome_1)):
                if i != j:
                    continue
                else:
                    difference.append(polynome_1[i] - polynome_2[j])
    elif len(polynome_1) > len(polynome_2):
        for i in range(0, len(polynome_2)):
            for j in range(i, len(polynome_2)):
                if i != j:
                    continue
                else:
                    difference.append(polynome_1[i] - polynome_2[j])
        for k in range(len(polynome_1) - len(polynome_2) + 1, len(polynome_1)):
            difference.append(polynome_1[k])
    else:
        for i in range(0, len(polynome_1)):
            for j in range(i, len(polynome_1)):
                if i != j:
                    continue
                else:
                    difference.append(polynome_1[i] - polynome_2[j])
        for k in range(len(polynome_2) - len(polynome_1) + 1, len(polynome_2)):
            difference.append(polynome_2[k] * -1)

    return difference

#Fonction d'affichage
def affichage(polynome):
    i = 0
    while i < len(polynome) :
        print(f"{polynome[i]}X^{i}" , end = " ")
        i += 1
        if i < len(polynome):
            print("+",end = " ")
        else:
            print("\n")


#MENU PRINCIPAL (Test de toutes les fonctions)

print("CREATION DU PREMIER POLYNOME... ")
poly_1 = creation()
affichage(poly_1)

print("CREATION DU SECOND POLYNOME... ")
poly_2 = creation()
affichage(poly_2)

print("CALCUL DE LA SOMME :")
la_somme = addition(poly_1, poly_2)
print("La somme est",end = " ")
affichage(la_somme)

print("CALCUL DE LA DIFFERENCE :")
print("Dans quel ordre voulez vous effectuer la différence ?")
print("Polynome 1 - Polynome 2 , Tapez 1")
print("Polynome 2 - Polynome 1 , Tapez 2")
reponse = int(input("Votrez choix : "))
while reponse != 1 and reponse != 2:
    reponse = int(input("Votrez choix : "))
if reponse == 1:
    la_difference = soustraction(poly_1, poly_2)
else:
    la_difference = soustraction(poly_2, poly_1)
print("La difference est", end = " ")
affichage(la_difference)