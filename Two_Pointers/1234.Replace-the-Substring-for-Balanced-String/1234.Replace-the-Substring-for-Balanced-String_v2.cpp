class Solution {
public:
    int balancedString(string s) 
    {
        unordered_map<int,int>sum;
        for (auto ch:s)
            sum[ch]++;
        
        int x = s.size()/4;
                        
        int ret = s.size();
        int j = -1;
        for (int i=0; i<s.size(); i++)
        {
            while (!checkOK(sum,x) && j+1<s.size())
            {
                j++;            
                sum[s[j]]--;                
            }
            
            if (checkOK(sum,x))
                ret = min(ret, j-i+1);
            sum[s[i]]++;
        }
        
        return ret;
    }
    
    bool checkOK(unordered_map<int,int>sum, int x)
    {
        for (auto t: sum)
            if (t.second>x) return false;
        return true;
    }
    
};
