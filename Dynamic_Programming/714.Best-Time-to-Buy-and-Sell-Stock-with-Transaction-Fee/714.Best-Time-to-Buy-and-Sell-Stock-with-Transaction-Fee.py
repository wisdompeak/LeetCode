class Solution:
    def maxProfit(self, prices, fee):
        """
        :type prices: List[int]
        :type fee: int
        :rtype: int
        """
        hold, sold = -math.inf,0
        for p in prices:
            hold_tmp, sold_tmp = hold, sold
            hold = max(hold_tmp, sold_tmp-p)
            sold = max(sold_tmp, hold_tmp+p-fee)
        return max(hold,sold)
