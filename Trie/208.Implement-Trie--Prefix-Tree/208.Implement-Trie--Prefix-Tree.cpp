class Trie {
    class TrieNode
    {
        public:
            TrieNode* next[26];
            bool isEnd;
        TrieNode()
        {
            for (int i=0; i<26; i++)
                next[i]=NULL;
            isEnd=false;
        }
    };
    TrieNode* root;
        
public:
    /** Initialize your data structure here. */
    Trie() 
    {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) 
    {
        TrieNode* node=root;
        for (int i=0; i<word.size(); i++)
        {
            char ch=word[i];
            if (node->next[ch-'a']==NULL)
                node->next[ch-'a']=new TrieNode();
            node=node->next[ch-'a'];
        }
        node->isEnd=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) 
    {
        TrieNode* node=root;
        for (int i=0; i<word.size(); i++)
        {
            char ch=word[i];
            if (node->next[ch-'a']==NULL)
                return false;
            node=node->next[ch-'a'];
        }
        if (node->isEnd==false)
            return false;
        else
            return true;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) 
    {
        TrieNode* node=root;
        for (int i=0; i<prefix.size(); i++)
        {
            char ch=prefix[i];
            if (node->next[ch-'a']==NULL)
                return false;
            node=node->next[ch-'a'];
        }
        return true;        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
