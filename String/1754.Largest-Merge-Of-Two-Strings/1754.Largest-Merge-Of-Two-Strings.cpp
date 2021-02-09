class Solution {
public:
    string largestMerge(string word1, string word2) 
    {
        string ret;
        int i=0, j=0;
        while (i<word1.size() && j<word2.size())
        {
            if (word1.substr(i)>word2.substr(j))
            {
                ret.push_back(word1[i]);
                i++;
            }
            else
            {
                ret.push_back(word2[j]);
                j++;
            }
        }
        while (i<word1.size())
        {
            ret.push_back(word1[i]);
            i++;
        }
        while (j<word2.size())
        {
            ret.push_back(word2[j]);
            j++;
        }
        return ret;
    }
};
