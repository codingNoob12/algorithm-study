from typing import *
import collections


class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        counter = collections.Counter(nums)
        return [num for num, count in counter.most_common(k)]


print(Solution().topKFrequent([1, 1, 1, 2, 2, 3], 2))
