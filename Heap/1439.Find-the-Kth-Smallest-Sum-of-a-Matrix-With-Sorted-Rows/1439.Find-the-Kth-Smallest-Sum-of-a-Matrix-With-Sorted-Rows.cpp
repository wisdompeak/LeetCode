class Solution {
    
public:
    int kthSmallest(vector<vector<int>>& mat, int k) 
    {
        int m = mat.size();
        int n = mat[0].size();
        int sum = 0;
        for (int i=0; i<m; i++) sum+=mat[i][0];        
        set<pair<int,vector<int>>>Set;
        Set.insert({sum, vector<int>(m,0)});
        int count = 0;
        
        while (Set.size()>0)
        {
            auto [val, idx] = *Set.begin();
            Set.erase(Set.begin());
            count++;
            if (count==k) return val;
            
            for (int i=0; i<m; i++)
            {
                if (idx[i]<n-1)
                {
                    auto idx2 = idx;
                    auto val2= val;
                    val2 += mat[i][idx2[i]+1] - mat[i][idx2[i]];
                    idx2[i]++;
                    Set.insert({val2, idx2});                    
                }
            }
        }
        
        return -1;        
    }        
};
