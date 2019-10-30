typedef long long ll;
class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) 
    {
        ll left = 1;
        ll right = INT_MAX;
        
        while (left<right)
        {
            ll mid = left+(right-left)/2;
            if (count(mid, a,b,c) < n )
                left = mid+1;
            else
                right = mid;
        }
        
        return left;
    }
    
    int count(ll M, ll a, ll b, ll c)
    {
        return M/a+M/b+M/c-M/lcm(a,b)-M/lcm(a,c)-M/lcm(b,c)+M/lcm(lcm(a,b),c);
    }
    
    ll lcm(ll a, ll b)
    {
        return a*b/gcd(a,b);
    }
    
    ll gcd(ll a, ll b)
    {
        if (b==0)
            return a;
        return gcd(b, a%b);
    }
};
