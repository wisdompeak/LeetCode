class Solution {
    int n;
    unordered_map<char,int>count;
public:
    int balancedString(string s) 
    {
        n = s.size();        
        for (auto ch:s)
            count[ch] += 1;
        int flag = 1;
        for (auto x: count)
            if (x.second!=n/4)
                flag = 0;
        if (flag==1) return 0;

        int j = 0;
        unordered_map<char,int>sum;
        int ret = INT_MAX;
        for (int i=0; i<n; i++)
        {
            while (j<n && !isOK(sum))
            {
                sum[s[j]]+=1;
                j++;
            }
            if (isOK(sum))
                ret = min(ret, j-i);
            sum[s[i]] -= 1;
        }
        return ret;
    }

    bool isOK(unordered_map<char,int>&sum)
    {        
        for (auto x: count)
        {
            char ch = x.first;
            if (count[ch]-sum[ch] > n/4)
                return false;
        }
        return true;
    }
};
