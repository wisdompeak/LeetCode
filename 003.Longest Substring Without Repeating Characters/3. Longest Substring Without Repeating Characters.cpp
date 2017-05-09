class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        vector<int>Map(256,0);
        int i=0;
        int j=0;
        int result=0;
        
        while (j<s.size())
        {
            if (Map[s[j]]==0)
            {
                Map[s[j]]=1;
                j++;
            }
            else if (Map[s[j]]==1)
            {
                Map[s[i]]=0;
                i++;
            }
            
            result = max(result,j-i);
        }
        
        return result;
        
    }
};
