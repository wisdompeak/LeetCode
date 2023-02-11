class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) 
    {
        map<int,int>Map;
        for (int x: basket1)
            Map[x]++;
        for (int x: basket2)
            Map[x]--;
        
        int t = Map.begin()->first;
        
        vector<int>a;
        for (auto [k,v]: Map)
        {
            if (v%2!=0) return -1;
            if (v>0)
            {
                for (int i=0; i<v/2; i++)
                    a.push_back(k);
            }
            else
            {
                for (int i=0; i<abs(v/2); i++)
                    a.push_back(k);
            }
        }
        
        sort(a.begin(), a.end());
        
        int n = a.size();
        long long ret = 0;
        for (int i=0; i<n/2; i++)
            ret += min(a[i], 2*t);
        
        return ret;
    }
};
