class Solution {
    vector<int>count;
public:
    int characterReplacement(string s, int k) 
    {        
        int ret = 0;
        int j = 0;
        count.resize(26);
        for (int i=0; i<s.size(); i++)
        {
            while (j<s.size() && checkOK(s, j, j-i+1, k))
                j++;
            ret = max(ret, j-i);
            count[s[i]-'A']--;
        }
        return ret;
    }

    bool checkOK(string&s, int j, int total, int k)
    {
        count[s[j]-'A']++;
        int maxCount = *max_element(count.begin(), count.end());
        if (total - maxCount <= k)
            return true;
        else
        {
            count[s[j]-'A']--;
            return false;
        }
    }
};
