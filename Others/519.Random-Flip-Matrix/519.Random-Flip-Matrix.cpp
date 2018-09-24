class Solution {
    int M,N;
    unordered_map<int,int>Map;
    int count;    
public:
    Solution(int n_rows, int n_cols) 
    {
        M = n_rows;
        N = n_cols;
        count = 0;
    }
    
    vector<int> flip() 
    {
        int result;        
        int k = rand()%(M*N-count);
        
        if (Map.find(k)==Map.end())
            result = k;
        else
            result = Map[k];
        
        int MAX = M*N-1-count;
        if (Map.find(MAX)==Map.end())
            Map[k] = MAX;
        else
            Map[k] = Map[MAX];
    
        count++;
        return {result/N, result%N};
    }
    
    void reset() 
    {
        Map.clear();
        count= 0 ;        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(n_rows, n_cols);
 * vector<int> param_1 = obj.flip();
 * obj.reset();
 */
