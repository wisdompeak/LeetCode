class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) 
    {
        int n = s.size();
        vector<int>diff(n+1);
        for (auto& shift: shifts)
        {
            int start = shift[0], end = shift[1], dir = shift[2];
            int d = (dir==0)? -1:1;
            diff[start]+=d;
            diff[end+1]-=d;
        }
        
        int cur = 0;
        string ret;
        for (int i=0; i<n; i++)
        {
            cur = (cur + diff[i]%26+26)%26;
            ret.push_back('a'+ (s[i]-'a'+ cur)%26);
        }
        return ret;
    }
};
