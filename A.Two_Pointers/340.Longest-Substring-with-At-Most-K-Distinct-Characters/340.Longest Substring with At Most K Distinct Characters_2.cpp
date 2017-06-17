class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) 
    {
        vector<int>Map(256,0);
        int i=0;
        int count=0;
        int result=0;
        
        for (int j=0; j<s.size(); j++)
        {
            if (Map[s[j]]>0)
                Map[s[j]]++;
            if (Map[s[j]]==0 && count<k)
            {
                Map[s[j]]++;
                count++;
            }
            else if (Map[s[j]]==0 && count==k)
            {
                Map[s[j]]++;
                count++;
                
                while (count>k)
                {
                    Map[s[i]]--;
                    if (Map[s[i]]==0)
                        count--;
                    i++;
                }
            }
            
            if (count<=k)
                result=max(result,j-i+1);
        }
        
        return result;
    }
};
