using LL = long long;
class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) 
    {
        LL left = 1, right = 51e9;
        while (left < right)
        {
            LL mid = left+(right-left)/2;
            if (isOK(coins, mid, k))
                right = mid;
            else
                left = mid+1;
        }
        return left;
    }
    
    bool isOK(vector<int>& coins, LL A, int t)
    {
        int m = coins.size();
        
        int sign = 1;
        LL ret = 0;
        
        for (int k=1; k<=m; k++)
        {
            LL sum = 0;
            int state = (1 << k) - 1;            
            while (state < (1 << m))
            {
                LL product = 1;
                for (int i=0; i<m; i++)
                {
                    if ((state>>i)&1)
                        product = product * coins[i] / gcd(product, coins[i]);
                }
                sum += A / product;                

                int c = state & - state;
                int r = state + c;
                state = (((r ^ state) >> 2) / c) | r;
            }
            
            ret += sum * sign;
            sign *= -1;
        }
        
        return ret >= t;
        
    }
};
