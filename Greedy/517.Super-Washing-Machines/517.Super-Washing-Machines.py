class Solution:
    def findMinMoves(self, machines):
        """
        :type machines: List[int]
        :rtype: int
        """        
        N = len(machines)
        if sum(machines)%N!=0: return -1
        avg = sum(machines)//N
        
        result = 0
        toNext = 0
        for i in range(N):
            fromPrev = toNext
            toNext = fromPrev+machines[i]-avg
            if fromPrev<0 and toNext>0:
                result = max(result,-fromPrev+toNext)
            else:
                result = max(result,abs(fromPrev),abs(toNext))
                        
        return result
