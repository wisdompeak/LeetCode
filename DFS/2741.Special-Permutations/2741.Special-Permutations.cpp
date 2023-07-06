using LL = long long;
class Solution {
    LL memo[14][1<<14];
    LL M = 1e9+7;
    int n;
    unordered_map<int,vector<int>>Map;
public:
    int specialPerm(vector<int>& nums) 
    {
        n = nums.size();
                
        for (int i=0; i<n; i++)
            for (int j=i+1; j<n; j++)
            {
                if (nums[i]%nums[j]==0 || nums[j]%nums[i]==0)
                {
                    Map[i].push_back(j);
                    Map[j].push_back(i);
                }
            }
                
        for (int j=0; j<14; j++)
            for (int state=0; state<(1<<n); state++)
                memo[j][state]=-1;        
        
        LL ret = 0;
        for (int i=0; i<n; i++)
        {
            ret += dfs(0, i, 1<<i);
            ret %= M;
        }
        return ret;
    }
    
    LL dfs(int i, int p, int state)
    {
        if (i==n-1) return 1;
        if (memo[p][state]!=-1) return memo[p][state];
        
        LL ret = 0;
        for (int q: Map[p])
        {
            if ((state>>q)&1) continue;
            ret  += dfs(i+1, q, state+(1<<q));
            ret %= M;
        }
        memo[p][state] = ret;
        return ret;
    }    
};
