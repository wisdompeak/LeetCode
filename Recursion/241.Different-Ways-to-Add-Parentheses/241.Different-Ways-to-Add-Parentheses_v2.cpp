class Solution {
    vector<int>nums;
    vector<char>ops;
    vector<int> dp[21][21];
public:
    vector<int> diffWaysToCompute(string input) 
    {
        for (int i=0; i<input.size(); i++)
        {
            int j = i;
            while (j<input.size() && isdigit(input[j]))
                j++;
            nums.push_back(stoi(input.substr(i, j-i)));
            if (j<input.size()) ops.push_back(input[j]);
            i = j;            
        }
        
        int n = nums.size();
        helper(0, n-1);
        return dp[0][n-1];        
    }
    
    void helper(int a, int b)
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
            helper(a,i);
            helper(i+1,b);
            for (int x: dp[a][i])
                for (int y: dp[i+1][b])
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
