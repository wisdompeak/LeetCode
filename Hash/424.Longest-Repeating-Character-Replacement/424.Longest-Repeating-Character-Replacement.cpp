class Solution {
public:
    int characterReplacement(string s, int k) 
    {
        int i = 0;
        unordered_map<char,int>Map;
        int maxNum = 0;
        int result = 0;
        
        for (int j=0; j<s.size(); j++)
        {
            Map[s[j]]++;
            maxNum = max(maxNum, Map[s[j]]);
            
            if (j-i+1 - maxNum <= k)
                result = max(result,j-i+1);
            else 
            {
                Map[s[i]]--;
                i++;    
            }                
        }
        return result;
    }
};
