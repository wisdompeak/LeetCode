
class Solution {
public:
    string longestPalindrome(string s) 
    {
        string t="#";
        for (int i=0; i<s.size(); i++)
            t+= s.substr(i,1)+"#";
        
        int N = t.size();
        vector<int>P(N,0);
        int maxCenter = -1;
        int maxRight = -1;
        
        for (int i=0; i<N; i++)
        {
            int k;
            if (i > maxRight)
            {
                k = 0;
                while (i-k>=0 && i+k<N && t[i-k]==t[i+k]) k++;
            }
            else
            {
                k = min(P[maxCenter*2-i],maxRight-i);
                while (i-k>=0 && i+k<N && t[i-k]==t[i+k]) k++;                
            }
            P[i] = k-1;
            if (i + P[i] > maxRight)
            {
                maxRight = i + P[i];
                maxCenter = i;
            }
        }
        
        // for (auto x:P) cout<<x<<" ";
        
        int maxLen = -1;
        int center;
        for (int i=0; i<P.size(); i++)
        {
            if (P[i]>maxLen)
            {
                maxLen = P[i];
                center = i;                
            }
        }
        return s.substr(center/2 - maxLen/2, maxLen);
    }
};
