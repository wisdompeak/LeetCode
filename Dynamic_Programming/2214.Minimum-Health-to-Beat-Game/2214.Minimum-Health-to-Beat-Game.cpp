using LL = long long;
class Solution {
public:
    long long minimumHealth(vector<int>& damage, int armor) 
    {
        int n = damage.size();
        LL dp0 = 0;
        LL dp1 = 0;
        LL ret = LLONG_MAX;
        for (int i=0; i<n; i++)
        {
            LL dp0_tmp = dp0, dp1_tmp = dp1;
            dp0 = dp0_tmp - damage[i];
            dp1 = max(dp1_tmp - damage[i], dp0_tmp+min(armor,damage[i])-damage[i]);
                        
            ret = min(ret, max(dp0, dp1));
        }
        return ret > 0? 0 : (-ret+1);        
    }
};
