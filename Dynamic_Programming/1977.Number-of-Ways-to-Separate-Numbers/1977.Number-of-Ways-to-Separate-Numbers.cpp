using PII = pair<long, long>;
class Solution {
    long M = 1e9+7;
public:
    bool larger(string& s, int a, int b, int len)
    {        
        for (int i=0; i<len; i++)
            if (s[a+i]!=s[b+i])
                return s[a+i]>s[b+i];
        return false;
    }
    
    int numberOfCombinations(string num) 
    {
        int n = num.size(); 
        if (num[0]=='0') return 0;
        
        vector<vector<int>>accum(n+2, vector<int>(n+2));
        vector<vector<int>>lcs(n+2, vector<int>(n+2));
        
        for (int i=n-1; i>=0; i--)
            for (int j=n-1; j>=0; j--)
            {
                if (num[i]==num[j])
                    lcs[i][j] = lcs[i+1][j+1]+1;
                else
                    lcs[i][j] = 0;
            }
                
        for (int i=0; i<n; i++)    
            for (int len=1; len<=i+1; len++)                        
            {                                
                int j = i-len+1;
                int dp = 0;
                
                if (num[j]=='0')                 
                    dp = 0;
                else if (len==i+1)
                    dp = 1;
                else
                {
                    int maxLen2 = min(len, j);
                    
                    if (len==maxLen2 && lcs[j-maxLen2][j]<len && num[j-maxLen2+lcs[j-maxLen2][j]]>num[j+lcs[j-maxLen2][j]])
                        maxLen2--;
                    while (maxLen2>=1 && num[j-maxLen2]=='0')
                        maxLen2--;
                    
                    if (maxLen2>=1)
                        dp = accum[j-1][maxLen2];
                }
                
                accum[i][len] = (accum[i][len-1] + dp) % M;
            }        
                        
        return accum[n-1][n];
    }
};
