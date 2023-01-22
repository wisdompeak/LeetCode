class Solution {
public:    
    bool isReachable(int targetX, int targetY) 
    {
        int g = gcd((LL)targetX, (LL)targetY);
        while (g%2==0) g/=2;
        return g==1;
    }       
};
