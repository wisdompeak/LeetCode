class Solution {
public:
    vector<int> amountPainted(vector<vector<int>>& paint) 
    {
        map<int, vector<pair<int,int>>>Map; // pos->{idx, flag}
        for (int i=0; i<paint.size(); i++)
        {
            Map[paint[i][0]].push_back({i,1});
            Map[paint[i][1]].push_back({i,-1});
        }
        
        vector<pair<int, vector<pair<int,int>>>>array(Map.begin(), Map.end());
        
        set<int>Set;
        int n = paint.size();
        vector<int>rets(n);        
        for (int i=0; i<array.size(); i++)
        {                 
            for (auto& [idx, flag]: array[i].second )
            {
                if (flag==1)
                    Set.insert(idx);
                else
                    Set.erase(idx);
            }
            if (!Set.empty())
            {
                rets[*Set.begin()] += array[i+1].first - array[i].first;
            }
        }
        
        return rets;        
    }
};
