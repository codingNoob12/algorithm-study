from typing import *


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        min_price, max_profit = prices[0], 0
        for i in range(1, len(prices)):
            max_profit = max(max_profit, prices[i] - min_price)
            min_price = min(min_price, prices[i])
        return max_profit


s = Solution()
print(s.maxProfit([7, 6, 4, 3, 1]))
