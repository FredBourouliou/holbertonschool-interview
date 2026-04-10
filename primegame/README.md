# Prime Game

## Description

Maria et Ben jouent à tour de rôle à partir de l'ensemble
`{1, 2, ..., n}` : à chaque coup, le joueur choisit un **nombre
premier** encore présent et **retire ce premier ainsi que tous ses
multiples**. Maria joue en premier. Le joueur qui ne peut plus jouer
perd la partie.

On joue `x` manches, avec un `n` par manche (`nums[i]`). Renvoyer le
nom du joueur qui a gagné le plus de manches, ou `None` en cas
d'égalité (ou d'entrée invalide).

## Prototype

```python
def isWinner(x, nums):
```

## Observation clé

Un **composé** n'est jamais pickable (on doit choisir un premier).
Lorsqu'on enlève un premier `p`, les autres nombres enlevés sont les
multiples de `p` — tous composés, donc déjà non pickables. Retirer
les composés n'a donc aucun impact sur la suite du jeu.

Conséquence : chaque premier `≤ n` finira par être choisi
**exactement une fois**. Le nombre total de coups dans une manche
vaut exactement `π(n)` (le nombre de premiers `≤ n`).

- Si `π(n)` est **impair** → Maria joue le dernier coup, Ben ne peut
  pas jouer, **Maria gagne**.
- Si `π(n)` est **pair** (y compris 0) → **Ben gagne**.

## Algorithme

1. `n_max = max(nums)`.
2. Crible d'Ératosthène jusqu'à `n_max` → `O(n log log n)`.
3. Tableau de préfixe `prime_count[k] = π(k)` → `O(n)`.
4. Pour chaque manche, tester la parité de `prime_count[n]` et
   incrémenter le compteur du vainqueur.
5. Renvoyer le nom du joueur avec le plus de victoires, `None` si
   égalité.

Complexité globale : `O(n_max · log log n_max + x)`.

## Fichiers

| Fichier             | Rôle                      |
|---------------------|---------------------------|
| `0-prime_game.py`   | Implémentation `isWinner` |

## Exemple

```python
isWinner = __import__('0-prime_game').isWinner
print(isWinner(5, [2, 5, 1, 4, 3]))   # Ben
print(isWinner(3, [4, 5, 1]))          # Ben
```

### Trace pour `x=5, nums=[2, 5, 1, 4, 3]`

| n | π(n) | parité | vainqueur |
|---|------|--------|-----------|
| 2 | 1    | impair | Maria     |
| 5 | 3    | impair | Maria     |
| 1 | 0    | pair   | Ben       |
| 4 | 2    | pair   | Ben       |
| 3 | 2    | pair   | Ben       |

Maria 2, Ben 3 → **Ben**.
