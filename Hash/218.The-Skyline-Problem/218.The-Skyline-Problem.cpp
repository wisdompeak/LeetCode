class Solution {

public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) 
    {
        vector<pair<int,int>>edges;
        
        for (int i=0; i<buildings.size(); i++)
        {
            edges.push_back({buildings[i][0],-buildings[i][2]});
            edges.push_back({buildings[i][1],buildings[i][2]});
        }
        
        sort(edges.begin(),edges.end());
        
        vector<pair<int, int>>results;
        multiset<int>Set;
        Set.insert(0);
        int cur = 0;
            
        for (int i=0; i<edges.size(); i++)
        {
            if (edges[i].second<0)            
                Set.insert(-edges[i].second);
            else
                Set.erase(Set.find(edges[i].second));
                                                
            if (cur != *prev(Set.end(),1))                           
                results.push_back({edges[i].first,*Set.rbegin()});                
            cur = *Set.rbegin();           
        }
        
        return results;
    }
};
