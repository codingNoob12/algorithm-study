from typing import *
import collections


class Solution:
    def numJewelsInStones(self, jewels: str, stones: str) -> int:
        return sum(stone in jewels for stone in stones)


print(Solution().numJewelsInStones("aA", "aAAbbbb"))
