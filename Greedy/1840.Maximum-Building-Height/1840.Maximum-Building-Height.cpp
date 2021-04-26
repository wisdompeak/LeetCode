class Solution {    
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) 
    {           
        
        restrictions.push_back({1,0});
        sort(restrictions.begin(), restrictions.end());
        
        int m = restrictions.size();
        vector<int>h(m);
        
        for (int i=1; i<m; i++)
        {
            h[i] = min(restrictions[i][1], h[i-1] + restrictions[i][0] - restrictions[i-1][0]);
        }
        
        for (int i=m-2; i>=1; i--)
        {
            h[i] = min(h[i], h[i+1] + restrictions[i+1][0] - restrictions[i][0]);
        }
        
        int ret = 0;
        for (int i=1; i<m; i++)
        {
            int y = ((h[i-1]-h[i]) - (restrictions[i-1][0]-restrictions[i][0]))/2;
            ret = max(ret, h[i]+y);
        }
        
        ret = max(ret, h[m-1] + n - restrictions[m-1][0]);
        
        return ret;
    }
};
