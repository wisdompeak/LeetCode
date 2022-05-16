class CountIntervals {
    map<int,int>Map;
    int ret = 0;
public:
    CountIntervals() {
        
    }
    
    void add(int left, int right) 
    {
        unordered_set<int>temp;

        int start = left;
        auto iter = Map.lower_bound(left);        
        if (iter!=Map.begin() && prev(iter)->second>=start)
        {
            iter = prev(iter);
            temp.insert(iter->first);
            start = min(start, iter->first);            
        }

        int end = right;
        iter = Map.lower_bound(left);        
        if (iter!=Map.begin())
            end = max(end, prev(iter)->second);        
        while (iter!=Map.end() && iter->first<=end)
        {
            temp.insert(iter->first);
            end = max(end, iter->second);
            iter = next(iter);
        }
        
        for (int x: temp)
        {
            ret -= Map[x]-x+1;
            Map.erase(x);
        }
        ret += end-start+1;
        Map[start] = end;
    }
    
    int count() {
        return ret;
    }
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */
