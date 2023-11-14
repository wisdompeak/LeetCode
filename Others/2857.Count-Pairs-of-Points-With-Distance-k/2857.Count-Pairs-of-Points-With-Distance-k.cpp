class Solution {
public:
    int countPairs(vector<vector<int>>& coordinates, int k) 
    {
        int ret = 0;
        unordered_map<long long, int>Map;
        for (int i=0; i<coordinates.size(); i++)
        {
            int x1 = coordinates[i][0];
            int y1 = coordinates[i][1];

            for (int a = 0; a <=k; a++)
            {
                
                int x2 = a^x1;
                int y2 = (k-a)^y1;

                long long code = (long long)x2 * 1000000 + y2;
                if (Map.find(code)!=Map.end())
                    ret += Map[code];
    
            }

            long long code = (long long)x1 * 1000000 + y1;
            Map[code] += 1;
        }

        return ret;        
    }
};
