class Solution:
    def findTargetSumWays(self, nums, S):
        """
        :type nums: List[int]
        :type S: int
        :rtype: int
        """
        def DFS(i,target):            
            if i==len(nums): return target==0            
            if (i,target) in mem: return mem[(i,target)]
            mem[(i,target)] = DFS(i+1,target-nums[i]) + DFS(i+1,target+nums[i])
            return mem[(i,target)]
        
        mem={}
        return DFS(0,S)            
