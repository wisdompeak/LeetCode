class TrieNode
{
    public:
    TrieNode* next[26];
    int idx;
    TrieNode()
    {
        for (int i=0; i<26; i++)
            next[i] = NULL;
        idx = -1;
    }        
};

class Solution {
    TrieNode* root = new TrieNode();
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) 
    {
        vector<pair<string,int>>arr;
        for (int i=0; i<wordsContainer.size(); i++)
        {
            arr.push_back({wordsContainer[i], i});
        }
        
        sort(arr.begin(), arr.end(), [](const pair<string,int>&a, const pair<string,int>&b)
            {
                if (a.first.size() != b.first.size()) 
                    return a.first.size() < b.first.size();
                else 
                    return a.second < b.second;
            });        
        
        for (int i=arr.size()-1; i>=0; i--)
        {
            TrieNode* node = root;
            string s = arr[i].first;
            for (int j=s.size()-1; j>=0; j--)
            {
                if (node->next[s[j]-'a']==NULL)
                    node->next[s[j]-'a'] = new TrieNode();
                node = node->next[s[j]-'a'];
                node->idx = arr[i].second;
            }            
        }
        
        root->idx = arr[0].second;
        vector<int>rets;
        for (auto& query: wordsQuery)
        {
            TrieNode* node = root;
            int ans = -1;
            for (int i=query.size()-1; i>=0; i--)
            {
                if (node->next[query[i]-'a']!=NULL)
                    node = node->next[query[i]-'a'];
                else
                {
                    ans = node->idx;
                    break;
                }
            }
            if (ans==-1)
                ans = node->idx;
            
            rets.push_back(ans);
            
        }
        
        return rets;
    }
};
