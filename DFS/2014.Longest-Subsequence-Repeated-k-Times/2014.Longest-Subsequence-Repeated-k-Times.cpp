class Solution {
    int k;
    string s;
    string ret;
public:
    string longestSubsequenceRepeatedK(string s, int k) 
    {
        this->k = k;
        this->s = s;
        vector<int>count(26);
        for (auto ch:s)
            count[ch-'a']++;
        string t;
        for (int i=0; i<26; i++)
        {
            if (count[i]>=k)
                t.push_back('a'+i);
        }

        string temp;
        dfs(t, temp);
        
        return ret;
    }

    void dfs(string&t, string& temp)
    {       
        if (temp!="" && !checkOK(temp))
            return;

        if (temp.size()>ret.size() || (temp.size()==ret.size() && temp>ret))
            ret = temp;

        if (temp.size()==7)
            return;

        for (auto ch: t)
        {
            temp.push_back(ch);
            dfs(t, temp);
            temp.pop_back();
        }
    }

    bool checkOK(string& temp)
    {
        int j = 0;
        int count = 0;
        for (int i=0; i<s.size(); i++)
        {
            if (s[i]!=temp[j]) continue;
            j++;
            if (j==temp.size())
            {
                j = 0;
                count++;
                if (count == k)
                    return true;
            }            
        }
        return false;        
    }
};
