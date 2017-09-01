class Solution {
public:
    string minWindow(string s, string t) 
    {
        vector<int>table(256,0);
        for (int i=0; i<t.size(); i++)
            table[t[i]]++;
        int COUNT=t.size();
        
        vector<int>Map(256,0);
        
        int i=0;
        int count=0;
        int len=INT_MAX;
        string result;
        for (int j=0; j<=s.size(); j++)
        {
            if (count==COUNT)
            {                
                while (table[s[i]]==0 || Map[s[i]]>table[s[i]])                
                {
                    Map[s[i]]--;
                    i++;
                }                
                if (len>j-i)
                {
                    len=j-i;
                    result=s.substr(i,len);
                }                
                Map[s[i]]--;
                count--;
                i++;
            }
            
            if (j==s.size()) break;
            
            if (Map[s[j]]<table[s[j]])
            {
                Map[s[j]]++;
                count++;
            }
            else if (Map[s[j]]>=table[s[j]])
            {
                Map[s[j]]++;
            }            
        }
        
        if (len==INT_MAX) return "";
        else return result;
        
    }
};
