class Solution {
public:
    string shortestPalindrome(string s) 
    {
        string t = "#";
        for (int i=0; i<s.size(); i++)
        {            
            t.push_back(s[i]);
            t.push_back('#');
        }

        int n = t.size();
        vector<int>P(n);
        int maxCenter = -1, maxRight = -1;
        int L = 1;
        for (int i=0; i<n; i++)
        {
            int r;
            if ( i < maxRight)
            {
                int j = maxCenter*2 - i;
                r = min(P[j], maxRight - i);
            }
            else
                r = 0;

            while (i-r>=0 && i+r<n && t[i-r]==t[i+r])
                r++;

            P[i] = r-1;
            if (i+P[i]>maxRight)
            {
                maxRight = i+P[i];
                maxCenter = i;
            }

            if (i-P[i]==0)
                L = P[i];
        }
        
        string temp = s.substr(L);
        reverse(temp.begin(), temp.end());
        return temp+s;
        
    }
};
