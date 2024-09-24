using LL = long long;
class Solution {
public:
    long long validSubstringCount(string word1, string word2) 
    {        
        vector<int>target(26);
        for (auto ch: word2)
            target[ch-'a']++;
        
        vector<int>count(26);        
        int j = 0;
        LL ret = 0;
        
        int n = word1.size();
        for (int i=0; i<n; i++)
        {
            while (j<n && !checkOK(count, target))
            {
                count[word1[j]-'a']++;
                j++;
            }
            if (checkOK(count,target))            
                ret += n-j+1;            
            count[word1[i]-'a']--;
        }        
        return ret;
    }
    
    bool checkOK(vector<int>&count, vector<int>&target)
    {
        for (int i=0; i<26; i++)
            if (count[i]<target[i])
                return false;
        return true;
    }
};
