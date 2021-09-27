class Solution {
    vector<int>nums;
    vector<char>ops;
    
public:
    vector<int> diffWaysToCompute(string input) 
    {
        for (int i=0; i<input.size(); i++)
        {
            int j = i;
            while (j<input.size() && isdigit(input[j]))
                j++;
            nums.push_back(stoi(input.substr(i,j-i)));
            ops.push_back(input[j]);
            i = j;
        }

        int n = nums.size();
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(n));
        helper(dp, 0, n-1);
        return dp[0][n-1];
    }

    void helper(vector<vector<vector<int>>>&dp, int a, int b)
    {
        if (!dp[a][b].empty())
            return;
        if (a==b)
        {
            dp[a][b] = {nums[a]};
            return;
        }
        
        for (int i=a; i<b; i++)
        {
            helper(dp, a, i);
            helper(dp, i+1, b);
            for (auto x: dp[a][i])
                for (auto y: dp[i+1][b])
                {
                    if (ops[i]=='+')
                        dp[a][b].push_back(x+y);
                    else if (ops[i]=='-')
                        dp[a][b].push_back(x-y);
                    else if (ops[i]=='*')
                        dp[a][b].push_back(x*y);
                }
        }
    }
};
