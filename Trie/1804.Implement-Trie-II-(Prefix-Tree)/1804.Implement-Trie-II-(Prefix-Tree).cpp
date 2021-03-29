class Trie {
    class TrieNode
    {
        public:
        TrieNode* next[26];
        int count1;
        int count2;
        TrieNode()
        {
            count1=0;
            count2=0;
            for (int i=0; i<26; i++)
                next[i] = NULL;            
        }
    };
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) 
    {
        TrieNode* node = root;
        for (auto ch: word)
        {
            if (node->next[ch-'a']==NULL)
                node->next[ch-'a'] = new TrieNode();
            node = node->next[ch-'a'];
            node->count1++;
        }
        node->count2++;
    }
    
    int countWordsEqualTo(string word) 
    {
        TrieNode* node = root;
        for (auto ch: word)
        {
            if (node->next[ch-'a']==NULL)
                return 0;
            node = node->next[ch-'a'];            
        }
        return node->count2;        
    }
    
    int countWordsStartingWith(string prefix) 
    {
        TrieNode* node = root;
        for (auto ch: prefix)
        {
            if (node->next[ch-'a']==NULL)
                return 0;
            node = node->next[ch-'a'];            
        }
        return node->count1;
        
    }
    
    void erase(string word) 
    {
        TrieNode* node = root;
        for (auto ch: word)
        {
            node->next[ch-'a']->count1--;            
            if (node->next[ch-'a']->count1 == 0)
            {
                node->next[ch-'a'] = NULL;
                return;
            }
            else
            {
                node = node->next[ch-'a'];
            }
        }
        node->count2--;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * int param_2 = obj->countWordsEqualTo(word);
 * int param_3 = obj->countWordsStartingWith(prefix);
 * obj->erase(word);
 */
