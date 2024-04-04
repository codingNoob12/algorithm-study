from typing import *
import collections


class Solution:
    def numJewelsInStones(self, jewels: str, stones: str) -> int:
        freqs = collections.defaultdict(int)
        for stone in stones:
            freqs[stone] += 1

        count = 0
        for jewel in jewels:
            count += freqs[jewel]
        return count


print(Solution().numJewelsInStones("aA", "aAAbbbb"))
