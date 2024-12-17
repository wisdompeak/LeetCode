class Solution {
public:
    int makeStringGood(string s) 
    {        
        vector<int>freq(26);        
        for (char c : s) {
            freq[c-'a']++;
        }
        int max_freq = *max_element(freq.begin(), freq.end());
                
        int ret = INT_MAX/2;
        vector<int>diff(26);
        
        for (int target = 1; target <= max_freq; target++)
        {            
            for (int i=0; i<26; i++)
                diff[i] = freq[i] - target;
            vector<vector<int>>dp(26, vector<int>(2, INT_MAX/2));

            int carry;
            dp[0][0] = freq[0];
            dp[0][1] = abs(diff[0]);

            for (int i=1; i<26; i++)
            {
                dp[i][0] = min(dp[i-1][0], dp[i-1][1]) + freq[i];

                dp[i][1] = min(dp[i-1][0], dp[i-1][1]) + abs(diff[i]);

                if (i>=1 && diff[i-1]>0 && diff[i]<0)
                {
                    int common = min(abs(diff[i-1]), abs(diff[i]));
                    dp[i][1] = min(dp[i][1], dp[i-1][1] + abs(diff[i])-common);
                }
                
                if (i>=1 && freq[i-1]>0 && diff[i]<0)
                {
                    int common = min(abs(freq[i-1]), abs(diff[i]));
                    dp[i][1] = min(dp[i][1], dp[i-1][0] + abs(diff[i])-common);
                }
            }

            ret = min(ret, min(dp[25][0], dp[25][1]));                
        }

        return ret;        
    }
};
