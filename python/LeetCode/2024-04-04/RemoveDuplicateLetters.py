from typing import *


class Solution:
    def removeDuplicateLetters(self, s: str) -> str:
        for char in sorted(set(s)):
            suffix = s[s.find(char):]
            if set(suffix) == set(s):
                return char + self.removeDuplicateLetters(suffix.replace(char, ''))
        return ''


s = Solution()
print(s.removeDuplicateLetters("cbacdcbc"))
