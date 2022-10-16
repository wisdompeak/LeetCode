class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) 
    {
        vector<int>powers;
        for (int i=0; i<32; i++)
        {
            if (n%2!=0)            
                powers.push_back(i);            
            n/=2;
            if (n==0) break;
        }
        
        vector<int>presum(powers.size());
        for (int i=0; i<powers.size(); i++)
        {
            if (i==0) presum[i] = powers[i];
            else presum[i] = presum[i-1] + powers[i];
        }
        
        vector<long>twos(32*32,1);
        long M = 1e9+7;
        for (int i=1; i<32*32; i++)
            twos[i] = twos[i-1] * 2 % M;
        
        vector<int>rets;
        for (auto& query : queries)
        {
            int l = query[0], r = query[1];
            int diff = presum[r] - (l==0?0:presum[l-1]);
            rets.push_back(twos[diff]);
        }
        return rets;
    }
};
