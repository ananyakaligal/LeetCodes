# Last updated: 9/16/2025, 12:08:57 AM
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        buy=prices[0]
        maxProfit=0

        for x in range(1,len(prices)):
            if prices[x] > buy:
                profit=prices[x]-buy
                maxProfit=max(profit,maxProfit)
            else:
                buy=prices[x] 

        return maxProfit        