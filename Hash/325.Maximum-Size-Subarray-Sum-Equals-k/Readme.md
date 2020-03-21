### 325.Maximum-Size-Subarray-Sum-Equals-k

在遍历元素的过程中，建立累加和sum，并建立映射Map:sum->i。对于每个元素i，找和为k的子数组，就是寻找之前的累加和序列里是否出现过 sum-k，显然，直接从Map中就可以找到。

```cpp
        for (int i=0; i<nums.size(); i++)
        {
            sum+=nums[i];
            Map[sum].push_back(i);
            
            int temp = sum-k;
            if (Map.find(temp)!=Map.end())
            {
                result = max(result, i-Map[temp][0]);
            }
        }
```


[Leetcode Link](https://leetcode.com/problems/maximum-size-subarray-sum-equals-k)