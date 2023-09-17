using LL = long long;
class Solution {
public:
    int countPairs(vector<vector<int>>& coordinates, int k) 
    {
        int n = coordinates.size();
        
        int ret = 0;
        for (int a = 0; a<=k; a++)
        {
            unordered_map<LL,int>Map;
            
            for (int i=0; i<n; i++)
            {
                int x1 = coordinates[i][0];
                int y1 = coordinates[i][1];
                int x2 = a^x1;
                int y2 = (k-a)^y1;
                
                long long code = (long long)x2*10000000 + y2;
                
                if (Map.find(code)!=Map.end())
                    ret += Map[code];
                
                code = (long long)x1*10000000 + y1;
                
                Map[code]+=1;
            }
        }
        
        return ret;
        
    }
};
