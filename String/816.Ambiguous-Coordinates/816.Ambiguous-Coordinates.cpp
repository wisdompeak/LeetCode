class Solution {
public:
    vector<string> ambiguousCoordinates(string s) 
    {
        s = s.substr(1, s.size()-2);
        vector<string>rets;
        for (int i=1; i<s.size(); i++)
        {
            vector<string> a = check(s.substr(0, i));
            vector<string> b = check(s.substr(i));
            if (!a.empty() && !b.empty())
            {
                for (auto x: a)
                    for (auto y:b)
                        rets.push_back("("+x+", "+y+")");                                                 
            }                
        }
        return rets;        
    }
    
    vector<string> check(string s)
    {
        vector<string>rets;
        if (s.size()==1 || s[0]!='0')
            rets.push_back(s);
        
        for (int i=1; i<s.size(); i++)
        {
            string a = s.substr(0, i);
            string b = s.substr(i);
            if (a.size()>1 && a[0]=='0') continue;
            if (b.back()=='0') continue;            
            rets.push_back(a+"."+b);
        }
        
        return rets;
    }
};
