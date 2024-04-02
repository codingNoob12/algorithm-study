from typing import *


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        appear = {}
        for i, x in enumerate(nums):
            if target - x in appear:
                return [i, appear[target - x]]
            appear[x] = i
