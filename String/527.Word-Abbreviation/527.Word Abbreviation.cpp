class Solution {
public:
    vector<string> wordsAbbreviation(vector<string>& dict) 
    {
        unordered_map<string,int>Index;
        for (int i=0; i<dict.size(); i++)
            Index[dict[i]]=i;
        
        unordered_map<string,vector<string>>Map;
        vector<string>results(dict.size());
        int abbrNum=0;

        for (int i=0; i<dict.size(); i++)
        {
            string abbr=getAbbr(dict[i],abbrNum);
            Map[abbr].push_back(dict[i]);
        }
        
        while (1)
        {
            unordered_set<string>Set;
            for (auto a:Map)
            {
                if (a.second.size()>1)
                {
                    for (int i=0; i<a.second.size(); i++)
                        Set.insert(a.second[i]);
                }
                else
                {
                    results[Index[a.second[0]]]=a.first;
                }
            }
            
            if (Set.size()==0) break;
            
            Map.clear();
            abbrNum++;
            for (auto s:Set)
            {
                string abbr=getAbbr(s,abbrNum);
                Map[abbr].push_back(s);
            }
        }
        
        return results;
        
    }
    
    string getAbbr(string s, int abbrNum)
    {
        string t;
        if (s.size()<=2) 
        {
            t=s;
            return t;
        }
        
        t=s.substr(0,abbrNum+1);
        t+=to_string(s.size()-abbrNum-2);
        t+=s.back();
        if (t.size()==s.size()) t=s;
        return t;
    }
};
