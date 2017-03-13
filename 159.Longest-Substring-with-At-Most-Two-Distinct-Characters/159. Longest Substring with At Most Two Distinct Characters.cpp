class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) 
    {
        vector<int>Map(128,0);
        int count=0;
        
        int left=0;
        int right=0;
        int result=0;
        
        while (right<s.size())
        {
            
            if (Map[s[right]]==0)
            {
                Map[s[right]]=1;
                count++;
            }
            else
            {
                Map[s[right]]++;
            }
            
            //cout<<left<<" "<<right<<" "<<count<<endl;
            
            if (count<=2)
            {
                result = max(result,right-left+1);
                right++;
            }
            else
            {
                while (left<right && count>2)
                {
                    Map[s[left]]--;
                    if (Map[s[left]]==0)
                        count--;
                    left++;
                }
                
                right++;
            }
        }
        
        return result;
        
    }
};
