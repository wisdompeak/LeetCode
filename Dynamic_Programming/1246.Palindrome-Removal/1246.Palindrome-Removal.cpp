class Solution {
public:
    int minimumMoves(vector<int>& arr) 
    {
        int N = arr.size(); 
        arr.insert(arr.begin(),0);
        
        auto dp = vector<vector<int>>(N+1,vector<int>(N+1,0));        
      
        for (int len = 1; len <= N; len++)           
            for (int i = 1; i+len-1<=N; i++) 
            { 
                int j = i+len-1;
                dp[i][j] = dp[i][j-1]+1;
                
                for (int k=i; k<j; k++)
                {
                    if (arr[k]==arr[j])
                        dp[i][j] = min(dp[i][j], dp[i][k-1]+(dp[k+1][j-1]==0?1:dp[k+1][j-1]));
                } 
            }         
  
        return dp[1][N]; 
    }
};
