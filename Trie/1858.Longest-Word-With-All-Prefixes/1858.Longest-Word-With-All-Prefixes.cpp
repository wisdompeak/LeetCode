class Solution {
    class TrieNode {
        public:
        TrieNode* next[26];
        bool isEnd;
        TrieNode() {
            for (int i=0; i<26; i++)
                next[i] = NULL;
            isEnd = false;            
        }        
    };
    TrieNode* root;
    string ret;
public:
    string longestWord(vector<string>& words) 
    {
        root = new TrieNode();
        for (auto word: words)
        {
            TrieNode* p = root;
            for (int i=0; i<word.size(); i++)
            {
                if (p->next[word[i]-'a']==NULL)
                    p->next[word[i]-'a'] = new TrieNode();
                p = p->next[word[i]-'a'];
            }
            p->isEnd = true;
        }
        
        string ans;
        dfs(root, ans);
        return ret;
    }
    
    void dfs(TrieNode* node, string ans)
    {
        if (ans.size() > ret.size())
            ret = ans;
        
        for (int i=0; i<26; i++)
        {
            if (node->next[i]==NULL) continue;
            if (node->next[i]->isEnd==false) continue;
            ans.push_back('a'+i);
            dfs(node->next[i], ans);
            ans.pop_back();
        }
    }

};
