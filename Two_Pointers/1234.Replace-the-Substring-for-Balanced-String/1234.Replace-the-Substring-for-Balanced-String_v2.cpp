class Solution {
public:
    int balancedString(string s) 
    {
        unordered_map<char,int>sum;
        for (auto ch:s)
            sum[ch]++;
        
        int th = s.size()/4;
        int j = 0; //left pointer
        int ret = s.size();
        
        for (int i=0; i<s.size(); i++)  // right pointer
        {
            sum[s[i]]--;
            while (checkOK(sum, th))
            {
                ret = min(ret, i-j+1);
                if (ret==0) return 0;
                
                sum[s[j]]++;
                j++;
            }
        }
        return ret;
    }
    
    bool checkOK(unordered_map<char,int>& sum, int th)
    {
        for (auto t: sum)
            if (t.second>th) return false;
        return true;
    }
};
