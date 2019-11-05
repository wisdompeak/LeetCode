class Solution {
public:
    int nthMagicalNumber(int N, int A, int B) 
    {
        long MOD = 1e9+7;
        long lcm = A*B/gcd(A,B);
        long p = (long)N/(lcm/A+lcm/B-1);
        
        long s = p*(lcm/A+lcm/B-1);
        long t = (long)N - s;
        
        if (t==0) return lcm*p%MOD;
        
        int i = 1, j = 1;
        long remainder;
        while (count<t)
        {
            if (A*i < B*j)
            {
                remainder = A*i;
                i++;
            }
            else
            {
                remainder = B*j;
                j++;
            }
            count++;
        }
        
        return (lcm*p%MOD + remainder)%MOD;
        
        
    }
};
