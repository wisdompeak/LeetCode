class Solution {    
    vector<int>boxes;
    int dp[100][100][100];
    
public:
    int removeBoxes(vector<int>& boxes) 
    {                
        this->boxes = boxes;       
        return DFS(0, boxes.size()-1, 0);        
    }
    
    int DFS(int l, int r, int k)
    {
        if (l>r) return 0;
        
        if (dp[l][r][k]!=0)
            return dp[l][r][k];                
        
        int i = r;
        int count = k;
        while (i>=l && boxes[i]==boxes[r]) 
        {
            i--;
            count++;
        }        
        dp[l][r][k] = DFS(l,i,0) + count*count;
        
        for (int j=i; j>=l; j--)
        {
            if (boxes[j]!=boxes[r]) continue;
            if (boxes[j]==boxes[r] && boxes[j+1]==boxes[r]) continue;
            dp[l][r][k] = max(dp[l][r][k], DFS(l,j,count)+DFS(j+1,i,0));
        }

        // cout<<l<<" "<<r<<" "<<k<<":"<<dp[l][r][k]<<endl;

        return dp[l][r][k];
    }
};
