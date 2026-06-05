#!/usr/bin/python3
"""Count keywords in hot Reddit articles recursively"""
import requests


def count_words(subreddit, word_list, after=None, counts=None):
    """
    Recursively fetch hot posts and count keyword occurrences.
    """

    if counts is None:
        counts = {}
        for word in word_list:
            counts[word.lower()] = 0

    url = f"https://www.reddit.com/r/{subreddit}/hot.json"

    headers = {"User-Agent": "linux:count_words:v1.0"}

    params = {
        "limit": 100,
        "after": after
    }

    response = requests.get(
        url,
        headers=headers,
        params=params,
        allow_redirects=False
    )
    if response.status_code != 200:
        return

    data = response.json()["data"]

    for post in data["children"]:
        words = post["data"]["title"].lower().split()

        for word in words:
            clean = "".join(
                c for c in word
                if c.isalnum()
            )

            if clean in counts:
                counts[clean] += 1

    if data["after"] is not None:
        return count_words(
            subreddit,
            word_list,
            data["after"],
            counts
        )

    duplicates = {}

    for word in word_list:
        word = word.lower()
        duplicates[word] = duplicates.get(word, 0) + 1

    results = []

    for word, count in counts.items():
        total = count * duplicates[word]

        if total > 0:
            results.append((word, total))

    results.sort(
        key=lambda x: (-x[1], x[0])
    )

    for word, count in results:
        print("{}: {}".format(word, count))
