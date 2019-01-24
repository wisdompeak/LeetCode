class Solution {
public:
    int reverse(int x) 
    {
        if (x==INT_MIN) return 0;        
        int flag = (x>=0)? 1:-1;
        x = abs(x);
        int result = 0;
        while (x>0)
        {
            int temp  = result*10+x%10;
            if (temp/10!=result) return 0;
            result = temp;
            x = x/10;
        }
        return flag*result;
    }
};
