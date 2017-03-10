class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        if (s.size()<2) return s.size();
        
        vector<int>Map(128,0);
        int left=0;
        int right=0;
        int Len=0;
        
        while (right<s.size())
        {
            //cout<<left<<right<<endl;
            
            Map[s[right]]++;
            
            if (Map[s[right]]==1)
            {
                Len=max(Len,right-left+1);
            }
            else if (Map[s[right]]>1)
            {
                while (left<right && Map[s[right]]>1)
                {
                    Map[s[left]]--;
                    left++;
                }
            }
            
            right++;
        }
        
        return Len;
        
    }
};
