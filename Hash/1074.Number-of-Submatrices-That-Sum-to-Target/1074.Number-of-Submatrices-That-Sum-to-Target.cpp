class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) 
    {
        int m = matrix.size(), n = matrix[0].size();
        int count = 0;
        
        for (int i=0; i<m; i++)
        {
            vector<int>row(n);
            for (int t=i; t<m; t++)
            {
                for (int j=0; j<n; j++)
                    row[j] += matrix[t][j];
                
                unordered_map<int,int>Map;
                Map[0] = 1;
                int presum = 0;
                for (int j=0; j<n; j++)
                {
                    presum += row[j];
                    count += Map[presum - target];
                    Map[presum]+=1;
                }
            }            
        }
        return count;
        
    }
};
