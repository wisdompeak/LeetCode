class TrieNode
{
    public:
        TrieNode* next[26];
        bool isEnd;
    TrieNode()
    {
        for (int i=0; i<26; i++)
            next[i]=NULL;
        isEnd=0;
    }
};

class Solution {
    TrieNode* root;        
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) 
    {
        root = new TrieNode();
        for (auto& word: products)
        {
            TrieNode* node = root;
            for (char ch: word)
            {
                if (node->next[ch-'a']==NULL)
                    node->next[ch-'a'] = new TrieNode();
                node = node->next[ch-'a'];
            }
            node->isEnd = true;
        }  
        
        vector<vector<string>>rets;
        TrieNode* node=root;
        string word;
        for (int i=0; i<searchWord.size(); i++)
        {
            char ch = searchWord[i];            
            if (node->next[ch-'a']==NULL)
            {
                for (int j=i; j<searchWord.size(); j++)
                    rets.push_back({});
                break;
            }
            
            node = node->next[ch-'a'];
            word.push_back(ch);
            vector<string>ans;
            string str = "";
            DFS(node,ans,str);
            
            for (int j=0; j<ans.size(); j++)
                ans[j] = word+ans[j];
            rets.push_back(ans);                
        }
        
        return rets;
    }    
    
    void DFS(TrieNode* node, vector<string>&ans, string& str) 
    {       
        if (ans.size()==3) return;

        if (node->isEnd == true)
            ans.push_back(str);
        
        for (int i=0; i<26; i++)
        {
            if (node->next[i]==NULL) continue;
            str.push_back('a'+i);
            DFS(node->next[i],ans, str);
            str.pop_back();
        }        
    }
};
