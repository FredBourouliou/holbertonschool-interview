# Sandpiles

## Description
Ce projet implémente un algorithme pour calculer la somme de deux piles de sable (sandpiles) et stabiliser le résultat selon les règles de l'automate cellulaire des piles de sable.

## Concept des Sandpiles
Une pile de sable est représentée par une grille 3x3 où chaque cellule contient un nombre de grains de sable. La pile est considérée comme **stable** lorsqu'aucune cellule ne contient plus de 3 grains.

### Règles de stabilisation (Toppling)
Lorsqu'une cellule contient plus de 3 grains :
- Elle perd 4 grains
- Chaque cellule adjacente (haut, bas, gauche, droite) reçoit 1 grain
- Les grains qui sortent de la grille sont perdus

## Fichiers
- `sandpiles.h` : Fichier d'en-tête contenant le prototype de la fonction
- `0-sandpiles.c` : Implémentation de la fonction `sandpiles_sum`
- `0-main.c` : Fichier de test principal
- `1-main.c` : Fichier de test alternatif

## Fonction principale
```c
void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
```
- Calcule la somme de deux piles de sable
- `grid1` : Première grille (modifiée pour contenir le résultat)
- `grid2` : Deuxième grille (non modifiée)
- Affiche les étapes intermédiaires de stabilisation

## Compilation
```bash
gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-sandpiles.c -o 0-sandpiles
```

## Utilisation
```bash
./0-sandpiles
```

## Exemple
Entrée :
```
3 3 3   1 3 1
3 3 3 + 3 3 3
3 3 3   1 3 1
```

Sortie avec étapes de stabilisation :
```
=
4 6 4
6 6 6
4 6 4
=
2 5 2
5 6 5
2 5 2
=
4 2 4
2 6 2
4 2 4
=
0 5 0
5 2 5
0 5 0
=
2 1 2
1 6 1
2 1 2
=
2 2 2
2 2 2
2 2 2
```

## Algorithme
1. **Addition** : Additionner élément par élément les deux grilles
2. **Vérification** : Vérifier si la grille résultante est stable
3. **Stabilisation** : Si instable, afficher l'état et effectuer le toppling
4. **Répétition** : Répéter jusqu'à obtenir une grille stable

## Complexité
- **Temps** : O(n) où n est le nombre d'itérations de stabilisation nécessaires
- **Espace** : O(1) - utilisation d'une grille temporaire 3x3 pour le toppling

## Auteur
Projet réalisé dans le cadre du curriculum Holberton School