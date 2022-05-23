using LL = long long;
LL M = 1e9+7;
class Solution {
public:
    int totalStrength(vector<int>& nums) 
    {
        int n = nums.size();
        nums.insert(nums.begin(), 0);
        
        vector<LL>presum(n+2, 0);
        for (int i=1; i<=n; i++)
            presum[i] = (presum[i-1]+(LL)nums[i]) % M;
        
        vector<LL>presum2(n+2, 0);
        for (int i=1; i<=n; i++)
            presum2[i] = (presum2[i-1]+(LL)nums[i]*i) % M;
        
        stack<int>Stack;
        vector<int>nextSmaller(n+2,n+1);
        vector<int>prevSmaller(n+2,0);
        for (int i=1; i<=n; i++)
        {
            while (!Stack.empty() && nums[Stack.top()]>nums[i])
            {
                nextSmaller[Stack.top()] = i;
                Stack.pop();
            }
            if (!Stack.empty())
                prevSmaller[i] = Stack.top();
            Stack.push(i);            
        }
        
        LL ret = 0;
        for (int i=1; i<=n; i++)
        {
            LL a = prevSmaller[i], b = nextSmaller[i];
            LL x = i-a, y = b-i;
            LL first = ((presum2[i-1] - presum2[a]) - (presum[i-1] - presum[a]) * a %M + M) % M;
            first = first * y % M;
            LL second = ((presum[b-1] - presum[i]) * (b-1+1) - (presum2[b-1] - presum2[i]) + M ) % M;
            second = second * x % M;
            LL mid = (LL)nums[i] * x * y % M;
            
            ret = (ret +(first + second + mid) * nums[i]) % M;  
        }
        
        return ret;
    }
};
