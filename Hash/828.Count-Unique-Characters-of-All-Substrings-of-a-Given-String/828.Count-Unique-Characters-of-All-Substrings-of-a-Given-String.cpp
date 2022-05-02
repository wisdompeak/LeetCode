class Solution {
public:
    int uniqueLetterString(string s) 
    {
        int n = s.size();
        vector<vector<int>>pos(26); // pos[k]: the pos of letter k so far (by i-th)
        
        int ret = 0;
        for (int i=0; i<n; i++)
        {
            pos[s[i]-'A'].push_back(i);
            for (int k=0; k<26; k++)
            {
                if (pos[k].size()>=2)
                {
                    int m = pos[k].size();
                    ret += pos[k][m-1] - pos[k][m-2];
                }
                else if (pos[k].size()==1)
                {
                    ret += pos[k][0]+1;
                }
            }
        }
        return ret;        
    }
};
