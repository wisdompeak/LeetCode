class Solution:
    def maxWidthRamp(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        Stack = []
        for i in range(len(A)):
            if len(Stack)==0 or A[Stack[-1]]>=A[i]:
                Stack.append(i)
        result = 0
        for i in range(len(A)-1,-1,-1):
            while (len(Stack)>0 and A[Stack[-1]]<=A[i]):
                result = max(result,i-Stack[-1])
                Stack.pop()
        return result
            
