class Solution {
    unordered_set<int>next[100005];
public:
    bool isPossible(int n, vector<vector<int>>& edges) 
    {
        for (auto& edge: edges)
        {
            int a = edge[0], b = edge[1];
            next[a].insert(b);
            next[b].insert(a);
        }
        
        vector<int>odds;
        for (int i=1; i<=n; i++)
        {
            if ((next[i].size()) % 2 == 1)
                odds.push_back(i);
        }

        if (odds.size()==0) return true;

        if (odds.size()==2)
        {
            int a = odds[0], b= odds[1];
            if (next[a].find(b)==next[a].end())
                return true;
            else for (int i=1; i<=n; i++)
            {
                if (i==a || i==b) continue;
                if (next[i].find(a)==next[i].end() && next[i].find(b)==next[i].end() )
                    return true;
            }
                
            return false;
        }

        if (odds.size() == 4)
        {
            int a = odds[0], b= odds[1], c= odds[2], d=odds[3];
            if (next[a].find(b)==next[a].end() && next[c].find(d)==next[c].end())
                return true;
            if (next[a].find(c)==next[a].end() && next[b].find(d)==next[b].end())
                return true;
            if (next[a].find(d)==next[a].end() && next[b].find(c)==next[b].end())
                return true;
            return false;
        }

        return false;
    }
};
