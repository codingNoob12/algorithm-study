from typing import *


class Solution:
    def arrayPairSum(self, nums: List[int]) -> int:
        nums.sort()
        flag, result = False, 0

        while nums:
            if flag:
                result += nums[-1]
            flag = not flag
            nums.pop()

        return result


s = Solution()
print(s.arrayPairSum([6, 2, 6, 5, 1, 2]))
