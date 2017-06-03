class Solution {
public:
    bool isSubsequence(string s, string t) 
    {
        unordered_map<char,vector<int>>Map;
        for (int i=0; i<t.size(); i++)
            Map[t[i]].push_back(i);
            
        int NextStart = -1;
        for (int i=0; i<s.size(); i++)
        {
            char ch = s[i];
            int flag=0;
            
            for (int j:Map[ch])
            {
                if (j>NextStart)
                {
                    flag = 1;
                    NextStart = j;
                    break;
                }
            }
            if (flag==0) return false;
        }
        
        return true;
        
    }
};
