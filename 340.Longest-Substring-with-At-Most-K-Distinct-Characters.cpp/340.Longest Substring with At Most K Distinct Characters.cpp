class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) 
    {
        if (k==0) return 0;
        
        int i=0;
        int j=0;
        vector<int>Map(256,0);
        int count=0;
        int result = 0;
        
        while (j<s.size())
        {
            //cout<<i<<j<<endl;
            
            if (Map[s[j]]>0)
            {
                Map[s[j]]++;
                if (count<=k)
                    result = max(result,j-i+1);
                j++;
            }
            else if (Map[s[j]]==0 && count<k)
            {
                Map[s[j]]++;
                count++;
                result = max(result,j-i+1);
                j++;
            }
            else if (Map[s[j]]==0 && count==k)
            {
                Map[s[i]]--;
                if (Map[s[i]]==0) count--;
                i++;
            }

        }
        
        return result;
        
    }
};
