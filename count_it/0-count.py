#!/usr/bin/python3
"""
Module to count keywords in Reddit hot article titles
"""
import requests


def count_words(subreddit, word_list, after=None, word_count=None):
    """
    Recursively queries the Reddit API, parses the title of all hot articles,
    and prints a sorted count of given keywords (case-insensitive).

    Args:
        subreddit: The subreddit to query
        word_list: List of keywords to count
        after: The "after" parameter for pagination (used in recursion)
        word_count: Dictionary to store word counts (used in recursion)
    """
    if word_count is None:
        word_count = {}
        for word in word_list:
            word_lower = word.lower()
            if word_lower in word_count:
                word_count[word_lower] += 0
            else:
                word_count[word_lower] = 0

    url = "https://www.reddit.com/r/{}/hot.json".format(subreddit)
    headers = {"User-Agent": "linux:count_words:v1.0 (by /u/holberton)"}
    params = {"limit": 100}
    if after:
        params["after"] = after

    try:
        response = requests.get(
            url,
            headers=headers,
            params=params,
            allow_redirects=False
        )

        if response.status_code != 200:
            return

        data = response.json()
        children = data.get("data", {}).get("children", [])

        for child in children:
            title = child.get("data", {}).get("title", "")
            title_words = title.lower().split()

            for title_word in title_words:
                for word in word_list:
                    if word.lower() == title_word:
                        word_count[word.lower()] += 1

        after = data.get("data", {}).get("after")

        if after:
            return count_words(subreddit, word_list, after, word_count)
        else:
            sorted_words = sorted(
                word_count.items(),
                key=lambda x: (-x[1], x[0])
            )
            for word, count in sorted_words:
                if count > 0:
                    print("{}: {}".format(word, count))

    except Exception:
        return
