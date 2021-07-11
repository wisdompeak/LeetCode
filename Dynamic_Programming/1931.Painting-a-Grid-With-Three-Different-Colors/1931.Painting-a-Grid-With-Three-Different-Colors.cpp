typedef long long LL;
class Solution {
    LL M = 1e9+7;
public:
    int colorTheGrid(int m, int n) 
    {
        vector<int>cand;
        for (int state = 0; state < pow(3,m); state++)
        {
            vector<int>temp;
            int state0 = state;
            int flag = 1;
            for (int i=0; i<m; i++)
            {
                int color = state0 % 3;
                if (!temp.empty() && temp.back()==color)
                {
                    flag = 0;
                    break;
                }
                temp.push_back(color);
                state0 /= 3;                
            }
            if (flag==1)
                cand.push_back(state);
        }
        
        int k = cand.size();
        vector<LL>dp(k, 1);                
               
        for (int j=1; j<n; j++)
        {       
            vector<LL>dp2(k);
            for (int s=0; s<k; s++)                            
                for (int t = 0; t<k; t++)
                {
                    if (checkOK(cand[s],cand[t],m))
                        dp2[s] = (dp2[s] + dp[t]) % M;                    
                }
            dp = std::move(dp2);
        }
                
        LL ret = 0;
        for (int s=0; s<k; s++)
            ret = (ret + dp[s])%M;
        return ret;
        
    }
    
    bool checkOK(int s, int t, int m)
    {
        for (int i=0; i<m; i++)
        {
            if (s%3==t%3)
                return false;
            s /=3;
            t /=3;
        }
        return true;
    }
};
