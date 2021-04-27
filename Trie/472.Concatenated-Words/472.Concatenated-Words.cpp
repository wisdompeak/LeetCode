class Solution {
    class TrieNode
    {
        public:
        TrieNode* next[26];
        bool isEnd;
        TrieNode()
        {
            for (int i=0; i<26; i++)
                next[i] = NULL;
            isEnd = false;
        }
    };
    TrieNode* root;
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) 
    {       
        sort(words.begin(), words.end(), [](string&a, string&b){return a.size()<b.size();});
        root = new TrieNode();

        vector<string>rets;
        for (auto word: words)
        {
            if (word!="" && check(word, root))
                rets.push_back(word);

            TrieNode* node = root;
            for (auto ch:word)
            {
                if (node->next[ch-'a']==NULL)
                    node->next[ch-'a'] = new TrieNode();
                node = node->next[ch-'a'];
            }
            node->isEnd = true;
        }
        return rets;
    }

    bool check(string& word, TrieNode* root)
    {
        int n = word.size();
        vector<int>visited(n,0);
        return dfs(word, 0, visited);
    }

    bool dfs(string& word, int cur, vector<int>&visited)
    {
        if (cur==word.size()) return true;

        if (visited[cur]==1)
            return false;

        TrieNode* node = root;

        for (int i=cur; i<word.size(); i++)
        {
            if (node->next[word[i]-'a']!=NULL)
            {
                node = node->next[word[i]-'a'];
                if (node->isEnd && dfs(word, i+1, visited))
                    return true;                
            } 
            else
            {
                break;
            }
        }

        visited[cur] = 1;
        return false;
    }
};
