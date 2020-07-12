class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) 
    {
        unordered_map<int,int>fill; // fill[x] is the last day that rain filled lake x        
        set<int>dryDays;         // the days that are dry, i.e. when we can drain
        vector<int>rets(rains.size(),1);
        
        for (int i=0; i<rains.size(); i++)
        {
            int x = rains[i];
            if (x==0)            
                dryDays.insert(i);            
            else
            {
                rets[i] = -1;
                if (fill.find(x)!=fill.end())
                {
                    auto iter = dryDays.lower_bound(fill[x]);
                    if (iter==dryDays.end()) return {};                    
                    rets[*iter] = x;  
                    dryDays.erase(*iter);                    
                }
                fill[x] = i;
            }            
        }        
        return rets;        
    }
};
