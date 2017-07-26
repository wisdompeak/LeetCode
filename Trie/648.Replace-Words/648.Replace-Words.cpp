class Solution {
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
    
    void addWord(TrieNode* root, string word)
    {
        TrieNode* node=root;
        for (int i=0; i<word.size(); i++)
        {
            char ch=word[i];
            if (node->next[ch-'a']==NULL)
                node->next[ch-'a']=new TrieNode();
            node=node->next[ch-'a'];
        }
        node->isEnd=true;
    }
    
    string replace(TrieNode* root, string word)
    {
        string result;
        string str;
        DFS(root,word,0,str,result);
        if (result!="")
            return result;
        else
            return word;
    }
    
    void DFS(TrieNode* root, string word, int k, string str, string &result)
    {
        if (root->isEnd==1)
        {
            if (result=="")
                result=str;
            else if (result.size()>str.size())
                result=str;
            return;
        }
        
        if (k==word.size())
            return;
                
        for (int i=0; i<26; i++)
        {
            if (root->next[word[k]-'a']!=NULL)
            {
                DFS(root->next[word[k]-'a'],word,k+1,str+word[k],result);
            }
        }
        return;
    }
    
public:
    string replaceWords(vector<string>& dict, string sentence) 
    {
        TrieNode* root=new TrieNode();
        for (int i=0; i<dict.size(); i++)
            addWord(root,dict[i]);
        
        int i=0;
        while (i<sentence.size() && sentence[i]==' ') i++;
        
        string result;
        while (i<sentence.size())
        {
            int i0=i;
            while (i<sentence.size() && sentence[i]!=' ') i++;
            string str=sentence.substr(i0,i-i0);
            string str2 = replace(root,str);
            
            result+=str2;
            result+=' ';
            i++;
        }
        result.pop_back();
        
        return result;
    }
};
