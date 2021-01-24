typedef long long ll;

class Solution {
    ll comb[10015][15]; 
    ll M = 1e9+7;
public:
    vector<int> waysToFillArray(vector<vector<int>>& queries) 
    {        
        int maxK = 10000;
        int maxExp = 14;
        for (int i = 0; i <= (maxK+maxExp); ++i) 
        {
            comb[i][0] = 1;            
            for (int j = 1; j <= min(i, maxExp); ++j) 
            {
                comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % M;
            }
        }  

        vector<int>rets;
        for (auto q:queries)
        {
            ll ans = 1;
            int k = q[0];
            int n = q[1];
            for (int x=2; x<=n; x++)
            {
                int count = 0;
                while (n%x==0)
                {
                    count++;
                    n/=x;
                }
                ans = ans * comb[count+k-1][count] % M;                
            }
            rets.push_back(ans);
        }
        return rets;
    }
};
