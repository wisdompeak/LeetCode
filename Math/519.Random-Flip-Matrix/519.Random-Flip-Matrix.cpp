class Solution {
    int m,n;
    int count;
    unordered_map<int,int>Map;
public:
    Solution(int n_rows, int n_cols) {
        m = n_rows;
        n = n_cols;
        count = 0;
    }
    
    vector<int> flip() 
    {
        int k = rand()%(m*n-count);
        int ret;
        
        count++;
        
        if (Map.find(k)!=Map.end())
            ret = Map[k];
        else
            ret = k;
        
        if (Map.find(m*n-count)!=Map.end())
            Map[k] = Map[m*n-count];
        else
            Map[k] = m*n-count;
        
        return {ret/n,ret%n};
        
    }
    
    void reset() 
    {
        Map.clear();
        count = 0;
    }
};
