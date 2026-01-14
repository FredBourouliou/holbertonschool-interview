# Count it!

This project contains a recursive function that queries the Reddit API, parses the titles of all hot articles in a given subreddit, and prints a sorted count of given keywords.

## Requirements

- Python 3.4.3+
- Requests module

## Usage

```bash
./0-main.py <subreddit> '<space-separated keywords>'
```

## Example

```bash
$ python3 0-main.py programming 'python java javascript'
java: 27
javascript: 20
python: 17
```

## Features

- Case-insensitive keyword matching
- Handles duplicate keywords (counts are summed)
- Results sorted by count (descending), then alphabetically
- Handles invalid subreddits gracefully (no output)
- Does not follow redirects for invalid subreddits
- Recursive pagination through all hot articles
