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
            
            while (j-i+1-*max_element(Count.begin(),Count.end()) >k)
            {
                Count[s[i]-'A']--;
                i++;                       
            }
            result = max(result, j-i+1);                                    
        }
        return result;
    }
};
