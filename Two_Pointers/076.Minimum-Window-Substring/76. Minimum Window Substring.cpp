class Solution {
public:
    string minWindow(string s, string t) 
    {
        vector<int>Map(128,0);
        vector<int>Times(128,0);
        int TotalNums=0;
        int count=0;
        
        for (int i=0; i<t.size(); i++)
        {
            Map[t[i]]++;
            if (Map[t[i]]==1)
                TotalNums++;
        }
        
        int left=0;
        int right=0;
        int Len=INT_MAX;
        string result;
        
        while (right<s.size())
        {
            if (Map[s[right]]>0)
            {
                Times[s[right]]++;
                if (Times[s[right]]==Map[s[right]])
                    count++;
            }
            else
                Times[s[right]]++;
            
            if (count==TotalNums)
            {
                while (left<=right && count==TotalNums)
                {
                    
                    if (right-left+1<Len)
                    {
                        Len=right-left+1;
                        result=s.substr(left,right-left+1);
                    }                    
                    
                    Times[s[left]]--;
                    if (Times[s[left]]<Map[s[left]])
                        count--;
                    left++;
                }
            }
            
            right++;
        }
        
        return result;
        
    }
};
