class Solution {
    class TrieNode
    {
        public:
        TrieNode* next[26];
    };
public:
    int countDistinct(string s) 
    {
        TrieNode* root = new TrieNode();
        int count = 0;
        for (int i=0; i<s.size(); i++)
        {
            TrieNode* node = root;
            for (int j=i; j<s.size(); j++)
            {
                if (node->next[s[j]-'a']==NULL)
                {
                    node->next[s[j]-'a'] = new TrieNode();
                    count ++;
                }
                node = node->next[s[j]-'a'];
            }            
        }
        return count;        
    }
};
