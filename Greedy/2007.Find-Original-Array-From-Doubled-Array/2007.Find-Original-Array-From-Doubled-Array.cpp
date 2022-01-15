class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) 
    {        
        int n = changed.size();
        if (n%2!=0) return {};
        
        multiset<int>Set(changed.begin(), changed.end());
        vector<int>rets;
        for (int t=0; t<n/2; t++)
        {
            int mx = *prev(Set.end());
            if (mx%2!=0)
                return {};
            if (Set.find(mx/2)==Set.end())
                return {};
            Set.erase(Set.lower_bound(mx));
            Set.erase(Set.lower_bound(mx/2));
            rets.push_back(mx/2);
        }
        return rets;
    }
};
