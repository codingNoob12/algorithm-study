from typing import *


class Solution:
    def arrayPairSum(self, nums: List[int]) -> int:
        nums.sort()
        return sum(nums[::2])


s = Solution()
print(s.arrayPairSum([6, 2, 6, 5, 1, 2]))
