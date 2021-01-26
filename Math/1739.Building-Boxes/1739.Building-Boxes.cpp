typedef long long ll;

class Solution {
public:
    int minimumBoxes(int n) 
    {
        int left = 1, right = 1e9;
        while (left < right)
        {
            int mid = left+(right-left)/2;
            if (cal(mid) >= n)
                right = mid;
            else
                left = mid+1;
        }
        return left;        
    }
    
    ll cal(ll area)
    {
        ll d = (int)sqrt(2*area);
        while ((1+d)*d/2 > area)
            d--;
        ll diff = area - (1+d)*d/2;
        
        vector<ll>a(d);
        for (int i=0; i<d; i++)
            a[i] = d - i;
        for (int i=0; i<diff; i++)
            a[i] += 1;        
        
        ll total = 0;
        ll sufsum = 0;
        for (int i=d-1; i>=0; i--)
        {
            sufsum += a[i];
            total += sufsum;
        }
        
        // cout<<area<<" "<<d<<" "<<total<<endl;
        
        return total;        
    }
};
