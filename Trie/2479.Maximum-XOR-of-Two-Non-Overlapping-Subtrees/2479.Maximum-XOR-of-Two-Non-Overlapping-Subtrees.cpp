using LL = long long;

class Solution {
    vector<int>next[50005];
    LL val[50005];
    vector<int>values;

    class TrieNode
    {
        public:
        TrieNode* next[2];
        TrieNode(){
            for (int i=0; i<2; i++)
                next[i] = NULL;
        }
    };
    TrieNode* root;

    LL ret = 0;

public:
    void insert(LL num)
    {
        TrieNode* node = root;
        for (int i=63; i>=0; i--)
        {
            int d = ((num>>i)&1);
            if (node->next[d]==NULL)
                node->next[d] = new TrieNode();
            node = node->next[d];
        }
    }

    LL find(LL num)
    {
        TrieNode* node = root;   
        if (root->next[0]==NULL && root->next[1]==NULL) return 0;     
        LL ret = 0;
        for (int i=63; i>=0; i--)
        {
            int d = ((num>>i)&1);
            if (node->next[1-d]!=NULL)
            {
                ret += (1LL<<i);
                node = node->next[1-d];
            }
            else
            {
                ret += 0;
                node = node->next[d];
            }
        }
        return ret;
    }

    long long maxXor(int n, vector<vector<int>>& edges, vector<int>& values) 
    {
        this->values = values;
        for (auto& edge: edges)
        {
            int a = edge[0], b = edge[1];
            next[a].push_back(b);
            next[b].push_back(a);
        }

        root = new TrieNode();

        dfs(0, -1);
        
        dfs2(0, -1);

        return ret;
    }

    LL dfs(int cur, int parent)
    {
        LL v = values[cur];
        for (int nxt: next[cur])
        {
            if (nxt==parent) continue;
            v = v + dfs(nxt, cur);
        }
        val[cur] = v;     
        return v;
    }

    void dfs2(int cur, int parent)
    {        
        for (int nxt: next[cur])
        {
            if (nxt==parent) continue;            
            ret = max(ret, find(val[nxt]));
            dfs2(nxt, cur);            
            insert(val[nxt]);
        }
    }
};
