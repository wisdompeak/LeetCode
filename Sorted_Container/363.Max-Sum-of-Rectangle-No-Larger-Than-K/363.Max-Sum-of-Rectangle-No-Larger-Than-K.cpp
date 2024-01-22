class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) 
    {
        int M = matrix.size();
        if (M==0) return 0;
        int N = matrix[0].size();
        
        if (M>N)
        {
            vector<vector<int>>matrix2(N,vector<int>(M,0));
            for (int i=0; i<M; i++)
                for (int j=0; j<N; j++)
                    matrix2[j][i]=matrix[i][j];
            return maxSumSubmatrix(matrix2,k);
        }
        
        int result = INT_MIN;
        
        for (int i=0; i<M; i++)        
        {
            vector<int>row(N,0);
            for (int j=i; j<M; j++)
            {
                for (int k=0; k<N; k++)
                    row[k]+=matrix[j][k];
                result = max(result,helper(row,k));
            }
        }        
        return result;
    }
    
    int helper(vector<int>&row, int k)
    {
        set<int>Set({0});
        int preSum = 0;
        int result = INT_MIN;
        for (int i=0; i<row.size(); i++)
        {
            preSum+=row[i];
            auto iter = Set.lower_bound(preSum-k);
            if (iter!=Set.end()) 
                result = max(result,preSum-*iter);
            Set.insert(preSum);
        }
        return result;
    }    
};
