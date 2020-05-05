class Solution {
public:
    int numberWays(vector<vector<int>>& hats) 
    {
        int n = hats.size();
        vector<long>dp(1<<n, 0);
        long M = 1e9+7;
        
        unordered_map<int, vector<int>>PersonsForThisHat;
        for (int i=0; i<hats.size(); i++)
            for (int j=0; j<hats[i].size(); j++)
                PersonsForThisHat[hats[i][j]].push_back(i);
        
        dp[0] = 1;
                
        for (int hat =1; hat <=40; hat++)
        {
            auto dp_new = dp; // dp_new = 000000000
            for (int state = 0; state<(1<<n); state++)
            {
                for (int person: PersonsForThisHat[hat])
                {
                    if (((state>>person)&1)==1)
                        continue;
                    dp_new[state+(1<<person)] += dp[state];
                    dp_new[state+(1<<person)] %= M;
                } 
            }   
            
            dp = dp_new;
        }
        
        return dp[(1<<n)-1];
    }
};
