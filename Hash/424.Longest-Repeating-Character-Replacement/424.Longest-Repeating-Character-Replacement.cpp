class Solution {
public:
    int characterReplacement(string s, int k) 
    {
        vector<int>Count(26,0);        
        int i = 0;        
        int result = 0;
        
        for (int j=0; j<s.size(); j++)
        {
            Count[s[j]-'A']++;
            int majorityNum = *max_element(Count.begin(),Count.end());
            
            if (j-i+1-majorityNum <=k)
                result = max(result, j-i+1);
            else
            {
                Count[s[i]-'A']--;
                i++;
            }
            
        }
        return result;
    }
};
