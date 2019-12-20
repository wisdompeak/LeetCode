class Solution {
public:
    int mirrorReflection(int p, int q) 
    {
        int m=1;
        while (q*m%p!=0)
            m++;
        
        int n = q*m/p;
        
        if (m%2==1 && n%2==1)
            return 1;
        else if (m%2==0 && n%2==1)
            return 2;
        else if (m%2==1 && n%2==0)
            return 0;
    }
};
