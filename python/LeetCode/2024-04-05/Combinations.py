from typing import *


class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        def backtracking(length: int):
            if length == k:
                result.append(combination[:])
                return

            start = combination[-1] if combination else 1
            for i in range(start, n + 1):
                if i in selected:
                    continue

                combination.append(i)
                selected.add(i)

                backtracking(length + 1)

                combination.pop()
                selected.remove(i)

        result, combination, selected = [], [], set()
        backtracking(0)
        return result


print(Solution().combine(n=1, k=1))
