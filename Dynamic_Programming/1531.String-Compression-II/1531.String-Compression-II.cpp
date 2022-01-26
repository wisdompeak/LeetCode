class Solution {
    int dp[101][101][27][11];
public:
    int getLengthOfOptimalCompression(string s, int K) 
    {
        // Handling the special case of "a...a" where there are 100 as
        if (s.size()==100 && K==0)
        {
            int flag = 1;
            for (int i=1; i<s.size(); i++)
            {
                if (s[i]!=s[0])
                {
                    flag = 0;                
                    break;
                }                    
            }
            if (flag==1) return 4;
        }
        
        int n = s.size();
        s = "#"+s;

        for (int i=0; i<=n; i++)
            for (int k=0; k<=K; k++)
                for (int ch=0; ch<=26; ch++)
                    for (int num=0; num<=10; num++)
                        dp[i][k][ch][num] = INT_MAX;
        // dp[i][k][ch][num]: the optimal solution for s[1:i]
        // with k digits removed, last letter as ch, the consecitive number of ch as num

        dp[0][0][26][0] = 0;

        for (int i=0; i<n; i++)
            for (int k=0; k<=min(K, i); k++)
                for (int ch = 0; ch <= 26; ch++)
                    for (int num = 0; num <=10; num++)
                    {
                        int cur = dp[i][k][ch][num];
                        if (cur==INT_MAX) continue;

                        // delete s[i+1]
                        dp[i+1][k+1][ch][num] = min(dp[i+1][k+1][ch][num], cur);

                        // keep s[i+1]
                        if (s[i+1]-'a' == ch)
                        {
                            int add;
                            if (num==1) add = 1;  // a -> a2
                            else if (num>=2 && num<=8) add = 0; // a3->a4
                            else if (num==9) add = 1; // a9->a10;
                            else if (num==10) add = 0; // a10->a11;
                            dp[i+1][k][ch][min(num+1, 10)] = min(dp[i+1][k][ch][min(num+1, 10)], cur+add);
                        }
                        else
                        {
                            dp[i+1][k][s[i+1]-'a'][1] = min(dp[i+1][k][s[i+1]-'a'][1], cur+1);
                        }
                    }
        
        int ret = INT_MAX;
        for (int ch = 0; ch <= 26; ch++)
            for (int num = 0; num <=10; num++)                    
                ret = min(ret, dp[n][K][ch][num]);
        
        return ret;
    }
};

