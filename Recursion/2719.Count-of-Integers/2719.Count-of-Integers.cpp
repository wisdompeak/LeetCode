using LL = long long;
LL M = 1e9+7;
class Solution {
public:
    int count(string num1, string num2, int min_sum, int max_sum) 
    {
        LL ret = (CountNoGreater(num2, max_sum) - CountNoGreater(num2, min_sum-1) + M) % M
- (CountNoGreater(num1, max_sum) - CountNoGreater(num1, min_sum-1) + M) % M;    

        ret = (ret + M) % M;

        int digitSum = calculate(num1);
        if (digitSum>=min_sum && digitSum<=max_sum) ret = (ret+1)%M;
        return ret;
    }

    int calculate(string& s)
    {
        int ret = 0;
        for (auto ch:s) ret += ch-'0';
        return ret;
    }

    LL CountNoGreater(string num, int max_sum)
    {
        vector<vector<vector<int>>>memo(2, vector<vector<int>>(25, vector<int>(405, -1)));
        return dfs(num, max_sum, 0, 0, true, memo);
    }

    LL dfs(string num, int max_sum, int i, int sum, bool isSame, vector<vector<vector<int>>>&memo) 
    {
        if (sum > max_sum) return 0;
        if (memo[isSame][i][sum]!=-1) return memo[isSame][i][sum];
        if (i==num.size()) return 1;

        LL ret = 0;
        if (!isSame)
        {
            for (int k=0; k<=9; k++)
            {
                ret += dfs(num, max_sum, i+1, sum+k, false, memo);
                ret %= M;
            }
        }
        else
        {
            for (int k=0; k<(num[i]-'0'); k++)
            {
                ret += dfs(num, max_sum, i+1, sum+k, false, memo);
                ret %= M;
            }
            ret += dfs(num, max_sum, i+1, sum+(num[i]-'0'), true, memo);
            ret %= M;
        }

        memo[isSame][i][sum] = ret;
        return ret;
    }
};


