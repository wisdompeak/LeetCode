class Solution {
public:
    string minWindow(string s, string t) 
    {
        string result;
        int len = INT_MAX;
        
        unordered_map<char,int>Table;        
        for (auto ch: t)        
            Table[ch]++;        
        int COUNT = Table.size();
        
        unordered_map<char,int>Map;
        int i = 0;
        int count = 0;
        
        for (int j=0; j<s.size(); j++)
        {        
            Map[s[j]]++;
            if (Map[s[j]]==Table[s[j]])
                count++;
            
            while (count==COUNT)
            {
                if (j-i+1<len)
                {
                    len = j-i+1;
                    result = s.substr(i,j-i+1);
                }
                
                Map[s[i]]--;
                if (Map[s[i]]<Table[s[i]])
                    count--;
                i++;                
            }
        }
            
        return result;
    }
};
