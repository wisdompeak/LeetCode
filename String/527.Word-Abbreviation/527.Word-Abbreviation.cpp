class Solution {
public:
    vector<string> wordsAbbreviation(vector<string>& words) 
    {
        int n = words.size();
        vector<string>rets(n);
        
        vector<int>Set;
        for (int i=0; i<n; i++)
            Set.push_back(i);
        
        int abbrNum = 1;
        while (1)
        {
            unordered_map<string, vector<int>> Map;
            
            for (int idx: Set)
            {
                string abbr = getAbbr(words[idx], abbrNum);
                Map[abbr].push_back(idx);
            }
            Set.clear();
            
            for (auto& [abbr, indices]: Map)
            {
                if (indices.size() > 1)
                {
                    for (int idx: indices)
                        Set.push_back(idx);
                }                    
                else
                    rets[indices[0]] = abbr;
            }
            
            abbrNum += 1;
            if (Set.size() == 0)
                break;            
        }
        
        return rets;
    }
    
    string getAbbr(string s, int abbrNum)
    {                
        if (s.size() < 3) return s;            
     
        string t;
        t = s.substr(0, abbrNum);
        t += to_string(s.size() - abbrNum - 1);
        t += s.back();
        
        if (t.size() == s.size()) return s;
        
        return t;        
    }
};
