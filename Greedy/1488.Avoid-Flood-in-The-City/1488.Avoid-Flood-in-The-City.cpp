class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) 
    {
        unordered_map<int,int>pos; // pos[x] is the last day that rain fell on lake x        
        set<int>Set;         // the days that are dry, i.e. when we can drain
        vector<int>rets(rains.size(),1);
        
        for (int i=0; i<rains.size(); i++)
        {
            int x = rains[i];
            if (x==0)            
                Set.insert(i);            
            else
            {
                rets[i] = -1;
                if (pos.find(x)!=pos.end())
                {
                    auto iter = Set.lower_bound(pos[x]);
                    if (iter==Set.end()) return {};                    
                    rets[*iter] = x;  
                    Set.erase(*iter);                    
                }
                pos[x] = i;
            }            
        }        
        return rets;        
    }
};
