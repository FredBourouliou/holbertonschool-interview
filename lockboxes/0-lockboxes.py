#!/usr/bin/python3
"""Module for lockboxes problem"""


def canUnlockAll(boxes):
    """
    Determines if all boxes can be opened
    
    Args:
        boxes: list of lists, where each inner list contains keys to other boxes
    
    Returns:
        True if all boxes can be opened, else False
    """
    if not boxes:
        return False
    
    n = len(boxes)
    unlocked = set([0])  # Box 0 is always unlocked
    keys = set(boxes[0])  # Start with keys from box 0
    
    # Keep trying to unlock boxes while we have new keys
    while keys:
        # Try to unlock a box with one of our keys
        key = keys.pop()
        
        # Check if this key corresponds to a valid box that we haven't opened yet
        if key < n and key not in unlocked:
            unlocked.add(key)
            # Add new keys from this box
            for new_key in boxes[key]:
                if new_key not in unlocked:
                    keys.add(new_key)
    
    # Check if we unlocked all boxes
    return len(unlocked) == n