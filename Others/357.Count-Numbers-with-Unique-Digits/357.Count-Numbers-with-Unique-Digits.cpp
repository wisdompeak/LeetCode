class Solution {
public:
    int countNumbersWithUniqueDigits(int n) 
    {
        if (n==0) return 1;
        int ret = 1;        
        for (int len = 1; len <= n; len++)
            ret += A(10, len) - A(9,len-1);
        return ret;        
    }
    
    int A(int m, int n)
    {
        int ret = 1;
        for (int i=0; i<n; i++)
            ret *= (m-i);
        return ret;
    }
};
