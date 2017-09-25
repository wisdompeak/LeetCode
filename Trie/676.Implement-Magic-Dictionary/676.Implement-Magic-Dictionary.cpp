class MagicDictionary {
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
    MagicDictionary() 
    {
        root = new TrieNode();
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) 
    {        
        for (int i=0; i<dict.size(); i++)
        {
            TrieNode* node=root;
            string str=dict[i];
            for (int j=0; j<str.size(); j++)
            {
                if (node->next[str[j]-'a']==NULL)
                    node->next[str[j]-'a']=new TrieNode();
                node=node->next[str[j]-'a'];
            }
            node->isEnd=true;
        }
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) 
    {
         return DFS_search(word,root);
    }
    
    bool DFS_search(string word, TrieNode* node)
    {
        if (word=="") return false;
        if (node==NULL) return false;
        
        for (char ch='a'; ch<='z'; ch++)
        {
            if (ch==word[0]) continue;
            if (inDict(word.substr(1),node->next[ch-'a']))
                return true;            
        }
        return DFS_search(word.substr(1),node->next[word[0]-'a']);
    }
    
    bool inDict(string word, TrieNode* node)
    {
        if (node==NULL) return false;
        
        for (int i=0; i<word.size(); i++)
        {
            char ch=word[i];
            if (node->next[ch-'a']==NULL)
                return false;
            node=node->next[ch-'a'];
        }
        
        return (node->isEnd);            
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * bool param_2 = obj.search(word);
 */
