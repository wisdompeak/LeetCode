using LL = long long;
class Solution {
    int k;
public:
    int numberOfBeautifulIntegers(int low, int high, int k) 
    {
        this->k = k;
        return helper(high, k) - helper(low-1, k);        
    }

    int helper(LL num, int k)
    {
        int memo[11][2][22][22];
        memset(memo, -1, sizeof(memo));

        string Num = to_string(num);
        int n = Num.size();
        
        int ret = 0;
        for (int len = 2; len < n; len+=2)
        {
            for (int d=1; d<=9; d++)
                ret += dfs(len-1, false, (d%2==0)*2-1, d%k, Num, memo);
        }

        if (n%2==0)
        {
            int D = Num[0]-'0';
            for (int d=1; d<D; d++)
                ret += dfs(n-1, false, (d%2==0)*2-1, d%k, Num, memo);
            ret += dfs(n-1, true, (D%2==0)*2-1, D%k, Num, memo);
        }

        return ret;
    }

    int dfs(int len, bool isSame, int diff, int r, string& num, int memo[11][2][22][22])
    {
        int n = num.size();

        if (len==0)
        {
            if (diff==0 && r==0) return 1;
            else return 0;
        }

        if (memo[len][isSame][diff+10][r]!=-1)
            return memo[len][isSame][diff+10][r];

        int ret = 0;
        if (!isSame)
        {
            for (int d=0; d<=9; d++)
                ret += dfs(len-1, false, diff + (d%2==0)*2-1, (r*10+d) %k, num, memo);
        }
        else
        {
            int D = num[n-len] - '0';
            for (int d=0; d<D; d++)
                ret += dfs(len-1, false, diff + (d%2==0)*2-1, (r*10+d) %k, num, memo);
            
            ret += dfs(len-1, true, diff + (D%2==0)*2-1, (r*10+D) %k, num, memo);
        }

        memo[len][isSame][diff+10][r] = ret;

        return ret;
    }

};
