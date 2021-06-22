class Solution {
public:
    int largestPalindrome(int n) 
    {
        if (n==1) return 9;
        
        int upper = pow(10,n)-1;
        int lower = pow(10,n-1);
        
        for (int i=upper; i>=lower; i--)
        {
            long long palindrome = createPalindrome(i);
            
            for (int j=upper; j>=sqrt(palindrome); j--)
            {
                if (palindrome%j==0 && palindrome/j>=pow(10,n-1))
                    return palindrome%1337;
            }
        }
        
        return -1;
    }
    
    long long createPalindrome(int i)
    {
        string temp = to_string(i);
        reverse(temp.begin(),temp.end());
        return stol(to_string(i)+temp);
    }
};
