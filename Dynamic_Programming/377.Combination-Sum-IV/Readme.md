### 377.Combination-Sum-IV

此题直观上明显适合DFS算法。
```py
    def combinationSum4(self, nums, target):
        self.result = 0        
        def DFS(Target):
            if (Target<0): return
            if (Target==0): 
                self.result+=1
                return      
            for i in range(len(nums)):
                DFS(Target-nums[i])                        
        DFS(target)
        return self.result
                
```
但结果发现会超时。此时显然应该想到，可以调整为DP算法。用dp[i]表示加和为i的组合的数目，这也是DP中常见的思想，当然前提是target不是非常大，否则dp数组会很占空间。
