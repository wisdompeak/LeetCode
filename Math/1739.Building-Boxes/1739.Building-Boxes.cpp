typedef long long ll;

class Solution {
    int a[1000000];
public:
    int minimumBoxes(int n) 
    {
        ll left = 1, right = 1e9;
        while (left < right)
        {
            ll mid = left+(right-left)/2;
            if (cal(mid) >= n)
                right = mid;
            else
                left = mid+1;
        }       
        return left;
    }
    
    ll cal(ll t)
    {        
        ll n = (int)sqrt(2*t);       
        if ((1+n)*n/2 > t)
            n--;
            
        for (int i=1; i<=n; i++)
            a[i] = n-i+1;
        ll diff = t - (1+n)*n/2;
        for (int i=1; i<=diff; i++)
            a[i] += 1;

        ll count = 0;
        ll sufsum = 0;
        for (ll k = n; k >= 1; k--)
        {
            sufsum += a[k];
            count += sufsum;
        }
        return count;
    }
};
