class TrieNode
{
    public:
    TrieNode* next[26];
    int cost;
    TrieNode()
    {
        for (int i=0; i<26; i++)
            next[i] = NULL;
        cost = -1;
    }        
};

class Solution {
    TrieNode* root = new TrieNode();
    vector<int>memo;
public:
    int minimumCost(string target, vector<string>& words, vector<int>& costs) 
    {
        memo = vector<int>(target.size(), -1);
        
        for (int i=0; i<words.size(); i++)
        {
            TrieNode* node = root;
            for (auto ch: words[i])
            {
                if (node->next[ch-'a']==NULL)
                    node->next[ch-'a'] = new TrieNode();
                node = node->next[ch-'a'];
            }
            if (node->cost==-1)
                node->cost = costs[i];
            else
                node->cost = min(node->cost, costs[i]);
        }
        
        int ret = dfs(target, 0);        
        if (ret == INT_MAX/2) return -1;
        else return ret;
    }
    
    int dfs(string& target, int cur)
    {
        if (cur==target.size()) return 0;
        if (memo[cur] != -1) return memo[cur];
        
        int ans = INT_MAX/2;
        TrieNode* node = root;
        for (int i=cur; i<target.size(); i++)
        {
            if (node->next[target[i]-'a']==NULL)
                break;
            node = node->next[target[i]-'a'];
            if (node->cost!=-1)
                ans = min(ans, node->cost + dfs(target, i+1));
        }
        
        memo[cur] = ans;
        
        return ans;
    }
};
