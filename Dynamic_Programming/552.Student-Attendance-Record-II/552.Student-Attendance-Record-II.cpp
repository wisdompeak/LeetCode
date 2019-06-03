class Solution {
public:
    int checkRecord(int n) 
    {
        vector<long>dp00(n+1,0);
        vector<long>dp01(n+1,0);
        vector<long>dp02(n+1,0);
        vector<long>dp10(n+1,0);
        vector<long>dp11(n+1,0);
        vector<long>dp12(n+1,0);
        
        dp00[0] = 1;
        long M = 1e9+7;
        
        for (int i=1; i<=n; i++)
        {
            dp00[i] = (dp00[i-1] + dp01[i-1] + dp02[i-1])%M;
            dp01[i] = dp00[i-1];
            dp02[i] = dp01[i-1];
            dp10[i] = (dp00[i-1] +  dp01[i-1] + dp02[i-1] + dp10[i-1] + dp11[i-1] + dp12[i-1])%M;
            dp11[i] = dp10[i-1];
            dp12[i] = dp11[i-1];
        }
        
        return (dp00[n]+dp01[n]+dp02[n]+dp10[n]+dp11[n]+dp12[n])%M ;
    }
};
