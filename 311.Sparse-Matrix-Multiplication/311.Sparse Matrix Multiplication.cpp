class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) 
    {
        int M=A.size();
        int N=B[0].size();
        int K=A[0].size();
        
        auto result = vector<vector<int>>(M,vector<int>(N,0));
        
        for (int i=0; i<M; i++)
         for (int k=0; k<K; k++)
         {
             if (A[i][k]==0) continue;
             
             for (int j=0; j<N; j++)
                result[i][j]+=A[i][k]*B[k][j];
         }
        
        return result;
    }
};
