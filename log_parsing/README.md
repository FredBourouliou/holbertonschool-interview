# Log Parsing

This project implements a log parsing script that reads stdin line by line and computes metrics.

## Files

- `0-stats.py`: Main script that parses log entries and computes statistics
- `0-generator.py`: Test generator that creates random log entries

## Usage

```bash
./0-generator.py | ./0-stats.py
```

## Requirements

- Ubuntu 14.04 LTS
- Python 3.4.3
- PEP 8 style (version 1.7.x)

## Functionality

The script:
- Reads log entries from stdin
- Parses entries matching the format: `<IP Address> - [<date>] "GET /projects/260 HTTP/1.1" <status code> <file size>`
- Computes total file size and counts status codes
- Prints statistics every 10 lines and on keyboard interruption (CTRL+C)
- Handles status codes: 200, 301, 400, 401, 403, 404, 405, 500