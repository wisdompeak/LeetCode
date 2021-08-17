class Solution {
public:
    int countSubstrings(string s) 
    {
        string t = "#";
        for (auto ch: s)
        {
            t.push_back(ch);
            t.push_back('#');
        }
        
        int n = t.size();
        vector<int>P(n);
        int maxCenter = -1;
        int maxRight = -1;
        for (int i=0; i<n; i++)
        {
            int r;
            if (i <= maxRight)
            {
                int j = maxCenter*2-i;
                r = min(P[j], maxRight-i);
                while (i-r>=0 && i+r<n && t[i-r]==t[i+r])
                    r++;                
            }
            else
            {
                r = 0;
                while (i-r>=0 && i+r<n && t[i-r]==t[i+r])
                    r++;  
            }
            P[i] = r-1;
            if (i+P[i]>maxRight)
            {
                maxRight = i+P[i];
                maxCenter = i;
            }
        }
        
        int ret = 0;
        for (int i=0; i<n; i++)
        {
            ret += (P[i]+1)/2;
        }
        return ret;
    }
};
