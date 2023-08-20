using LL = long long;
LL M = 1e9+7;
class Solution {
public:
    int countSteppingNumbers(string low, string high) 
    {
        LL ret = helper(high) - helper(low);
        ret = (ret + M) % M;
        ret = (ret + check(low) + M) % M;
                
        return ret;
    }
    
    bool check(string s)
    {
        for (int i=1; i<s.size(); i++)
            if (abs(s[i]-s[i-1])!=1) return false;
        return true;
    }
    
    LL helper(string num)
    {
        LL ret = 0;
        
        int n = num.size();
        int memo[105][10][2];
        memset(memo, -1, sizeof(memo));

        for (int len = 1; len < n; len++)
        {
            for (int d=1; d<=9; d++)
                ret = (ret + dfs(len-1, d, false, num, memo)) % M;
        }

        int D = num[0]-'0';
        for (int d=1; d<D; d++)
            ret = (ret + dfs(n-1, d, false, num, memo)) % M;
        ret = (ret + dfs(n-1, D, true, num, memo)) % M;
        
        return ret;
    }
    
    LL dfs(int len, int prev, bool isSame, string& num, int memo[105][10][2])
    {        
        if (len==0) return 1;

        if (memo[len][prev][isSame]!=-1) 
            return memo[len][prev][isSame];

        int n = num.size();                
        LL ret = 0;
        if (!isSame)
        {
            if (prev+1 <= 9)            
                ret = (ret + dfs(len-1, prev+1, false, num, memo)) % M;                            
            if (prev-1 >= 0)
                ret = (ret + dfs(len-1, prev-1, false, num, memo)) % M;
        }
        else
        {
            int D = num[n-len] - '0';
            if (prev+1 < D)
                ret += dfs(len-1, prev+1, false, num, memo);
            else if (prev+1 == D)
                ret += dfs(len-1, prev+1, true, num, memo);
            ret %= M;                

            if (prev-1 >= 0 && prev-1 < D)
                ret += dfs(len-1, prev-1, false, num, memo);
            else if (prev-1 >= 0 && prev-1 == D)
                ret += dfs(len-1, prev-1, true, num, memo);
            ret %= M;                            
        }
        
        memo[len][prev][isSame] = ret;
        return ret;        
    }
};
