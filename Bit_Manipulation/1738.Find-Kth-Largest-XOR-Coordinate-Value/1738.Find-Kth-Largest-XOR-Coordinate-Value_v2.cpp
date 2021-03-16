class Solution {
    int a[1000][1000];
    int m,n;
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) 
    {
        m = matrix.size();
        n = matrix[0].size();
                
        a[0][0] = matrix[0][0];
        for (int i=1; i<m; i++)
            a[i][0] = a[i-1][0]^matrix[i][0];
        for (int j=1; j<n; j++)
            a[0][j] = a[0][j-1]^matrix[0][j];
        
        for (int i=1; i<m; i++)
            for (int j=1; j<n; j++)
                a[i][j] = a[i-1][j]^a[i][j-1]^a[i-1][j-1]^matrix[i][j];
        
        priority_queue<int,vector<int>,greater<>>pq;
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
            {
                pq.push(a[i][j]);
                if (pq.size()>k) pq.pop();
            }
                
        return pq.top();
    }    
};
