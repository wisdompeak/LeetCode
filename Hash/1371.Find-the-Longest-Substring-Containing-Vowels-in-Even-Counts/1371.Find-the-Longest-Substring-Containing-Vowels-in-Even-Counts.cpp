class Solution {
public:
    int findTheLongestSubstring(string s) 
    {
        vector<int>count(5,0);
        unordered_map<int,int>Map;
        Map[0] = -1;
        
        int ret = 0;
        
        for (int i=0; i<s.size(); i++)
        {
            if (s[i]=='a')
                count[0] = (count[0]+1)%2;
            if (s[i]=='e')
                count[1] = (count[1]+1)%2;
            if (s[i]=='i')
                count[2] = (count[2]+1)%2;
            if (s[i]=='o')
                count[3] = (count[3]+1)%2;
            if (s[i]=='u')
                count[4] = (count[4]+1)%2;
            
            int code = 0;
            for (int i=0; i<5; i++)
                code = code*2 + count[i];
            
            if (Map.find(code)!=Map.end())
                ret = max(ret, i-Map[code]);
            else
                Map[code] = i;
        }
        
        return ret;
    }
};
