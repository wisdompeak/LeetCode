class Solution:
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        buy1, buy2 = -math.inf, -math.inf
        release1, release2 = 0,0        
        for p in prices:
            buy1_tmp,buy2_tmp = buy1, buy2
            release1_tmp, release2_tmp = release1, release2
            buy1 = max(buy1_tmp,-p)
            release1 = max(release1,buy1_tmp+p)
            buy2 = max(buy2, release1_tmp-p)
            release2 = max(release2_tmp,buy2+p)
        return max(0,release1,release2)
