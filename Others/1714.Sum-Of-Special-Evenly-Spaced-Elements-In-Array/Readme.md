### 1714.Sum-Of-Special-Evenly-Spaced-Elements-In-Array

https://leetcode.com/problems/sum-of-special-evenly-spaced-elements-in-array/discuss/1008468/

#### solution 1 
Same idea as https://leetcode.com/problems/sum-of-special-evenly-spaced-elements-in-array/discuss/1006993/ Just implemented it in C++.

Rough explanation:

Let query = [s,d]

When d >= sqrt(n)，just brute loop the numbers we want to add. It takes at most o(sqrt(N)).

When d < sqrt(n), would be better to prepare the prefix sum array as ```presum[d][offset]```，where  ```offset = s%d```.  ```presum[d][offset]``` is the summation of ```nums[offset] + nums[offset+d] + nums[offset+d*2] + ... ``` Then the result of this query is simply ```presum[d][offset][(n-1-offset)/d] - presum[d][offset][(s-1-offset)/d] ``` The pre-computation for one query takes ```o(N/d)``` which is around ```o(sqrt(N))```, but it can be stored for reuse (if multiple queries share the same d and offset). 

#### solution 2 
Same idea as https://leetcode.com/problems/sum-of-special-evenly-spaced-elements-in-array/discuss/1007086/ Just implemented it in C++.

Rough explanation:

Let query = [s,d]

When d >= sqrt(n)，just brute loop the numbers we want to add. It takes at most o(sqrt(N)).

When d < sqrt(n), would be better to prepare the suffix sum array as ```sufsum[d][i]```.  ```sufsum[d][i]``` is the summation of ```nums[i] + nums[i+d] + nums[i+d*2] + ... ``` Then the result of this query is simply ```sufsum[d][s]``` The pre-computation for one query always takes ```o(N)``, but it can be stored for reuse (if multiple queries share the same d). 

```
class Solution {        
    long M = 1e9+7;
    int sufsum[256][50001];

public:
    vector<int> solve(vector<int>& nums, vector<vector<int>>& queries) 
    {        
        int n = nums.size();
        vector<int>rets(queries.size());    
        
        for (int d = 1; d<sqrt(n); d++)
            for (int i=0; i<n; i++)
                sufsum[d][i] = -1;

        
        for (int k=0; k<queries.size(); k++)
        {
            int s = queries[k][0];
            int d = queries[k][1];
            if (d >= sqrt(n))
            {
                long sum = 0;
                int i = s;
                while (i < n)
                {
                    sum = (sum+nums[i])%M;
                    i+=d;
                }
                rets[k] = sum;                    
            }
            else
            {                
                if (sufsum[d][0] == -1)
                {
                    for (int d = 1; d<sqrt(n); d++)
                    {
                        for (int i = n-1; i>=0; i--)
                        {
                            if (i+d < n)
                                sufsum[d][i] = (sufsum[d][i+d] + nums[i]) % M;
                            else
                                sufsum[d][i] = nums[i];
                        }
                    }                    
                }                                
                rets[k] = sufsum[d][s];
            }
        }
        return rets;        
    }
};
```

Both solutions are slow in C++ (beat 5%).
