class Solution {
public:
    int largestVariance(string s) 
    {
        int n = s.size();
        map<char, vector<int>>pos;
        for (int i=0; i<n; i++)
            pos[s[i]].push_back(i);

        int ret = 0;

        for (auto& [a, pos0]: pos)
            for (auto& [b, pos1]: pos)
            {
                if (a==b) continue;
                cout<<a<<" "<<b<<endl;
                int i = 0, j = 0;
                int dp0 = 0,  dp1 = INT_MIN/2;

                while (i<pos0.size() || j<pos1.size())
                {
                    if (i==pos0.size() || (j<pos1.size() && pos1[j] < pos0[i]))
                    {
                        dp1 = max(dp0-1, dp1-1);
                        dp0 = 0;                        
                        j++;
                    }                        
                    else if (j==pos1.size() || (i<pos0.size() && pos0[i] < pos1[j]))
                    {                        
                        dp1 +=1;
                        dp0 +=1;
                        i++;
                    }
                    ret = max(ret, dp1);
                }

            }

        return ret;
    }
};
