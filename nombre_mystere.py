import random

rep = "o"

while rep.lower() != "n":
    mystere = random.randint(1, 100)
    tent = 0

    print("\n******* DEVINETTE *******")

    nombre = int(input("Veuillez entrer un nombre entier entre 1 et 100 \nVous avez 5 tentatives : "))
    tent += 1

    while nombre != mystere and tent < 5:
        if nombre < mystere:
            nombre = int(input("Trop petit ! \nRéessayez : "))
        else:
            nombre = int(input("Trop grand ! \nRéessayez : "))
        tent += 1

    if nombre == mystere:
        print(f"Trouvé ! Après {tent} tentative(s)")
    else:
        print(f"Perdu ! Le nombre mystère était {mystere}.")

    rep = input("Voulez-vous rejouer ? (o/n) : ")

if rep.lower() == "n":
    print("A bientot !")


