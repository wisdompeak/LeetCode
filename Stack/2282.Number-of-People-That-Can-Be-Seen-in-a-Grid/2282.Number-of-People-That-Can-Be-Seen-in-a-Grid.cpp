class Solution {
public:
    vector<vector<int>> seePeople(vector<vector<int>>& heights) 
    {        
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>>rets(m, vector<int>(n,0));
        
        for (int i=0; i<m; i++)
        {
            stack<int>stk;            
            for (int j=0; j<n; j++)
            {
                int lastRemove = -1;
                while (!stk.empty() && heights[i][j] >= heights[i][stk.top()])
                {
                    rets[i][stk.top()]++;
                    lastRemove = heights[i][stk.top()];
                    stk.pop();
                }
                if (!stk.empty() && lastRemove != heights[i][j])
                {
                    rets[i][stk.top()]++;                    
                }
                stk.push(j);
            }
                
        }           
        
        for (int j=0; j<n; j++)
        {
            stack<int>stk;            
            for (int i=0; i<m; i++)
            {
                int lastRemove = -1;
                while (!stk.empty() && heights[i][j] >= heights[stk.top()][j])
                {
                    rets[stk.top()][j]++;
                    lastRemove = heights[stk.top()][j];
                    stk.pop();
                }                
                if (!stk.empty() && lastRemove != heights[i][j])
                {
                    rets[stk.top()][j]++;                    
                }                
                stk.push(i);
            }
        }
        
        return rets;
        
    }
};
