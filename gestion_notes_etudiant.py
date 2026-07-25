"""
Le programme ci-après permet la gestion des notes entrées par l'utilisateur
"""

#Cette fonction permet l'enregistrement des notes , qui sont par la suite stockées dans une liste
def saisie (notes):
    rep = "o"
    while rep.lower() == "o" :
        a = int(input("Entrez une note : "))
        while a < 0 or a > 20 :
            a = int(input("Entrez une note valide !: "))
        notes.append(a)
        rep = (input("Voulez vous continuer ? O / N : "))
        while rep.lower() != "o" and rep.lower() != "n" :
            rep = (input("Entrez une reponse valide ! O / N : "))

#Cette fonction permet l'affichage des notes
def affichage (notes):
    print("Voici les notes entrées : ")
    print(notes)

#Celle-ci calcule la moyenne
def moyenne(notes):
    somme = 0
    taille = 0
    for i in notes:
        somme += i
        taille += 1
    moy = somme / taille

    return moy

#Celle-là retourne la plus grande note parmi toutes celles entrées
def maximum(notes):
    maxi = notes[0]
    for i in notes:
        if i > maxi:
            maxi = i

    return maxi

#A contrario , cette fonction retourne la plus petite des notes
def minimum (notes):
    mini = notes[0]
    for i in notes:
        if i < mini:
            mini = i

    return mini

#La fonction générale qui regroupe toutes celles du dessus
def gestion_notes(notes):
    print("********* BIENVENUE *********")
    #saisie
    saisie(notes)

    #affichage
    affichage(notes)

    #moyenne
    moy = moyenne(notes)
    print(f"la moyenne est {moy}")

    #note maximale
    maxi = maximum(notes)
    print(f"la plus forte note est {maxi}")

    #note minimale
    mini = minimum(notes)
    print(f"La plus faible note est {mini}")

#appel de la fonction générale
notes = []
gestion_notes(notes)

#disons si la moyenne est supérieure ou égale à 10
moy = moyenne(notes)

if moy < 10 :
    print("La moyenne générale est inférieure à 10")
else:
    print("La moyenne générale est supérieure ou égale à 10")

