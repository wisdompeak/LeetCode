class Solution:
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        hold, sold, sold_cd = -math.inf, 0, 0
        for i in range(len(prices)):
            hold_0, sold_0, sold_cd_0 = hold, sold, sold_cd
            hold = max(hold_0, sold_cd_0-prices[i])
            sold = max(sold_0, hold_0+prices[i])
            sold_cd = sold_0
        return max(sold,0)
