#!/usr/bin/python3
"""
0-prime_game

Solve the Prime Game: Maria and Ben alternately pick primes from
``{1, 2, ..., n}``. When a prime ``p`` is picked, ``p`` and all of its
multiples are removed. The player unable to move loses. Maria plays
first.

Key observation
---------------
A composite number is never pickable (only primes are). When a prime
``p`` is removed, the only other numbers removed are multiples of
``p``, all of which are composites — they were never going to be
picked anyway. Therefore each prime ``<= n`` ends up being picked
exactly once, in some order, and the total number of moves in a round
is exactly ``pi(n)`` (the number of primes ``<= n``).

Maria wins a round iff ``pi(n)`` is odd.
"""


def isWinner(x, nums):
    """Return the name of the player with the most round wins.

    Args:
        x (int): number of rounds to play.
        nums (list[int]): value of ``n`` for each round.

    Returns:
        str | None: ``"Maria"``, ``"Ben"`` or ``None`` when the
        overall winner cannot be determined (tie, or invalid input).
    """
    if not nums or x <= 0:
        return None

    n_max = max(nums)
    sieve = [True] * (n_max + 1)
    if n_max >= 0:
        sieve[0] = False
    if n_max >= 1:
        sieve[1] = False
    i = 2
    while i * i <= n_max:
        if sieve[i]:
            for j in range(i * i, n_max + 1, i):
                sieve[j] = False
        i += 1

    prime_count = [0] * (n_max + 1)
    for k in range(1, n_max + 1):
        prime_count[k] = prime_count[k - 1] + (1 if sieve[k] else 0)

    maria = 0
    ben = 0
    for n in nums[:x]:
        if n < 2 or prime_count[n] % 2 == 0:
            ben += 1
        else:
            maria += 1

    if maria > ben:
        return "Maria"
    if ben > maria:
        return "Ben"
    return None
