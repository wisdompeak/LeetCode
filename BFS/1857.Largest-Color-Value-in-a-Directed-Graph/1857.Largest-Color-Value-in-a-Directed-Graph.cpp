class Solution {
    int out[100000];
    int num[100000];
    vector<int>prev[100000];
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) 
    {
        int ans = 1;
        unordered_set<int>Set;
        for (auto c: colors)
            Set.insert(c-'a');       
        
        for (int k=0; k<26; k++)
        {
            if (Set.find(k)==Set.end()) continue;
            int t = helper(k, colors, edges);
            if(t==-1) return -1;
            ans = max(ans, t);
        }
        return ans;
        
    }
    
    int helper(int k, string colors, vector<vector<int>>& edges) 
    {
        int n = colors.size();
        for (int i=0; i<n; i++)
        {
            out[i] = 0;
            num[i] = 0;
            prev[i].clear();
        }
        
        for (auto edge: edges)
        {            
            int a = edge[0], b = edge[1];
            prev[b].push_back(a);
            out[a]++;                        
        }
        
        int nodes = 0;
        queue<int>q;
        for (int i=0; i<n; i++)
        {
            if (out[i]==0)
            {
                nodes++;
                if (colors[i]-'a'==k) num[i]++;
                q.push({i});
            }
        }
        
        int ret = 0;
        while (!q.empty())
        {
            auto cur = q.front();
            q.pop();            
            
            for (auto p: prev[cur])
            {
                num[p] = max(num[p], num[cur]+ (colors[p]-'a'==k));                
                ret = max(ret, num[p]);
                
                out[p]--;
                if (out[p]==0)
                {                    
                    nodes++;
                    q.push(p);                 
                }
            }            
        }
        
        if (nodes!=n) return -1;
        return ret;
    }
};
