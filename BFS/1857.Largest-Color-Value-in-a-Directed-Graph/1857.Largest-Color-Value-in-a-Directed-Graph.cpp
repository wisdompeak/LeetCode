class Solution {
    int outD[100000];    
    vector<int>prev[100000];
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) 
    {
        int ans = 1;
        for (auto edge: edges)
        {            
            int a = edge[0], b = edge[1];
            prev[b].push_back(a);
            outD[a]++;
        }
        
        unordered_set<char>Set(colors.begin(), colors.end());
        for (char ch='a'; ch<='z'; ch++)
        {
            if (Set.find(ch)==Set.end()) continue;
            int t = helper(ch-'a', colors, edges);
            if(t==-1) return -1;
            ans = max(ans, t);
        }
        return ans;        
    }
    
    int helper(int k, string colors, vector<vector<int>>& edges) 
    {
        int n = colors.size();
        vector<int>count(n, 0);
        vector<int>out(n, 0);
        for (int i=0; i<n; i++)
            out[i] = outD[i];
        
        int nodes = 0;
        queue<int>q;
        for (int i=0; i<n; i++)
        {
            if (out[i]==0)
            {
                nodes++;
                if (colors[i]-'a'==k) count[i]++;
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
                count[p] = max(count[p], count[cur]+ (colors[p]-'a'==k));                
                ret = max(ret, count[p]);                
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
