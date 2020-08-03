class Solution {
public:
    int minStickers(vector<string>& stickers, string target) 
    {
        int n = target.size();
        vector<int>dp(1<<n,INT_MAX);
        dp[0] = 0;

        for (int state=0; state<(1<<n); state++)
        {
            if (dp[state]==INT_MAX) continue;
            for (string str:stickers)
            {
                int new_state = findNextStatusByUsingStr(state,target,str);
                dp[new_state] = min(dp[new_state], dp[state]+1);
            }
        }
        return dp[(1<<n)-1]==INT_MAX?-1: dp[(1<<n)-1];
    }
    
    int findNextStatusByUsingStr(int status, string target, string s)
    {
        int n = target.size();
        for (auto ch:s)
        {
            // loop over each character in target, if equals to ch and not filled, then set as filled
            for (int k=0; k<n; k++)
            {
                if (((status>>k)&1)==0 && target[k]==ch)
                {
                    status = status+(1<<k);   
                    break;
                }              
            }
        }
        return status;
    }
};
