class MapSum {
    class TrieNode
    {
        public:
        TrieNode* next[26];
        int val;
        TrieNode()
        {
            for (int i=0; i<26; i++)
                next[i]=NULL;
            val=0;
        }
    };
    TrieNode* root;
public:
    /** Initialize your data structure here. */
    MapSum() 
    {
        root=new TrieNode();
    }
    
    void insert(string key, int val) 
    {
        TrieNode* node=root;
        for (int i=0; i<key.size(); i++)
        {
            char ch=key[i];
            if (node->next[ch-'a']==NULL)
                node->next[ch-'a']=new TrieNode();
            node=node->next[ch-'a'];
        }
        node->val=val;
    }
    
    int sum(string prefix) 
    {
        TrieNode* node=root;
        for (int i=0; i<prefix.size(); i++)
        {
            char ch=prefix[i];
            if (node->next[ch-'a']==NULL)            
                return 0;                            
            node=node->next[ch-'a'];
        }
                
        int Sum=0;
        DFS(node,Sum);
        return Sum;
    }
    
    void DFS(TrieNode* node, int& sum)
    {
        if (node==NULL) return;
        
        sum+=node->val;
        for (int i=0; i<26; i++)
            DFS(node->next[i],sum);
    }
};
