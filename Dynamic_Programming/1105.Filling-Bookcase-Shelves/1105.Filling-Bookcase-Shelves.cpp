class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) 
    {
        int N = books.size();
        books.insert(books.begin(),{0,0});        
        vector<int>dp(N+1,INT_MAX/2);
        dp[0] = 0;
        
        for (int i=1; i<=N; i++)
        {
            int width = books[i][0];
            int height = books[i][1];
            dp[i] = dp[i-1]+height;
            
            int j = i-1;
            while (j>=1 && books[j][0]+width<=shelf_width)
            {                
                width += books[j][0];
                height = max(height, books[j][1]);
                dp[i] = min(dp[i], dp[j-1]+height);
                j--;
            }
        }
        return dp[N];
    }
};
