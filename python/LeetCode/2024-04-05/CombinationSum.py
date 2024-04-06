from typing import *


class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        def backtracking(i):
            tot = sum(candidate)
            if tot >= target:
                if tot == target:
                    result.append(candidate[:])
                return

            for j in range(i, len(candidates)):
                candidate.append(candidates[j])
                backtracking(j)
                candidate.pop()

        result, candidate = [], []
        backtracking(0)
        return result


print(Solution().combinationSum(candidates=[2], target=1))
