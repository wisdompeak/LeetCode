class Solution {
public:
    int largestVariance(string s) 
    {
        int n = s.size();
        unordered_map<char, vector<int>>Map;
        for (int i=0; i<n; i++)
            Map[s[i]].push_back(i);

        int ret = 0;

        for (auto& [a, pos0]: Map)
            for (auto& [b, pos1]: Map)
            {
                if (a==b) continue;                
                int curSum0 = 0,  curSum1 = INT_MIN/2;

                int i = 0, j = 0;

                while (i<pos0.size() || j<pos1.size())
                {
                    if (j==pos1.size() || (i<pos0.size() && pos0[i] < pos1[j]))
                    {
                        curSum0 = curSum0 + 1;
                        curSum1 = curSum1 + 1;
                        i++;
                    }
                    else if (i==pos0.size() || (j<pos1.size() && pos1[j] < pos0[i]))
                    {
                        curSum1 = max(curSum0-1, curSum1-1);
                        curSum0 = 0;                        
                        j++;
                    }

                    ret = max(ret, curSum1);
                }
            }

        return ret;
    }
};
