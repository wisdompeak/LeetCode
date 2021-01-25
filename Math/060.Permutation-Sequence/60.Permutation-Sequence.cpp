class Solution {
public:
    string getPermutation(int n, int k) 
    {
        vector<int>digits;
        for (int i=1; i<=n; i++)
            digits.push_back(i);
        
        k--;
        
        string ret;
        while (n>0)
        {
            int a = k/ fact(n-1);
            ret.push_back('0'+digits[a]);
            
            k -= a * fact(n-1);
            n -= 1;
            
            digits.erase(digits.begin()+a);
        }
        
        return ret;
    }
    
    int fact(int k)
    {
        int ret = 1;
        for (int i=1; i<=k; i++)
            ret *= i;
        return ret;
    }
};
