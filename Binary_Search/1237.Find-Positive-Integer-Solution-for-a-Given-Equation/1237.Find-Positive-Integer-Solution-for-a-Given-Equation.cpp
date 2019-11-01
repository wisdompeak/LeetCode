/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */

class Solution {
    set<vector<int>>Set;
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) 
    {
        dfs(customfunction,z,1,1000,1,1000);
        vector<vector<int>>rets(Set.begin(),Set.end());
        return rets;        
    }
    
    void dfs(CustomFunction& customfunction, int z, int x1, int x2, int y1, int y2)
    {
        if (x1==x2 && y1==y2)
        {
            if (customfunction.f(x1,y1)==z)
                Set.insert({x1,y1});
            return;
        }
        if (x1>x2 || y1>y2)
            return;
        
        int midX = x1+(x2-x1)/2;
        int midY = y1+(y2-y1)/2;
        
        int val = customfunction.f(midX, midY);
        
        if (val==z)
        {
            Set.insert({midX,midY});
            dfs(customfunction,z,midX+1,x2,y1,midY-1);
            dfs(customfunction,z,x1,midX-1,midY+1,y2);
            
        }
        else if (val<z)
        {
            dfs(customfunction,z,midX+1,x2,y1,y2);
            dfs(customfunction,z,x1,x2,midY+1,y2);           
        }
        else
        {
            dfs(customfunction,z,x1,midX-1,y1,y2);
            dfs(customfunction,z,x1,x2,y1,midY-1);    
        }
    }
};


