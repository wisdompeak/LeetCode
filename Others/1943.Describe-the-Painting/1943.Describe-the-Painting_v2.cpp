using LL = long long;
class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) 
    {        
        map<LL, LL>diffPairs;     
        
        for (auto seg: segments)
        {
            diffPairs[seg[0]] += seg[2];
            diffPairs[seg[1]] -= seg[2];
        }
        
        LL start = -1, end = -1;        
        LL sum = 0;
        vector<vector<LL>>rets;
        
        for (auto x: diffPairs)
        {
            auto [pos, diff] = x;
            
            if (start == -1)
                start = pos;
            else
            {
                end = pos;
                rets.push_back({start, end, sum});
                start = end;
            }
            
            sum += diff;
            
            if (sum==0)
                start = -1;
        }
        
        return rets;
    }
};
