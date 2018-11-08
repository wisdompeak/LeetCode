class Solution:
    def numSubarraysWithSum(self, A, S):
        """
        :type A: List[int]
        :type S: int
        :rtype: int
        """        
        count,result = 0,0
        Map = collections.defaultdict(int)
        Map[0] = 1                
        for i in range(len(A)):
            count+=A[i]
            result+=Map[count-S]
            Map[count]+=1
        return result
