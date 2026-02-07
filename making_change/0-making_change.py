#!/usr/bin/python3
"""Module for making change problem"""


def makeChange(coins, total):
    """Determine fewest coins needed to meet a given total.

    Args:
        coins: list of coin values (integers > 0)
        total: target amount

    Returns:
        Fewest number of coins needed, or -1 if impossible.
    """
    if total <= 0:
        return 0

    dp = [float('inf')] * (total + 1)
    dp[0] = 0

    for coin in coins:
        for amount in range(coin, total + 1):
            dp[amount] = min(dp[amount], dp[amount - coin] + 1)

    return dp[total] if dp[total] != float('inf') else -1
