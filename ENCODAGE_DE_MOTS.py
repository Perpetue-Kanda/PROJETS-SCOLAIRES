"""
Programme permettant de coder et de décoder un mot (Application des permutations en Structures Algébriques)
"""

def encodage(mot , pas):
    if not(isinstance(mot, str)):
        return "Le mot entré doit etre une chaine de caractère"

    elif not(isinstance(pas, int)):
        return "Le pas entré doit etre un entier"

    else:
        reponse = int(input("Voulez vous coder ou décoder le mot ? \nTapez 1 pour le coder , 2 pour le décoder: "))
        while reponse != 1 and reponse != 2:
            reponse = int(input("Reponse invalide ! Tapez 1 pour le coder , 2 pour le decoder: "))
        if reponse == 2:
            #Cette méthode permet d'inverser le pas
            pas = - pas

        alphabet = "abcdefghijklmnopqrstuvwxyz"
        alphabet_tronque = alphabet[pas:] + alphabet[:pas]

        #On prend en compte les lettres majuscules
        alphabet += alphabet.upper()
        alphabet_tronque += alphabet_tronque.upper()

        #On crée une correspondance entre les lettres de l'alphabet normal et les lettres de l'alphabet tronqué
        correspondance = str.maketrans(alphabet , alphabet_tronque)

        #On applique la modification au mot passé en paramètres
        mot_tronque = mot.translate(correspondance)
        return f"Après encodage: {mot_tronque}"

#Programme principal
mot = input("Veuillez entrer le mot à coder/décoder: ")
pas = int(input("Veuillez entrer le pas à appliquer: "))

print(f"Avant encodage: {mot}")

mot_modifie = encodage(mot , pas)
print(mot_modifie)