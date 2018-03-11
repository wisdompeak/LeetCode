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
但结果发现会超时。此时应该立刻想到，是否可以调整为DP算法。用dp[i]表示加和为i的组合的数目，考察与其他dp[j]的传递关系，这也是DP中常见的思想。
```py
    def combinationSum4(self, nums, target):
        dp = [1]+[0]*target
        for i in range(1,target+1):
            for j in range(len(nums)):
                if i-nums[j]>=0:
                    dp[i]+=dp[i-nums[j]]
        return dp[target]
```
当然DP算法的前提是target不是非常大，否则dp数组会很占空间。
