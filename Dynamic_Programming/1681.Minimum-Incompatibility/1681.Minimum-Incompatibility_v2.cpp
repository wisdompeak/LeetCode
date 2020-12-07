class Solution {
    int n;
public:
    int minimumIncompatibility(vector<int>& nums, int k) 
    {
        unordered_map<int,int>count;
        for (auto x: nums)
            count[x]++;
        for (auto x: count)
            if (x.second > k)
                return -1;

        n= nums.size();        
        vector<int>states;
        vector<int>values;
        int state = (1 << n/k) - 1;            
        while (state < (1 << n))
        {
            int val;
            if (!containDuplicate(nums, state, val))
            {
                states.push_back(state);
                values.push_back(val);                
            }
            
            int c = state & - state;
            int r = state + c;
            state = (((r ^ state) >> 2) / c) | r;
        }

        vector<int>dpstates;
        for (int state=0; state<(1<<n); state++)
        {
            if (__builtin_popcount(state) % (n/k) ==0) 
                dpstates.push_back(state);
        }
        reverse(dpstates.begin(), dpstates.end());
        
        vector<int>dp(1<<n, INT_MAX/2);
        dp[0] = 0;

        for (int i=0; i<states.size(); i++)
        {            
            for (auto dpstate: dpstates)
            {                
                if ((dpstate & states[i])!=states[i]) continue;
                dp[dpstate] = min(dp[dpstate], dp[dpstate-states[i]]+values[i]);
            }
        }
        return dp[(1<<n)-1];
    }

    bool containDuplicate(vector<int>&nums, int state, int&val)
    {
        vector<int>p;
        for (int i=0; i<n; i++)
        {
            if ((state>>i)&1)
                p.push_back(nums[i]);
        }
        sort(p.begin(),p.end());
        for (int i=1; i<p.size(); i++)
            if (p[i]==p[i-1]) return true;
        val = p.back()-p.front();
        return false;
    }
};
