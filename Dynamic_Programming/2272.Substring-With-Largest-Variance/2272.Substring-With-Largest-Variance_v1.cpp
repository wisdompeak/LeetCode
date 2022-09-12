class Solution {
public:
    int largestVariance(string s) 
    {
        int n = s.size();
        unordered_set<char>Set(s.begin(), s.end());

        int ret = 0;

        for (auto a: Set)
            for (auto b: Set)
            {
                if (a==b) continue;                
                int curSum0 = 0,  curSum1 = INT_MIN/2;

                for (int i=0; i<n; i++)
                {
                    if (s[i] == a)
                    {
                        curSum0 = curSum0 + 1;
                        curSum1 = curSum1 + 1;
                    }
                    else if (s[i] == b)
                    {
                        curSum1 = max(curSum0-1, curSum1-1);
                        curSum0 = 0;                        
                    }

                    ret = max(ret, curSum1);
                }
            }

        return ret;
    }
};
