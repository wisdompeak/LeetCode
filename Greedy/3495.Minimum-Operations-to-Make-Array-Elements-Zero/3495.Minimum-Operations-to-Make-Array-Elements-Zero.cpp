using ll = long long;
class Solution {
public:
    ll helper(ll a, ll b) 
    {        
        ll total = 0;

        ll x = 1;
        while (x<=b) {
            total += b-max(x,a)+1;
            x*=4;
        }
                
        ll B = log(b+1)/log(4);
        if (B*2<=total) return (total+1)/2;
        ll A = total - B;        
        return A + (B-A+1)/2;
    }

    
    long long minOperations(vector<vector<int>>& queries) 
    {
        long long ret = 0;
        for (auto&q : queries)
        {
            int a = q[0], b = q[1];
            ret += helper(a,b);
        }
        return ret;        
    }
};
