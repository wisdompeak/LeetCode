class Solution {
    int inD[100000];    
    vector<int>next[100000];
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) 
    {
        int ans = 1;
        for (auto edge: edges)
        {            
            int a = edge[0], b = edge[1];
            next[a].push_back(b);
            inD[b]++;
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
        vector<int>in(n, 0);
        for (int i=0; i<n; i++)
            in[i] = inD[i];
        
        int nodes = 0;
        queue<int>q;
        for (int i=0; i<n; i++)
        {
            if (in[i]==0)
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
            
            for (auto p: next[cur])
            {
                count[p] = max(count[p], count[cur]+ (colors[p]-'a'==k));                
                ret = max(ret, count[p]);                
                in[p]--;
                if (in[p]==0)
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
