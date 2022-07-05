class Solution {
    vector<pair<int,int>> nxt[50000];    
public:    
    int maximumScore(vector<int>& scores, vector<vector<int>>& edges) 
    {
        int n = scores.size();
        for (auto edge: edges)
        {
            int a= edge[0], b=edge[1];
            nxt[a].push_back({scores[b],b});
            nxt[b].push_back({scores[a],a});
        }
        for (int i=0; i<n; i++)
        {
            sort(nxt[i].rbegin(), nxt[i].rend());
            if (nxt[i].size() > 3)
                nxt[i].resize(3);
        }
        
        int ret = -1;
        
        for (auto edge: edges)
        {
            int a= edge[0], b=edge[1];
            for (auto& [_, i] : nxt[a])
                for (auto & [_, j] : nxt[b])
                {
                    if (i==j) continue;
                    if (i==b || j==a) continue;
                    ret = max(ret, scores[i]+scores[a]+scores[b]+scores[j]);
                    break;
                }            
        }      

        return ret;      
    }
};
