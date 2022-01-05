class Solution {
public:
    int minDistance(string word1, string word2) 
    {
        int n1=word1.size();
        int n2=word2.size();
        word1.insert(word1.begin(),'0');
        word2.insert(word2.begin(),'0');
        
        auto dp=vector<vector<int>>(n1+1,vector<int>(n2+1,INT_MAX));        
        
        dp[0][0]=0;
        for (int i=1; i<=n1; i++)
            dp[i][0]=i;
        for (int j=1; j<=n2; j++)
            dp[0][j]=j;
        
        for (int i=1; i<=n1; i++)
         for (int j=1; j<=n2; j++)
         {
             if (word1[i]==word2[j])
                 dp[i][j]=dp[i-1][j-1];
             else
             {
                 dp[i][j]=min(dp[i][j],dp[i-1][j]+1);
                 dp[i][j]=min(dp[i][j],dp[i][j-1]+1);
                 dp[i][j]=min(dp[i][j],dp[i-1][j-1]+1);
             }                 
         }
        
        return dp[n1][n2];
    }

    /**
     * @brief calculate the minimum edit distance between word1 and word2
     * Another implementation of edit distance with compressed memory usage
     * @param word1 const std::string &   The reference of first string
     * @param word2 const std::string &   The reference of second string
     * @return The edit distance
     */
    int minDistance2(const std::string &word1, const std::string &word2)
    {
      int n1=word1.size();
      int n2=word2.size();

      // dp[i][j] : edit distance between word1[0, i) and word2[0, j)
      // dp[i][j] = std::min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1
      //                     ----------  ---------- -------------
      //                       add-j       delete-j   replace-j
      //  if word1[i] != word2[j]
      // Compressed to
      // dp[j]

      std::vector<int> dp(n2+1, 0);

      for (auto j = 1; j <= n2; ++j)
        dp[j] = j; // distance between word1[0, 0) and word2[0, j), j deletions

      for (auto i = 1; i <= n1; ++i)
      {
        int topleft = dp[0];
        // reset dp[i]
        dp[0] = i; // edit distance = j add operations

        for (auto j = 1; j <= n2; ++j)
        {
          int top = dp[j];

          if (word1[i-1] == word2[j-1])
            dp[j] = topleft;
          else
            dp[j] = std::min({dp[j-1], top, topleft}) + 1;
            //                -------- --- ---------
            //                delete-j add-j replace-j

          topleft = top; // move the top 1 step to the right
        }
      }

      return dp.back();
    }
};
