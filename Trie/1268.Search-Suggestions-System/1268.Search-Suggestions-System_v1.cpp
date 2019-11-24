class Solution {
    class TrieNode
    {
        public:
            TrieNode* next[26];
            int isEnd;
        TrieNode()
        {
            for (int i=0; i<26; i++)
                next[i]=NULL;
            isEnd=0;
        }
    };
    TrieNode* root;    
    
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) 
    {
        root = new TrieNode();
        for (auto word: products)
            insert(word);
        
        cout<<products.size()<<endl;
        
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
            string temp = "";
            DFS(node,ans,temp);
            
            while (ans.size()>3)
                ans.pop_back();
            for (int j=0; j<ans.size(); j++)
                ans[j] = word+ans[j];
            rets.push_back(ans);                
        }
        
        return rets;
    }
    
    void insert(string word) 
    {
        TrieNode* node=root;
        for (int i=0; i<word.size(); i++)
        {
            char ch=word[i];
            if (node->next[ch-'a']==NULL)
                node->next[ch-'a']=new TrieNode();
            node=node->next[ch-'a'];
        }
        node->isEnd+=1;
    }   
    
    void DFS(TrieNode* node, vector<string>&ans, string temp) 
    {        
        if (node->isEnd>0)
        {
            for (int k=0; k<node->isEnd; k++)
                ans.push_back(temp);
        }
            
        
        for (int i=0; i<26; i++)
        {
            if (ans.size()>3) break;
            if (node->next[i]==NULL) continue;
            temp.push_back('a'+i);
            DFS(node->next[i],ans, temp);
            temp.pop_back();
        }        
    }
    
    
};
