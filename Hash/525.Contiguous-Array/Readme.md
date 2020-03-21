### 525.Contiguous-Array

建立累加和sum，遍历所有元素，遇到1加1，遇到0减1. 如果两个位置的累加和相等，说明中间的元素和是0，即有相同数目的0和1.

构造unordered_map<int,int>Map记录每个累加和sum出现的位置。注意，因为求的是最大长度，只需要存储第一次出现sum数值的位置即可。另外，需要考虑子串的首位置可以是0，故设置Map[0]=-1.

```cpp
        int result=0;
        for (int i=0; i<nums.size(); i++)
        {
            sum+=(nums[i]==1?1:-1);
            if (Map.find(sum)==Map.end())
                Map[sum]=i;
            else
                result = max(result, i-Map[sum]);
        }
```        


[Leetcode Link](https://leetcode.com/problems/contiguous-array)