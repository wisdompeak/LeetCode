class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) 
    {
        auto p = vector<vector<long long>>(m,vector<long long>(n,0));
        vector<vector<long long>> q =p;
        long long M=pow(10,9)+7;
        
        for (int k=0; k<N; k++)
        {
            for (int i=0; i<m; i++)
             for (int j=0; j<n; j++)
             {
                 long long n1= (i==0)?1:q[i-1][j];
                 long long n2= (i==m-1)?1:q[i+1][j];
                 long long n3= (j==0)?1:q[i][j-1];
                 long long n4= (j==n-1)?1:q[i][j+1];
                 p[i][j]=(n1+n2+n3+n4)%M;
             }
            q=p;
        }
        return p[i][j];
    }
};
