class TrieNode
{
    public:
    TrieNode* next[128];
    set<pair<int,string>>top;
    TrieNode()
    {
        for (int i=0; i<128; i++)
            next[i] = NULL;        
    }    
};

class AutocompleteSystem {    
    TrieNode* root;
    string inputStr;
    TrieNode* cur;
    int flag = 1;
public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) 
    {
        root = new TrieNode();     
        cur = root;
        for (int i=0; i<sentences.size(); i++)
            add(root, sentences[i], 0, -times[i]);        
    }
    
    void add(TrieNode* node, const string sentence, int i, int freq)
    {        
        if (i==sentence.size()) return;
        
        int k = sentence[i];
        if (node->next[k] == NULL)
            node->next[k] = new TrieNode();
        node = node->next[k];
        
        int f = 0;
        for (auto iter = node->top.begin(); iter!=node->top.end(); iter=next(iter))
        {
            if (iter->second == sentence)
                f = iter->first;
        }
        if (f!=0) node->top.erase({f, sentence});        
        node->top.insert(make_pair(f+freq, sentence));    
        
        add(node, sentence, i+1, freq);
    }
    
    vector<string> input(char c) 
    {
        inputStr.push_back(c);
        
        if (c=='#')
        {
            inputStr.pop_back();
            add(root, inputStr, 0, -1);
            inputStr = "";
            cur = root;
            flag = 1;
            return {};
        }
        else if (flag==0)
        {
            return {};
        }
        else if (cur->next[c]==NULL)
        {
            flag = 0;
            return {};
        }
        
        cur = cur->next[c];
        vector<string>rets;
        for (auto iter = cur->top.begin(); iter!=cur->top.end(); iter=next(iter))
        {
            rets.push_back(iter->second);
            if (rets.size()==3) break;
        }
        return rets;
        
    }
    
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */
