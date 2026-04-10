# Substring with Concatenated Words

## Description

Trouver toutes les positions dans une chaîne `s` où commence un
sous-mot qui est la **concaténation** de tous les mots d'un tableau
`words`, chacun utilisé exactement une fois, dans n'importe quel
ordre, et sans caractère intercalaire.

Tous les mots ont la **même longueur**.

## Prototype

```c
int *find_substring(char const *s, char const **words,
                    int nb_words, int *n);
```

- `s` : chaîne à analyser
- `words` : tableau de mots
- `nb_words` : nombre de mots dans `words`
- `n` : adresse où écrire la taille du tableau retourné
- Retourne un tableau alloué des indices de match (ou `NULL` si
  aucun match / échec d'allocation). `*n` est toujours mis à jour.

L'appelant est responsable de `free()` le tableau retourné.

## Contraintes

- Ubuntu 14.04 LTS, `gcc 4.8.4`
- Flags : `-Wall -Werror -Wextra -pedantic`
- Style Betty
- Pas de variable globale
- Pas plus de 5 fonctions par fichier
- Header `substring.h` avec include guard

## Algorithme

Soient `word_len` la longueur commune des mots et `total_len =
nb_words * word_len`.

Pour chaque position `i` de `0` à `strlen(s) - total_len` inclus :

1. Réinitialiser un tableau `used[nb_words]` à 0.
2. Découper la fenêtre `s[i..i+total_len]` en `nb_words` tranches de
   `word_len` caractères.
3. Pour chaque tranche, chercher dans `words` un mot **non encore
   consommé** qui matche exactement. Si trouvé, le marquer `used`.
   Sinon, la fenêtre échoue.
4. Si les `nb_words` tranches ont toutes trouvé un mot distinct, `i`
   est une position valide.

Le tableau `used` gère les **doublons** dans `words` (ex: `"good"`
présent deux fois).

Complexité : `O(|s| · nb_words² · word_len)` — suffisant pour les
tailles visées par l'exercice.

## Fichiers

| Fichier        | Rôle                                   |
|----------------|----------------------------------------|
| `substring.c`  | Implémentation (`find_substring` + helpers) |
| `substring.h`  | Prototype + include guard              |

## Compilation

```bash
gcc -Wall -Werror -Wextra -pedantic main.c substring.c -o substring
```

## Exemples

```bash
$ ./a.out barfoothefoobarman foo bar
Indices -> [0, 9]

$ ./a.out wordgoodgoodgoodbestword word good best word
Indices -> []

$ ./a.out wordgoodgoodgoodbestword word good best good
Indices -> [8]
```
