class Solution {
public:
    int reinitializePermutation(int n) 
    {        
        if (n==2) return 1;
        int count = 1;        
        int power = 2;
        while (power % (n-1) !=1)
        {
            count++;
            power = power * 2 % (n-1);
        }
        return count;
    }
};
