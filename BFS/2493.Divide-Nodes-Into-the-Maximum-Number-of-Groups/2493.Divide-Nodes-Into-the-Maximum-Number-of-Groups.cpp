class Solution {
    vector<int>next[505];
public:
    int magnificentSets(int n, vector<vector<int>>& edges) 
    {
        for (auto edge: edges)
        {
            int a = edge[0], b = edge[1];
            next[a].push_back(b);
            next[b].push_back(a);
        }
        
        unordered_map<int,int>Map;
        
        for (int start=1; start<=n; start++)
        {
            int d = 0;
            int smallestId = INT_MAX;
            vector<int>level(505);
            
            queue<int>q; 
            q.push(start);
            level[start] = 1;
            
            while (!q.empty())
            {
                d++;
                int len = q.size();                
                while (len--)
                {
                    int cur = q.front();
                    q.pop();                                        
                    smallestId = min(smallestId, cur);

                    for (int nxt: next[cur])
                    {
                        if (level[nxt] == 0)
                        {
                            level[nxt] = d+1;
                            q.push(nxt);
                        }
                        else if (level[nxt] == d)
                        {
                            return -1;
                        }
                    }                    
                }
            }
            
            Map[smallestId] = max(Map[smallestId], d);
        }
        
        int ret = 0;
        for (auto [k, v]: Map)
            ret += v;
        
        return ret;        
    }
};



    
