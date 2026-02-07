#!/usr/bin/python3
import subprocess
import signal
import time

# Start the stats script
proc = subprocess.Popen(['python3', '0-stats.py'], stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)

# Send some test data
test_lines = [
    '192.168.1.1 - [2024-01-01 12:00:00] "GET /projects/260 HTTP/1.1" 200 512\n',
    '192.168.1.2 - [2024-01-01 12:00:01] "GET /projects/260 HTTP/1.1" 404 256\n',
    '192.168.1.3 - [2024-01-01 12:00:02] "GET /projects/260 HTTP/1.1" 500 128\n',
]

for line in test_lines:
    proc.stdin.write(line)
    proc.stdin.flush()
    time.sleep(0.1)

# Send SIGINT
proc.send_signal(signal.SIGINT)

# Get output
try:
    stdout, stderr = proc.communicate(timeout=1)
    print("Output:")
    print(stdout)
    if stderr:
        print("Errors:")
        print(stderr)
except subprocess.TimeoutExpired:
    proc.kill()
    print("Process did not terminate properly")