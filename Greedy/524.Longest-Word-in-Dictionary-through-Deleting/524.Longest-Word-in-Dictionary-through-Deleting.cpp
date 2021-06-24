class Solution {
public:
    string findLongestWord(string S, vector<string>& dictionary) 
    {
        int m = S.size();
        S = "#"+S;
        int next[m+1][26];
        
        for (int k=0; k<26; k++)
            next[m][k] = -1;
        for (int i=m; i>=1; i--)
        {
            for (int k=0; k<26; k++)
                next[i-1][k] = next[i][k];
            next[i-1][S[i]-'a'] = i;
        }
        
        string ret = "";
        for (auto word: dictionary)
        {
            int flag = 1;
            int i = 0;
            for (auto ch: word)
            {
                i = next[i][ch-'a'];
                if (i==-1)
                {
                    flag = 0;
                    break;
                }                
            }
            if (flag)
            {
                if (word.size() > ret.size() || (word.size() == ret.size() && word < ret))
                    ret = word;
            }
        }
        return ret;        
    }
};
