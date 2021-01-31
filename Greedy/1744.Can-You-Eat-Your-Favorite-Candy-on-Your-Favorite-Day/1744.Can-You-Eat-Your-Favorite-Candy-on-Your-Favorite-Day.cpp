typedef long long ll;
class Solution {
public:
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) 
    {
        int n = candiesCount.size();
        candiesCount.insert(candiesCount.begin(),0);
        vector<ll>presum(n+1);
        for (int i=1; i<=n; i++)
            presum[i] = presum[i-1]+candiesCount[i];
        
        vector<bool>rets;
        for (auto q: queries)
        {
            ll type = q[0]+1;
            ll day = q[1]+1;
            ll cap = q[2];
                                    
            if (1*(day-1) >= presum[type])            
                rets.push_back(false);                            
            else if (day*cap <= presum[type-1])            
                rets.push_back(false);                            
            else
                rets.push_back(true);            
        }
        return rets;        
    }
};
