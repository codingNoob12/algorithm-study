from typing import *


class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        def backtracking(k: int, letters: str):
            if k == len(digits):
                result.append(letters)
                return

            for char in digit_to_letter[digits[k]]:
                backtracking(k + 1, letters + char)

        result = []
        if not digits:
            return result

        digit_to_letter = {
            '2': 'abc',
            '3': 'def',
            '4': 'ghi',
            '5': 'jkl',
            '6': 'mno',
            '7': 'pqrs',
            '8': 'tuv',
            '9': 'wxyz'
        }

        backtracking(0, '')
        return result


print(Solution().letterCombinations(""))
