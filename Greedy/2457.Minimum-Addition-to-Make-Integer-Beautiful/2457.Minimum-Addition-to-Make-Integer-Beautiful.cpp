class Solution {
public:
    int getSum(long long x)
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
        int len = to_string(n).size();
        string ret;
        
        int carry = 0;
        for (int i=0; i<len; i++)
        {
            if (getSum(n) <= target) break;

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
