class Solution {
public:
    string longestNiceSubstring(string s) 
    {
        int retLen = -1, retStart = -1;
        for (int k=26; k>=1; k--)
        {
            auto [len, start] = helper(s, k);
            if (len > retLen)
            {
                retLen = len;
                retStart = start;
            } else if (len==retLen && start < retStart)
            {
                retStart = start;
            }                                
        }
        if (retLen!=-1)
            return s.substr(retStart, retLen);
        else
            return "";        
    }
    
    pair<int,int> helper(string&s, int k)
    {
        int j=0;
        unordered_map<char,int>Map1;
        unordered_map<char,int>Map2;
        int len = -1, start = -1;
                
        for (int i=0; i<s.size(); i++)
        {
            while (j<s.size() && (Map1.size()<k || Map1.size()==k && Map1.find(tolower(s[j]))!=Map1.end()))
            {
                Map1[tolower(s[j])]++;                
                Map2[s[j]]++; 
                j++;
            }
            if (Map1.size() < k) break;                
            
            int flag = 1;
            for (auto x: Map1)
            {
                if (Map2[tolower(x.first)]==0 || Map2[toupper(x.first)]==0)
                {
                    flag = 0;
                    break;
                }
            }
            if (flag==1)
            {
                if (j-i > len)
                {
                    len = j-i;
                    start = i;
                }                
            }       
            
            Map1[tolower(s[i])]--;
            if (Map1[tolower(s[i])]==0)
                Map1.erase(tolower(s[i]));
            Map2[s[i]]--;
                        
        }
        
        return {len, start};
    }
};
