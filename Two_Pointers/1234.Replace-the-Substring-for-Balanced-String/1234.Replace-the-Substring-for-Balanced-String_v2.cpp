class Solution {
public:
    int balancedString(string s) 
    {
        unordered_map<char,int>sum;
        for (auto ch:s)
            sum[ch]++;
        int x = s.size()/4;
        int ret = s.size();
        int j = 0;

        for (int i=0; i<s.size(); i++)
        {
            sum[s[i]]--;
            while (check(sum,x))
            {
                ret = min(ret, i-j+1);   
                if (j<=i)             
                {
                    sum[s[j]]++;
                    j++;
                }
                else
                    break;
            }
        }

        return ret;
    }

    bool check(unordered_map<char,int>&sum, int x)
    {
        for (auto t: sum)
            if (t.second>x) return false;
        return true;
    }
};
