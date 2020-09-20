### 340.Longest-Substring-with-At-Most-K-Distinct-Characters.cpp

#### 解法1：固定左边界，探索右边界(开区间)
```cpp
        for (int i=0; i<n; i++)
        {
            while (j<n && count + (freq[s[j]]+1 == 1) <= k)
            {
                freq[s[j]]++;
                count += (freq[s[j]] == 1);
                j++;
            }
            ret = max(ret, j-i);
            
            freq[s[i]]--;
            count -= (freq[s[i]] == 0);
        }
```        

#### 解法1：固定右边界，探索左边界(闭区间)
```cpp
        for (int j=0; j<s.size(); j++)
        {                        
            freq[s[j]]++;
            if (freq[s[j]]==1) count++;
            
            while (count>k)
            {
                freq[s[i]]--;
                if (freq[s[i]]==0)
                    count--;
                i++;
            }
            ret = max(ret, j-i+1);            
        }
```

[Leetcode Link](https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters)
