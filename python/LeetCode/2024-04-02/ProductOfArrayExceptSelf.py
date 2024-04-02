from typing import *
from functools import reduce


class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        nums_without_zeros = list(filter(lambda x: x != 0, nums))

        if len(nums_without_zeros) + 1 < len(nums):
            return [0] * len(nums)

        multiply = reduce(lambda a, b: a * b, nums_without_zeros, 1)
        if len(nums_without_zeros) + 1 == len(nums):
            return [0 if num else multiply for num in nums]

        return [multiply // num for num in nums]


s = Solution()
print(s.productExceptSelf([1, 2, 3, 4]))
