class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) 
    {
        vector<vector<int>>edges;
        for (int i=0;i<buildings.size(); i++)
        {
            edges.push_back({buildings[i][0],-buildings[i][2]});
            edges.push_back({buildings[i][1],buildings[i][2]});
        }
        
        sort(edges.begin(),edges.end());
        
        multiset<int>Set={0};        
        vector<pair<int, int>>results;
        int cur=0;
        
        for (int i=0; i<edges.size(); i++)
        {
            if (edges[i][1]<0) 
                Set.insert(-edges[i][1]);
            else
                Set.erase(Set.lower_bound(edges[i][1]));
            
            int H=*Set.rbegin();
            if (cur!=H)
                results.push_back({edges[i][0],H});
            cur=H;
        }
        
        return results;
    }
};
