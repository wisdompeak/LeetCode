class Solution {    
    
public:
    int removeBoxes(vector<int>& boxes) 
    {                
        int dp[100][100][100]={0};
        
        return DFS(boxes, dp, 0, boxes.size()-1, 0);        
    }
    
    int DFS(vector<int>& boxes, int dp[100][100][100], int l, int r, int k)
    {
        if (l>r) return 0;
        
        if (dp[l][r][k]!=0)
            return dp[l][r][k];                
        
        while (r>l && boxes[r]==boxes[r-1]) 
        {
            r--;
            k++;
        }
        
        dp[l][r][k] = DFS(boxes,dp,l,r-1,0) + (k+1)*(k+1);
        
        for (int i=l; i<r; i++)
        {
            if (boxes[i]==boxes[r])
            {
                dp[l][r][k] = max(dp[l][r][k], DFS(boxes,dp,l,i,k+1) + DFS(boxes,dp,i+1,r-1,0));
            }
        }
        return dp[l][r][k];
    }
};
