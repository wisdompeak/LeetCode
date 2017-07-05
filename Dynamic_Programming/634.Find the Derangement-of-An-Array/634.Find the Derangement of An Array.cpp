class Solution {
public:
    int findDerangement(int n) 
    {
        if (n==1) return 0;
        if (n==2) return 1;
        
        long long a=0;
        long long b=1;
        long long c;
        long long m=pow(10,9)+7;
        
        for (int k=3; k<=n; k++)
        {
            c = (a+b)%m*(k-1)%m;
            a = b;
            b = c;
        }
        
        return c;
    }
};
