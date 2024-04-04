from typing import *
import collections


class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        chars, seen = collections.deque(), set()
        max_length = 0

        for char in s:
            if char not in seen:
                seen.add(char)
            else:
                while chars[0] != char:
                    seen.remove(chars.popleft())
                chars.popleft()
            chars.append(char)
            max_length = max(max_length, len(chars))
        return max_length


print(Solution().lengthOfLongestSubstring("pwwkew"))
