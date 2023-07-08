using LL = long long;
class Solution {
    int n;
public:
    LL encode(LL x, LL y)
    {
        return x*n + y;
    }
    
    vector<long long> countBlackBlocks(int m, int n, vector<vector<int>>& coordinates) 
    {
        unordered_map<LL, int>Map;
        this->n = n;
                
        int count = 0;
        for (auto& c: coordinates)
        {
            int x = c[0], y = c[1];
            for (int i=x-1; i<=x; i++)
                for (int j=y-1; j<=y; j++)
                {
                    if (i>=0 && i<m-1 && j>=0 && j<n-1)
                    Map[encode(i,j)]+=1;            
                }                    
        }
        
        vector<LL>rets(5);
        for (auto [k,v]: Map)
            rets[v]+=1;            
        
        rets[0] = LL(m-1)*LL(n-1) - rets[1] - rets[2] - rets[3] -rets[4];      
        
        return rets;      
    }
};
