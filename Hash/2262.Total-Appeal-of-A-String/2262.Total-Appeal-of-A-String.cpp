class Solution {
public:
    long long appealSum(string s) 
    {
        vector<vector<int>>pos(26);
        long long result=0;
        for (int i=0; i<s.size(); i++)
        {
            pos[s[i]-'a'].push_back(i);
            for (int i=0; i<26; i++)
            {
                if (pos[i].size()>=1)
                {
                    int k = pos[i].size();
                    result+=(long long)pos[i][k-1]+1;
                }                
            }
        }
        return result;
        
    }
};
