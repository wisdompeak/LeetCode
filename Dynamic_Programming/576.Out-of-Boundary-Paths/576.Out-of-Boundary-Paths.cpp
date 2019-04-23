class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) 
    {
        auto p = vector<vector<int>>(m,vector<int>(n,0));
        auto q =p;
        int M=pow(10,9)+7;
        
        for (int k=0; k<N; k++)
        {
            for (int i=0; i<m; i++)
             for (int j=0; j<n; j++)
             {
                 long n1= (i==0)?1:q[i-1][j];
                 long n2= (i==m-1)?1:q[i+1][j];
                 long n3= (j==0)?1:q[i][j-1];
                 long n4= (j==n-1)?1:q[i][j+1];
                 p[i][j]=(n1+n2+n3+n4)%M;
             }
            q=p;
        }
        return p[i][j];
    }
};
