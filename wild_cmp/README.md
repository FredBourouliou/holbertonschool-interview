# Wild Compare

## Description

Écriture d'une fonction qui compare deux chaînes de caractères et
retourne `1` si elles peuvent être considérées comme identiques,
sinon `0`.

La seconde chaîne peut contenir le caractère spécial `*`, qui peut
remplacer n'importe quelle sous-chaîne (y compris une chaîne vide).

## Prototype

```c
int wildcmp(char *s1, char *s2);
```

## Contraintes

- Allowed editors: `vi`, `vim`, `emacs`
- Compilation : Ubuntu 14.04 LTS, `gcc 4.8.4`
- Flags : `-Wall -Werror -Wextra -pedantic`
- Style Betty (`betty-style.pl`, `betty-doc.pl`)
- Pas de variables globales ni statiques
- Pas plus de 5 fonctions par fichier
- Bibliothèque standard interdite
- **Aucune boucle autorisée** (implémentation récursive)

## Fichiers

| Fichier        | Rôle                                        |
|----------------|---------------------------------------------|
| `0-wildcmp.c`  | Implémentation récursive de `wildcmp`       |
| `holberton.h`  | Prototype de la fonction                    |

## Algorithme

Approche récursive en trois cas :

1. Les deux chaînes sont vides → match (`1`).
2. `*s2 == '*'` :
   - Si `*` est le dernier caractère de `s2` → match (`1`).
   - Si `s1` est vide mais `s2` reste non vide après `*` → pas de match.
   - Sinon, essayer de consommer `*` (avancer `s2`) **ou** consommer
     un caractère de `s1` en gardant `*`.
3. Sinon, si `*s1 == *s2` et non nul, continuer avec `s1+1` et `s2+1`.
4. Dans tous les autres cas → pas de match (`0`).

## Compilation

```bash
gcc -Wall -Werror -Wextra -pedantic 0-main.c 0-wildcmp.c -o 0-wildcmp
```

## Exemple

```c
wildcmp("main.c", "*.c");      /* 1 */
wildcmp("main.c", "m*a*i*n*.*c*"); /* 1 */
wildcmp("main.c", "m.*c");     /* 0 */
wildcmp("abc", "*b");          /* 0 */
```
