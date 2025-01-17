
# Projet - Automate et Analyseur Syntaxique

## Description

Ce projet implémente un automate et un analyseur syntaxique pour reconnaître et évaluer des expressions arithmétiques simples. Il utilise un lexer pour analyser les chaînes de caractères en entrée, des états pour définir le comportement de l'automate, et un automate pour gérer les transitions et effectuer les réductions nécessaires.

### Fonctionnalités principales :
- Reconnaissance de chaînes représentant des expressions arithmétiques.
- Calcul de la valeur des expressions reconnues.
- Support des opérateurs : `+`, `*`, et des parenthèses `( )`.
- Gestion des erreurs syntaxiques.

---

## Structure du projet

- **`main.cpp`** : Point d'entrée du programme. Lit la chaîne en entrée et initialise l'automate.
- **`lexer.cpp` / `lexer.h`** : Analyseur lexical qui décompose la chaîne en symboles (tokens).
- **`automate.cpp` / `automate.h`** : Automate responsable de la gestion des transitions et des réductions.
- **`etat.cpp` / `etat.h`** : Définitions des différents états de l'automate.
- **`symbole.cpp` / `symbole.h`** : Définitions des symboles utilisés par l'automate, y compris les entiers et les non-terminaux.

---

## Installation et Compilation

### Prérequis
- Un compilateur supportant C++11 ou une version ultérieure (par exemple, `g++`).
- Make (optionnel pour simplifier la compilation).

### Compilation
Pour compiler le projet, utilisez la commande suivante :
```bash
make
```

Si vous ne disposez pas d'un fichier `Makefile`, vous pouvez compiler manuellement avec :
```bash
g++ -std=c++11 -o automate main.cpp lexer.cpp symbole.cpp automate.cpp etat.cpp
```

---

## Utilisation

### Lancement du programme
Exécutez le programme en fournissant une expression arithmétique comme argument :
```bash
./automate "(1+2)*(3+4)"
```

### Exemple de sortie
Pour l'entrée `(1+2)*(3+4)` :
```plaintext
Le mot "(1+2)*(3+4)" est reconnu, la valeur calculée est : 21
```

Pour une chaîne non reconnue, par exemple `(1+*3)` :
```plaintext
Erreur : Erreur de syntaxe
Le mot "(1+*3)" n'est pas reconnu.
```

---

## Structure des Classes

### `Automate`
Gère la pile des symboles (`symbolestack`) et la pile des états (`statestack`). Responsable des transitions, des réductions et de l'exécution globale de l'automate.

### `Etat`
Définit les comportements des états. Chaque état a une méthode `Transition` pour définir les actions à effectuer en fonction du symbole courant.

### `Lexer`
Analyseur lexical qui transforme une chaîne en symboles compréhensibles par l'automate.

### `Symbole`
Classe de base pour représenter les symboles. Les sous-classes incluent `Entier` (pour les nombres) et `NonTerminal`.

---

## Améliorations possibles

- Support d'autres opérateurs (ex. : division, soustraction).
- Gestion des priorités via un tableau de précédence.
- Meilleure gestion des erreurs avec des messages plus explicites.
- Tests unitaires pour valider les fonctionnalités.

---

## Auteur

Projet développé par **Chloé BUTTIGIEG** et **Leonardo HERON**.
