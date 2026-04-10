# Pascal's Triangle

## Description

Implémentation en Python 3 d'une fonction qui construit le triangle
de Pascal de taille `n` sous forme de liste de listes d'entiers.

## Prototype

```python
def pascal_triangle(n):
```

- Retourne une liste vide si `n <= 0`.
- `n` est toujours un entier (aucune validation de type requise).

## Principe

Chaque ligne `i` du triangle de Pascal se construit à partir de la
ligne précédente :

- les bords valent toujours `1` ;
- chaque valeur interne est la somme des deux valeurs adjacentes
  de la ligne précédente : `row[j] = prev[j - 1] + prev[j]`.

```
n = 5
[1]
[1, 1]
[1, 2, 1]
[1, 3, 3, 1]
[1, 4, 6, 4, 1]
```

## Fichiers

| Fichier                | Rôle                                    |
|------------------------|-----------------------------------------|
| `0-pascal_triangle.py` | Implémentation de `pascal_triangle(n)`  |

## Exécution

```bash
./0-main.py
```

## Exemple

```python
pascal_triangle = __import__('0-pascal_triangle').pascal_triangle
print(pascal_triangle(5))
# [[1], [1, 1], [1, 2, 1], [1, 3, 3, 1], [1, 4, 6, 4, 1]]
```
