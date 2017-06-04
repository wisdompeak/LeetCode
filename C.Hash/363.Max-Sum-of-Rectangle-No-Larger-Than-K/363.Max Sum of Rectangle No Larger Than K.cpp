class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) 
    {
        int M=matrix.size();
        int N=matrix[0].size();
        
        if (M>N)
        {
            vector<vector<int>>matrix2(N,vector<int>(M,0));
            for (int i=0; i<M; i++)
                for (int j=0; j<N; j++)
                    matrix2[j][i]=matrix[i][j];
            return maxSumSubmatrix(matrix2,k);
        }
        
        vector<vector<int>>sums(M+1,vector<int>(N,0));
        for (int i=1; i<=M; i++)
            for (int j=0; j<N; j++)
                sums[i][j]=sums[i-1][j]+matrix[i-1][j];
        
        int result=INT_MIN;
        
        
        for (int a=1; a<=M; a++)
            for (int b=1; b<=a; b++)
            {
                vector<int>sum(N,0);
                for (int j=0; j<N; j++)
                    sum[j]=sums[a][j]-sums[b-1][j];
                
                //cout<<a<<" "<<b<<endl;

                set<int>Set;
                Set.insert(0);
                int CurSum=0;
                for (int j=0; j<N; j++)
                {
                    CurSum+=sum[j];
                    
                    auto it = Set.lower_bound(CurSum-k);
                    if (it!=Set.end()) 
                        result = max(result,CurSum-*it);
                    Set.insert(CurSum);
                    
                    //cout<<result<<" ";
                    
                }
                
                cout<<endl;
            }
            
        return result;
        
        
    }
};
