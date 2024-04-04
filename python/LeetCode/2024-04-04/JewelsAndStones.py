from typing import *
import collections


class Solution:
    def numJewelsInStones(self, jewels: str, stones: str) -> int:
        counter, result = collections.Counter(stones), 0
        for jewel in jewels:
            result += counter[jewel]
        return result


print(Solution().numJewelsInStones("aA", "aAAbbbb"))
