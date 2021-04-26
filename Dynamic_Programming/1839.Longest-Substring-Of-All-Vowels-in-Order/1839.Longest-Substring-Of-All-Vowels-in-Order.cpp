class Solution {    
public:
    int longestBeautifulSubstring(string word) 
    {
        unordered_map<char,int>Map{{'a',1},{'e',2},{'i',3},{'o',4},{'u',5}};
        vector<int>dp(6,INT_MIN);
        dp[0] = 0;
        vector<int>dp_tmp(6);
        int ret = 0;
        for (int i=0; i<word.size(); i++)
        {
            for (int j=0; j<=5; j++)
                dp_tmp[j] = dp[j];

            int k = Map[word[i]];
            for (int j=1; j<=5; j++)
            {
                if (j!=k)
                    dp[j] = INT_MIN;
                else
                    dp[j] = max(dp_tmp[j], dp_tmp[j-1])+1;
            }
            
            ret = max(ret, dp[5]);
        }
        return ret;
    }
};
