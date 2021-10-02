class Solution {    
public:
    int characterReplacement(string s, int k) 
    {        
        int ret = 0;
        int j = 0;
        vector<int>count(26);
        for (int i=0; i<s.size(); i++)
        {
            while (j-i - *max_element(count.begin(), count.end()) <= k)
            {
                ret = max(ret, j-i);
                if (j<s.size())
                {
                    count[s[j]-'A']++;
                    j++;
                }
                else
                    break;
            }                            
            count[s[i]-'A']--;
        }
        return ret;
    }
};
