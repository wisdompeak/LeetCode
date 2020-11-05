class Solution {
    string dp[5001];
public:
    string largestNumber(vector<int>& cost, int target) 
    {
        cost.insert(cost.begin(),0);
        for (int cap=1; cap<=target; cap++)
            dp[cap] = "#";
        for (int cap = 1; cap <= target; cap++)        
        {
            for (int i=1; i<=9; i++)
            {
                if (cap < cost[i]) continue;
                if (dp[cap-cost[i]]=="#") continue;
                string temp = dp[cap-cost[i]] + to_string(i);
                if (temp.size() > dp[cap].size() || temp.size()==dp[cap].size() && temp > dp[cap])
                    dp[cap] = temp;
            }
            // cout<<cap<<":"<<dp[cap]<<endl;
        }
        if (dp[target]=="#")
            return "0";
        else
            return dp[target];
    }
};
