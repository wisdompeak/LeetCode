class Solution {
public:
    int getSum(int a, int b) 
    {        
        while (b!=0)
        {
            int aa= a^b;  // 不进位的加法
            int bb= (a&b)<<1; // 各个位上的进位值
            a = aa;
            b = bb;
        }        
        return a;        
    }
};
