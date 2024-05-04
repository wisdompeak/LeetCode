using LL = long long;
class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) 
    {
        LL left = 1, right = 51e9;
        while (left < right)
        {
            LL mid = left+(right-left)/2;
            if (countNumber(mid, coins) >= k)
                right = mid;
            else
                left = mid+1;
        }
        return left;
    }

    LL countNumber(LL M, vector<int>& coins)
    {
        int m = coins.size();

        LL ret = 0;
        int sign = 1;

        for (int k=1; k<=m; k++)
        {
            LL sum = 0;
            int state = (1 << k) - 1;            
            while (state < (1 << m))
            {
                LL LCM = 1;
                for (int i=0; i<m; i++)
                {
                    if ((state>>i)&1)
                        LCM = lcm(LCM, coins[i]);
                }
                sum += M / LCM;

                int c = state & - state;
                int r = state + c;
                state = (((r ^ state) >> 2) / c) | r;
            }

            ret += sum * sign;
            sign *= -1;
        }

        return ret;
    }
};
