class Solution {
public:
    int DigitSum(long long x)
    {
        int sum = 0;
        while (x>0)
        {
            sum += x%10;
            x/=10;
        }
        return sum;
    }
    
    long long makeIntegerBeautiful(long long n, int target) 
    {
        string ret;        
        int carry = 0;
        while (n > 0)
        {
            if (DigitSum(n) <= target) break;

            int cur = n%10;
            int d;            
            if (cur != 0)
            {
                ret.push_back('0' + (10-cur));
                carry = 1;
            }
            else
            {
                ret.push_back('0');
                carry = 0;
            }
                            
            n = n/10 + carry;
        }
        
        if(ret.empty()) return 0;
        reverse(ret.begin(), ret.end());
        return stoll(ret);
    }
};
