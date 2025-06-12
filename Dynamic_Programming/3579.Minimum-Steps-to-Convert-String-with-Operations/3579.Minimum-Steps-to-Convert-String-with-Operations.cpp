class Solution {
    int count[26][26];
public:
    int helper(string& word1, string&word2) {
        fill(&count[0][0], &count[0][0]+26*26, 0);

        int n = word1.size();
        for (int k=0; k<n; k++) {
            if (word1[k]==word2[k]) continue;
            count[word1[k]-'a'][word2[k]-'a']++;
        }

        int ans = 0;
        for (int a=0; a<26; a++)
            for (int b=0; b<26; b++) {
                int common = min(count[a][b], count[b][a]);
                ans+=common;
                count[a][b]-=common;
                count[b][a]-=common;
                ans+=count[a][b];
            }
        return ans;
    }

    int minOperations(string word1, string word2) {
        int n = word1.size();
        vector<int>dp(n, INT_MAX/2);

        for (int j=0; j<n; j++)
            for (int i=0; i<=j; i++) {
                int ans = INT_MAX/2;
                string a = word1.substr(i,j-i+1);
                string b = word2.substr(i,j-i+1);
                ans = min(ans, helper(a,b));

                string rev = a;
                reverse(rev.begin(), rev.end());                
                ans = min(ans, helper(rev,b)+1);
    
                dp[j] = min(dp[j], (i==0?0:dp[i-1])+ans);
            }

        return dp[n-1];
        
    }
};
