class Solution {
    bool dp[51][1024];
public:
    bool canDistribute(vector<int>& nums, vector<int>& quantity) 
    {
        unordered_map<int,int>Map;
        for (auto x: nums)
            Map[x]++;
        vector<int>count;
        for (auto x: Map)
            count.push_back(x.second);
        
        int n = count.size();
        int m = quantity.size();        
        
        count.insert(count.begin(), 0);
                
        for (int i=0; i<=n; i++)
            dp[i][0] = true;
        
        for (int i=1; i<=n; i++)
            for (int state=1; state<(1<<m); state++)
            {
                if (dp[i-1][state]==true) 
                {
                    dp[i][state] = true;
                    continue;
                }                    
                
                for (int subset=state; subset>0; subset=(subset-1)&state)
                {
                    if (dp[i-1][state-subset]==false) continue;
                    if (canSatisfySubset(count[i], quantity, subset))
                    {
                        dp[i][state] = true;
                        break;
                    }
                }
            }
        return dp[n][(1<<m)-1];
        
    }
    
    bool canSatisfySubset(int count, vector<int>& quantity, int subset)
    {
        int m = quantity.size();
        int sum = 0;
        for (int i=0; i<m; i++)
        {
            if ((subset>>i)&1)
                sum += quantity[i];
        }
        return count>=sum;
    }
};
