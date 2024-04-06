from typing import *
import itertools


class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        return [comb for k in range(len(nums) + 1) for comb in itertools.combinations(nums, k)]


print(Solution().subsets([0]))
