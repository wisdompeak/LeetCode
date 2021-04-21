class Solution {
    class TrieNode
    {
        public:
        TrieNode* next[26];
        bool end;
        TrieNode()
        {
            end = false;
            for (int i=0;i<26;i++)
                next[i] = NULL;
        }
    };
    TrieNode* root;
    int memo[300];
public:
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        root = new TrieNode();
        for (auto word: wordDict)
        {
            TrieNode* node = root;
            for (auto ch: word)
            {
                if (node->next[ch-'a']==NULL)
                    node->next[ch-'a'] = new TrieNode();
                node = node->next[ch-'a'];
            }
            node->end = true;
        }
        
        return dfs(s,0);          
    }
    
    bool dfs(string&s, int cur)
    {
        if (memo[cur]==1) return false;
        
        if (cur==s.size())
            return true;
        
        TrieNode* node = root;
        for (int i=cur; i<s.size(); i++)
        {           
            if (node->next[s[i]-'a']!=NULL)
            {
                node = node->next[s[i]-'a'];
                if (node->end==true && dfs(s, i+1))
                    return true;
            } else
            {
                break;
            }
        }
        
        memo[cur] = 1;
        return false;
    }
};
