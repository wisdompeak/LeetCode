class Solution {
public:
    int knightDialer(int N) 
    {
        if (N==1) return 10;
        
        unordered_map<int,vector<int>>Map;
        Map[1]={6,8};
        Map[2]={7,9};
        Map[3]={4,8};
        Map[4]={3,9,0};
        Map[6]={1,7,0};
        Map[7]={6,2};
        Map[8]={1,3};
        Map[9]={4,2};
        Map[0]={6,4};
        
        vector<int>dp(10,1);
        vector<int>dp_temp(10);
        int M = 1e9 + 7;
        
        for (int i=1; i<N; i++)
        {            
            for (int k=0; k<=9; k++)
            {
                dp_temp[k] = 0;
                for (int j: Map[k])
                {
                    dp_temp[k]+=dp[j];
                    dp_temp[k] %= M;
                }
            }
            dp = dp_temp;
        }
        
        int result = 0;
        for (int i=0; i<=9; i++)
        {
            result += dp[i];
            result %= M;
        }
        return result;
    }
};
