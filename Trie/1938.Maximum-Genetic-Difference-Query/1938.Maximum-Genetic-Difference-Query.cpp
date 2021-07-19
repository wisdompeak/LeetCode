class Solution {
    class TrieNode
    {
        public:
        TrieNode* next[26];
        int count;
        TrieNode()
        {        
            count = 0;
            for (int i=0;i<26;i++)
                next[i] = NULL;
        }
    };
    TrieNode* root;
    
    vector<int>next[100005];
    vector<int>rets;
    unordered_map<int, vector<pair<int,int>>>Map;
    
public:
    vector<int> maxGeneticDifference(vector<int>& parents, vector<vector<int>>& queries) 
    {
        int n = parents.size();
        rets.resize(queries.size());
        int start = -1;
        
        for (int i=0; i<parents.size(); i++)
        {
            if (parents[i]!=-1)
                next[parents[i]].push_back(i);
            else
                start = i;
        }        
        
        for (int i=0; i<queries.size(); i++)
        {
            int cur = queries[i][0];
            int val = queries[i][1];
            Map[cur].push_back({val, i});
        }
        
        root = new TrieNode();
        dfs(start);
        
        return rets;        
    }
    
    void dfs(int cur)
    {
        TrieNode* node = root;
        for (int i=31; i>=0; i--)
        {
            int d = ((cur>>i)&1);
            if (node->next[d]==NULL)
                node->next[d] = new TrieNode();
            node = node->next[d];
            node->count+=1;
        }
        
        for (auto x: Map[cur])
        {
            int val = x.first;
            int idx = x.second;
                        
            TrieNode* node = root;
            int ans = 0;
            for (int i=31; i>=0; i--)
            {
                int d = ((val>>i)&1);
                if (node->next[1-d]==NULL || node->next[1-d]->count==0)
                {
                    node = node->next[d];
                    ans = ans*2 + (d);                    
                }                    
                else
                {
                    node = node->next[1-d];
                    ans = ans*2 + (1-d);                    
                }
            }
            
            rets[idx] = val^ans;
        }
        
        for (auto nxt: next[cur])
        {
            dfs(nxt);
        }
        
        node = root;
        for (int i=31; i>=0; i--)
        {
            int d = ((cur>>i)&1);            
            node = node->next[d];
            node->count-=1;
        }
    }
};
