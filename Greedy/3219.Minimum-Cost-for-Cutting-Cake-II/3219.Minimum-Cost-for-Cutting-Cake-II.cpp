using LL = long long;
class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& h, vector<int>& v) 
    {
        sort(h.rbegin(), h.rend());
        sort(v.rbegin(), v.rend());
        
        LL i=0, j=0;
        LL ret = 0;
        while (i<m-1 && j<n-1)
        {
            if (h[i]>v[j])
            {
                ret += h[i]*(j+1);
                i++;
            }
            else
            {
                ret += v[j]*(i+1);
                j++;
            }                
        }
        while (i<m-1)
        {
            ret += h[i]*(j+1);
            i++;
        }
        while (j<n-1)
        {
            ret += v[j]*(i+1);
            j++;
        }
        
        return ret;
    }
};
