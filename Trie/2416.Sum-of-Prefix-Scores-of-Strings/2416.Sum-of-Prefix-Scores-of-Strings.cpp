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
    vector<int> sumPrefixScores(vector<string>& words) {
        TrieNode* root = new TrieNode();
        
        for (auto& word: words)
        {
            TrieNode* node = root;
            for (char ch: word)
            {
                if (node->next[ch-'a']==NULL)
                    node->next[ch-'a'] = new TrieNode();
                node = node->next[ch-'a'];
                node->count += 1;
            }
        }
        
        vector<int>rets;
        for (auto& word: words)
        {
            TrieNode* node = root;
            int score = 0;
            for (char ch: word)
            {
                if (node->next[ch-'a'] == NULL)
                    break;
                node = node->next[ch-'a'];
                score += node->count;
            }
            rets.push_back(score);
        }
        
        return rets;        
    }
};
