class Solution {
    class TrieNode
    {
        public:
        TrieNode* next[26];
        int count;
        TrieNode()
        {
            for (int i=0; i<26; i++)
                next[i] = NULL;
            count = 0;
        }
    };
public:
    TrieNode* root;
    
    void insert(string word) 
    {
        TrieNode* node=root;
        for (int i=0; i<word.size(); i++)
        {
            char ch=word[i];
            if (node->next[ch-'a']==NULL)
                node->next[ch-'a']=new TrieNode();
            int prevCount = node->count;
            node=node->next[ch-'a'];
            node->count += 1;            
        }        
    }
    
    vector<int> sumPrefixScores(vector<string>& words) 
    {
        root = new TrieNode();
        
        for (string& word: words)
            insert(word);
        
        int n = words.size();
        vector<int>rets(n);
        
        for (int i=0; i<n; i++)
        {
            TrieNode* node=root;
            int sum = 0;
            for (char ch: words[i])
            {
                if (node->next[ch-'a']==NULL)
                    break;
                node = node->next[ch-'a'];
                sum += node->count;
            }
            rets[i] = sum;
        }
        
        return rets;
    }
};
