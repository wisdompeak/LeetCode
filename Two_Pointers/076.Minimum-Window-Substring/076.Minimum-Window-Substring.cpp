class Solution {
public:
    string minWindow(string s, string t) 
    {
        unordered_map<char,int>Table;
        for (int i=0; i<t.size(); i++)
            Table[t[i]]++;
        int M = Table.size();
        
        unordered_map<char,int>Map;
        int i=0;
        int Len = INT_MAX;
        string result;
        int count = 0;
        for (int j=0; j<s.size(); j++)
        {
            Map[s[j]]++;
            if (Map[s[j]]==Table[s[j]])
                count++;
            while (count==M)
            {
                if (Len>j-i+1)
                {
                    Len = j-i+1;
                    result = s.substr(i,Len);
                }
                Map[s[i]]--;
                if (Map[s[i]]==Table[s[i]]-1)
                    count--;
                i++;
            }
        }
        return result;
    }
};
