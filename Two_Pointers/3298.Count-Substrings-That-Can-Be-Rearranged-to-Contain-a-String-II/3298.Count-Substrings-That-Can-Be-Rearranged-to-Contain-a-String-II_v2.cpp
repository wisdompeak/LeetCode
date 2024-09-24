using LL = long long;
class Solution {
public:
    long long validSubstringCount(string word1, string word2) 
    {        
        vector<int>target(26);
        for (auto ch: word2)
            target[ch-'a']++;
        int T = 0;
        for (int i=0; i<26; i++)
            if (target[i]!=0) T++;
        
        vector<int>count(26);        
        int j = 0;
        LL ret = 0;

        int t = 0;        
        int n = word1.size();
        for (int i=0; i<n; i++)
        {
            while (j<n && t!=T)
            {
                count[word1[j]-'a']++;
                if (count[word1[j]-'a']==target[word1[j]-'a'])
                    t++;
                j++;
            }
            if (t==T)            
                ret += n-j+1;            
            count[word1[i]-'a']--;
            if (count[word1[i]-'a'] == target[word1[i]-'a']-1)
                t--;
        }        
        return ret;
    }    
};
