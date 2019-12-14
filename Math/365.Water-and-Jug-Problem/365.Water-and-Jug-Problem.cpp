class Solution {
public:
    bool canMeasureWater(int x, int y, int z) 
    {
        if(x + y < z) return false;
        if (z==x||z==y||z==x+y) return true;
        return z% __gcd(x, y) ==0;
    }
};
