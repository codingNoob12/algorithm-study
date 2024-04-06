from typing import *


class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        result = []

        def backtracking(size: int, subset: List[int]):
            result.append(subset)

            for i in range(size, len(nums)):
                backtracking(i + 1, subset + [nums[i]])

        backtracking(0, [])
        return result


print(Solution().subsets([1, 2, 3]))
