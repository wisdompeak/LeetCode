class Solution {
public:
    int lastRemaining(int n) 
    {
        if (n==1) return 1;
        
        return (n/2+1 - lastRemaining(n/2))*2;
    }
};
