class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) 
    {
        int n = heights.size();
        
        for (int i=0; i<queries.size(); i++)
        {            
            sort(queries[i].begin(), queries[i].end());
            queries[i].push_back(i);
        }
        
        sort(queries.begin(), queries.end(), [](vector<int>&a, vector<int>&b){
            return a[1]>b[1];
        });        
        
        vector<int>rets(queries.size());
        int i = n-1;
        map<int,int>Map;
        for (auto& query: queries)
        {
            int a = query[0], b = query[1], idx = query[2];
            while (i>=b)
            {
                while (!Map.empty() && heights[i] >= (Map.begin()->first))
                    Map.erase(Map.begin());
                Map[heights[i]] = i;
                i--;
            }
            
            if (heights[a] < heights[b] || a==b)
            {
                rets[idx] = b;
                continue;
            }
            
            int m = max(heights[a],heights[b]);
            auto iter = Map.upper_bound(m);
            if (iter!=Map.end())
                rets[idx] = iter->second;
            else
                rets[idx] = -1;
        }
        
        return rets;
    }
};
