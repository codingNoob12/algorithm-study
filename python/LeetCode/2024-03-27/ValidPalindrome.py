import re


class Solution:
    def isPalindrome(self, s: str) -> bool:
        # converting all uppercase letters into lowercase letters
        s = s.lower()
        # removing all non-alphanumeric characters
        s = re.sub('[^a-z0-9]', '', s)

        # check it's palindrome
        return s == s[::-1]
