class WordFilter {
    class TrieNode
    {
        public:
            TrieNode* next[27];
            bool isEnd;
            int weight;
        TrieNode()
        {
            for (int i=0; i<27; i++)
                next[i]=NULL;
            weight=-1;
        }
    };    
    TrieNode* root;
public:
    WordFilter(vector<string> words) 
    {
        root = new TrieNode();        
        for (int i=0; i<words.size(); i++)
        {
            for (int j=0; j<words[i].size(); j++)
            {
                string suf=words[i].substr(j);                                    
                reverse(suf.begin(),suf.end());
                insert(root,suf+"{"+words[i],i);
            }
            insert(root,"{"+words[i],i);
        }
    }
    
    int f(string prefix, string suffix) 
    {
        reverse(suffix.begin(),suffix.end());
        string s = suffix+"{"+prefix;
        
        TrieNode* node = root;
        for (int i=0; i<s.size(); i++)
        {
            char ch=s[i];
            if (node->next[ch-'a']==NULL)
                return -1;
            node=node->next[ch-'a'];
        }        
        return node->weight;
    }
    
    void insert(TrieNode* root, string word, int weight) 
    {
        TrieNode* node=root;
        for (int i=0; i<word.size(); i++)
        {
            char ch=word[i];
            if (node->next[ch-'a']==NULL)
                node->next[ch-'a']=new TrieNode();
            node=node->next[ch-'a'];
            if (node->weight<weight)
                node->weight=weight;
        }
    }    
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter obj = new WordFilter(words);
 * int param_1 = obj.f(prefix,suffix);
 */
