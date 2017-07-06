class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) 
    {
        int M=matrix.size();
        if (M==0) return 0;
        int N=matrix[0].size();
        
        auto sum=vector<vector<int>>(M+1,vector<int>(N+1,0));
        
        for (int i=1; i<M+1; i++)
            for (int j=1; j<N+1; j++)
            {
                sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+matrix[i-1][j-1]-'0';
            }
            
        /*
        for (int i=1; i<M+1; i++)
        {
            for (int j=1; j<N+1; j++)
            {
                cout<<sum[i][j]<<" ";
            }
            cout<<endl;
        }
        */
        
        int result = 0;
        
        for (int i=1; i<M+1; i++)
            for (int j=1; j<N+1; j++)
            {
                int k=1;
                while (j-k>=0 && i-k>=0)
                {
                    int temp = sum[i][j]-sum[i-k][j]-sum[i][j-k]+sum[i-k][j-k];
                    if (temp == k*k)
                        result = max(result, temp);
                    k++;    
                }
            }
            
        return result;
        
    }
};
