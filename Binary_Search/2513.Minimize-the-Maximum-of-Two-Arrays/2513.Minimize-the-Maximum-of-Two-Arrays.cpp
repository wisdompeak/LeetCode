using LL = long long;
class Solution {
public:
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) 
    {
        LL left = 1, right = INT_MAX;
        while (left < right)
        {
            LL mid = left + (right-left)/2;
            if (NotEnough(divisor1, divisor2, uniqueCnt1, uniqueCnt2, mid))
                left = mid+1;
            else
                right  = mid;
        }
        return left;        
    }

    bool NotEnough(LL divisor1, LL divisor2, LL uniqueCnt1, LL uniqueCnt2, LL n)
    {
        LL a = n - n/divisor1;
        LL b = n - n/divisor2;
        LL c = n - (n/divisor1 + n/divisor2 - n/lcm(divisor1,divisor2));

        if (a < uniqueCnt1) return true;
        if (b < uniqueCnt2) return true;
        if (a+b-c < uniqueCnt1 + uniqueCnt2) return true;
        return false;
    }
};
