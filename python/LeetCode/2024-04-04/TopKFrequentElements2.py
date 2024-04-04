from typing import *
import collections


class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        freqs = collections.defaultdict(int)
        for n in nums:
            freqs[n] += 1

        result = [key for key, value in sorted(freqs.items(), key=lambda x: (-x[1], x[0]))]
        return result[:k]


print(Solution().topKFrequent([1, 1, 1, 2, 2, 3], 2))
