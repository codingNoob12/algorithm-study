from collections import deque
from typing import *


class Solution:
    def isPalindrome(self, s: str) -> bool:
        # declare a deque
        strs: Deque = deque()

        # if character is alphanumeric, append to deque
        for char in s:
            if char.isalnum():
                strs.append(char.lower())

        # check the string is palindrome
        while len(strs) > 1:
            if strs.pop() != strs.popleft():
                return False
        return True
