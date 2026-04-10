# Simple RegEx

## Description

Implémentation minimale d'un moteur d'expressions régulières supportant
deux métacaractères :

- `.` — correspond à n'importe quel caractère unique.
- `*` — correspond à zéro ou plusieurs occurrences du caractère
  précédent.

Le match doit couvrir **toute** la chaîne d'entrée (pas de match
partiel).

## Prototype

```c
int regex_match(char const *str, char const *pattern);
```

- `str` : chaîne à analyser (ne contient ni `.` ni `*`).
- `pattern` : expression régulière (peut contenir `.` et `*`).
- Retourne `1` si le motif correspond à la chaîne, `0` sinon.

## Contraintes

- Ubuntu 14.04 LTS, `gcc 4.8.4`
- Flags : `-Wall -Wextra -Werror -pedantic`
- Style Betty (`betty-style.pl`, `betty-doc.pl`)
- Pas de variable globale
- Pas plus de 5 fonctions par fichier
- Header file `regex.h` avec include guard

## Fichiers

| Fichier    | Rôle                                 |
|------------|--------------------------------------|
| `regex.c`  | Implémentation de `regex_match`      |
| `regex.h`  | Prototype + include guard `REGEX_H`  |

## Algorithme

Approche récursive, inspirée du mini-regex de Brian Kernighan / Rob Pike :

1. **Pattern vide** : match si, et seulement si, la chaîne est aussi vide.
2. **Second caractère du pattern = `*`** (ex. `c*`) :
   - Essayer de sauter `c*` complètement (zéro occurrence).
   - Sinon, si le caractère courant de `str` match `c` (ou `c == '.'`),
     consommer un caractère de `str` en gardant le même pattern.
3. **Cas classique** : si les caractères courants matchent (égalité
   stricte ou `.`), avancer les deux pointeurs.
4. **Sinon** : pas de match (`0`).

## Compilation

```bash
gcc -Wall -Wextra -Werror -pedantic main.c regex.c -o regex
```

## Exemple

```c
regex_match("Holberton", "Z*H.*");       /* 1 */
regex_match("Holberton", "Z*H.*o");      /* 0 — 'n' reste non consommé */
regex_match("Holberton", "Z*H.*o.");     /* 1 */
regex_match("HH", "H*");                 /* 1 */
regex_match("HH", "H");                  /* 0 — match partiel interdit  */
```
