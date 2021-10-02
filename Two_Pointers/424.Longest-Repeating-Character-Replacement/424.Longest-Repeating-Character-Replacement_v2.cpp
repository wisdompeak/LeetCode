class Solution {
public:
    int characterReplacement(string s, int k) 
    {
        vector<int>count(26,0);
        
        int i = 0;        
        int result = 0;
        
        for (int j=0; j<s.size(); j++)
        {
            count[s[j]-'A']++;
            
            while (j-i+1 - *max_element(count.begin(),count.end()) > k)
            {
                count[s[i]-'A']--;
                i++;                       
            }
            result = max(result, j-i+1);                                    
        }
        return result;
    }
};
