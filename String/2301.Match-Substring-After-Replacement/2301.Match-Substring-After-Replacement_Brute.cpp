class Solution {
    bool table[256][256];
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) 
    {
        int m = s.size();
        
        for (auto x: mappings)
        {
            table[x[0]][x[1]] = 1;
        }
        
        for (int i=0; i<s.size(); i++)
        {
            int flag = true;
            for (int j=0; j<sub.size(); j++)
            {
                if (i+j<m && (sub[j]==s[i+j] || table[sub[j]][s[i+j]]))
                    continue;

                flag = false;
                break;
            }
            if (flag) return true;
        }

        return false;
        
    }
};
