typedef long long ll;
class Solution {
    ll M = 1e9+7;
public:
    int maxSumMinProduct(vector<int>& nums) 
    {
        int n = nums.size();
        
        vector<ll>nextSmaller(n, n);        
        vector<ll>prevSmaller(n, -1);

        stack<ll>Stack;
        for (int i=0; i<n; i++)
        {
            while (!Stack.empty() && nums[Stack.top()]>nums[i])
            {
                nextSmaller[Stack.top()] = i;
                Stack.pop();
            }
            Stack.push(i);                    
        }        
        
        while (!Stack.empty()) Stack.pop();
        for (int i=n-1; i>=0; i--)
        {
            while (!Stack.empty() && nums[Stack.top()]>nums[i])
            {
                prevSmaller[Stack.top()] = i;
                Stack.pop();
            }
            Stack.push(i);                    
        }
        
        vector<ll>presum(n);
        presum[0] = nums[0];
        for (int i=1; i<n; i++)
            presum[i] = presum[i-1]+nums[i];
        
        ll ret = 0;
        for (int i=0; i<n; i++)
        {
            ll a = prevSmaller[i]==-1 ? 0: presum[prevSmaller[i]];
            ll b = presum[nextSmaller[i]-1];
            ret = max(ret, (b-a)*(ll)nums[i]);
        }
        return ret%M;        
    }
};
