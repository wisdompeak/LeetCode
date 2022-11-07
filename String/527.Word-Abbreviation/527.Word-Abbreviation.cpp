class Solution {
public:
    vector<string> wordsAbbreviation(vector<string>& dict) 
    {         
        int n = dict.size();
        vector<string>rets(n);
        unordered_set<int>Set;
        for (int i=0; i<n; i++)
            Set.insert(i);
        
        int abbrNum = 1;
        while (1)
        {
            unordered_map<string,vector<int>>Map;
            for (auto idx : Set)
            {
                string abbr=getAbbr(dict[idx], abbrNum);
                Map[abbr].push_back(idx);
            }
            Set.clear();
            
            for (auto& [str, indices]:Map)
            {
                if (indices.size()>1)
                {
                    for (int idx: indices)
                        Set.insert(idx);
                }
                else
                {
                    rets[indices[0]] = str;
                }
            }
            
            if (Set.size()==0) break;
            abbrNum++;
        }
        
        return rets;
        
    }
    
    string getAbbr(string s, int abbrNum)
    {
        string t;
        if (s.size()<=2) 
        {
            t=s;
            return t;
        }
        
        t=s.substr(0, abbrNum);
        t+=to_string(s.size()-abbrNum-1);
        t+=s.back();
        if (t.size()==s.size()) t=s;
        return t;
    }
};
