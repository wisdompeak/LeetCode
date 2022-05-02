class Solution {
public:
    long long appealSum(string s) 
    {
        int n = s.size();
        vector<int>last(26, -1);        
            
        long long ret = 0;
        for (int i=0; i<n; i++)
        {
            ret += (i-last[s[i]-'a']) * (n-i);
            last[s[i]-'a']=i;
        }
            
        return ret;        
    }
};
