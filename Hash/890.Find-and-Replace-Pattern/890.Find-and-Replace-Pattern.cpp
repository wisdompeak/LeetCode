class Solution {
public:
    string encode(string s)
    {
        int num = 0;
        unordered_map<char, int>Map;
        string ret;
        for (auto ch: s)
        {
            if (Map.find(ch)!=Map.end())
                ret+=to_string(Map[ch]);
            else
            {
                Map[ch] = num;
                ret+=to_string(num);
                num++;
            }            
        }
        return ret;
    }    
    
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) 
    {
        string p = encode(pattern);
        vector<string>rets;
        
        for (auto word: words)
        {
            string t = encode(word);
            if(t==p)
                rets.push_back(word);                
        }
        return rets;
    }
};
