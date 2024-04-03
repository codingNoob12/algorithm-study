from typing import *


class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        for ch in s:
            if ch in ('(', '[', '{',):
                stack.append(ch)
            else:
                if not stack:
                    return False
                open_pair = stack.pop()
                if (open_pair != '(' or ch != ')') and \
                        (open_pair != '{' or ch != '}') and \
                        (open_pair != '[' or ch != ']'):
                    return False
        return not stack


s = Solution()
print(s.isValid("(]"))
