from typing import *


class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        def backtracking(k: int, permutation: List[int] = []):
            if k == len(nums):
                result.append(permutation[:])
                return

            for num in nums:
                if num in selected:
                    continue

                permutation.append(num)
                selected.add(num)

                backtracking(k + 1, permutation)

                permutation.pop()
                selected.remove(num)

        result: List[List[int]] = []
        selected: Set[int] = set()

        backtracking(0)
        return result


print(Solution().permute([1, 2, 3]))
