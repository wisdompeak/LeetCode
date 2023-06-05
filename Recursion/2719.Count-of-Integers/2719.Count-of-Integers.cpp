using LL = long long;
LL M = 1e9+7;
class Solution {
public:
    int count(string num1, string num2, int min_sum, int max_sum) 
    {
        LL ret = (ValidNumbersNoGreaterThan(num2, max_sum)-ValidNumbersNoGreaterThan(num2, min_sum-1)) - (ValidNumbersNoGreaterThan(num1, max_sum)-ValidNumbersNoGreaterThan(num1, min_sum-1));
        
        int digitSum = getDigitSum(num1);
        if (digitSum>=min_sum && digitSum<=max_sum) ret = (ret+1) % M;
        return ret;        
    }
    
    int getDigitSum(string s)
    {
        int ret = 0;
        for (auto ch: s) ret += ch-'0';
        return ret;
    }
    
    
    LL ValidNumbersNoGreaterThan(string num, int max_sum)
    {        
        vector<vector<int>>memo(25, vector<int>(405, -1));        
        return dfs(num, max_sum, 0, 0, memo, true);
    }
    
    LL dfs(string num, int max_sum, int i, int sum, vector<vector<int>>&memo, int isSame)
    {
        if (sum > max_sum) return 0;                         
        if (!isSame && memo[i][sum]!=-1) return memo[i][sum];
        if (i==num.size()) return 1; 
                           
        LL ret = 0;
        if (!isSame)
        {
            for (int k=0; k<=9; k++)
            {
                ret += dfs(num, max_sum, i+1, sum+k, memo, false);
                ret %= M;
            }            
        }
        else
        {
            for (int k=0; k<num[i]-'0'; k++)
            {
                ret += dfs(num, max_sum, i+1, sum+k, memo, false);
                ret %= M;
            }            
            ret += dfs(num, max_sum, i+1, sum+(num[i]-'0'), memo, true);
            ret %= M;
        }
        
        if (!isSame) memo[i][sum] = ret;
        return ret;
    }
    
};
