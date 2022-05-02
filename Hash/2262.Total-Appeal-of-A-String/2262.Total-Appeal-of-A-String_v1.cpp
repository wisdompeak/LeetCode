class Solution {
public:
    long long appealSum(string s) 
    {
        vector<int>pos(26, -1);
        long long result=0;
        for (int i=0; i<s.size(); i++)
        {
            pos[s[i]-'a'] = i;
            for (int i=0; i<26; i++)
            {
                if (pos[i]!=-1)                                    
                    result+=(long long)pos[i]+1;                  
            }
        }
        return result;        
    }
};
