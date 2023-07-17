using LL = long long;
class Solution {
    unordered_set<LL>Set;
    unordered_map<int, vector<int>>Map;
public:
    int longestValidSubstring(string word, vector<string>& forbidden) 
    {
        for (auto& s: forbidden)
        {
            LL code = 0;
            for (auto ch: s)            
                code = (code << 5) + (ch-'a'+1);            
            Set.insert(code);
        }
        
        for (int len = 1; len<=10; len++)
            helper(word, len);
        
        int n  = word.size();        
        int rightBound = n;
        int ret = 0;
        for (int i=n-1; i>=0; i--)
        {
            if (Map.find(i)!=Map.end())
            {
                for (int j: Map[i])
                    rightBound = min(rightBound, j);                
            }                
            ret = max(ret, rightBound-i);
        }
        return ret;
        
    }
    
    void helper(string&word, int len)
    {
        int n = word.size();
        LL code = 0;
        for (int i=0; i<n; i++)
        {
            if (i>=len) 
                code &= (1LL<<(5*(len-1)))-1;
                
            code = (code << 5) + word[i]-'a'+1;
                        
            if (i>=len-1 && Set.find(code)!=Set.end())
                Map[i-len+1].push_back(i);
        }
    }
};
