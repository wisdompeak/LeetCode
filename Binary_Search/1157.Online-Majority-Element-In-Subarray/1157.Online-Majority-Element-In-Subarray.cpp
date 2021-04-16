class MajorityChecker {
    unordered_map<int,vector<int>>Map;
    vector<pair<int,int>>q;
public:
    MajorityChecker(vector<int>& arr) 
    {
        for (int i=0; i<arr.size(); i++)
            Map[arr[i]].push_back(i);
                
        for (auto x: Map)
            q.push_back({x.second.size(),x.first});
        sort(q.begin(),q.end());        
        reverse(q.begin(),q.end());
    }
    
    int query(int left, int right, int threshold) 
    {
        int total = right-left+1;
        for (int i=0; i<q.size(); i++)
        {
            int num = q[i].second;
            int pos1 = lower_bound(Map[num].begin(), Map[num].end(), left) - Map[num].begin();
            int pos2 = upper_bound(Map[num].begin(), Map[num].end(), right) - Map[num].begin();
            
            if (pos2-pos1>=threshold)
                return num;
            else
                total -= pos2-pos1;
            
            if (total < threshold)
                return -1;
            if (Map[num].size() < threshold)
                return -1;
        }
        return -1;
    }
};
