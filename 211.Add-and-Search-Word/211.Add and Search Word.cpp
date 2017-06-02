class WordDictionary {
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
    WordDictionary() 
    {
        root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) 
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
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) 
    {
        return DFS(word, 0, root);
    }
    
    bool DFS(string word, int i, TrieNode* node)
    {
        if (node==NULL)
            return false;
        if (i==word.size())
            return (node->isEnd);

        if (word[i]!='.')
            return DFS(word, i+1, node->next[ch=word[i]-'a']);
        else
        {
            bool flag=false;
            for (int k=0; k<26; k++)
            {
                if (DFS(word,i+1,node->next[k]))
                {
                    flag=true;
                    break;
                }    
            }
            return flag;
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */
