using LL = long long;
class Solution {
    class TrieNode
    {
        public:
            TrieNode* next[26];            
            int count;
        TrieNode()
        {
            for (int i=0; i<26; i++)
                next[i]=NULL;            
            count = 0;
        }
    };
    TrieNode* root = new TrieNode();
public:
    vector<int> longestPrefix(string s) 
    {
        int n = s.size();
        vector<int>dp(n);
        dp[0] = 0;

        for (int i=1; i<n; i++)
        {
            int j = dp[i-1];                       
            while (j>=1 && s[j]!=s[i])
            {
                j = dp[j-1];
            }          
            dp[i] = j + (s[j]==s[i]);
        }

        return dp;        
    }
    
    void add(TrieNode* root, string& word, unordered_set<int>&Set)
    {
        TrieNode* node = root;
        int n = word.size();
        for (int i=0; i<n; i++)
        {                     
            if (node->next[word[i]-'a']==NULL)
                node->next[word[i]-'a'] = new TrieNode();
            node = node->next[word[i]-'a'];
            if (Set.find(i+1)!=Set.end())
                node->count++;
        }
    }
    
    int find(TrieNode* root, string& word)
    {
        TrieNode* node = root;        
        int n = word.size();
        for (int i=0; i<n; i++)
        {                        
            if (node->next[word[i]-'a']==NULL)
                return 0;
            node = node->next[word[i]-'a'];
        }
        return node->count;        
    }
    
    
    long long countPrefixSuffixPairs(vector<string>& words) 
    {
        LL ret = 0;
        for (int i=words.size()-1; i>=0; i--)
        {            
            ret += find(root, words[i]);
            
            int n = words[i].size();
            vector<int>lcp = longestPrefix (words[i]);
            unordered_set<int>Set;
            int len = lcp[n-1];
            while (len!=0)        
            {
                Set.insert(len);
                len = lcp[len-1];
            }
            Set.insert(n);
            
            add(root, words[i], Set);
        }
        return ret;
    }
};
