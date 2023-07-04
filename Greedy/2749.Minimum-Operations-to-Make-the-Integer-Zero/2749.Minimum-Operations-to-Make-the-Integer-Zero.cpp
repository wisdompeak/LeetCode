using LL = long long;
class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) 
    {
        long long x = num1;
        long long y = num2;
        int k = 1;
        while (1)
        {
            x -= y;
            if (x < k) return -1;        
            
            int count = __builtin_popcountll(x);                        
            if (count <= k) return k;
            k++;
        }
        return -1;
    }
};
