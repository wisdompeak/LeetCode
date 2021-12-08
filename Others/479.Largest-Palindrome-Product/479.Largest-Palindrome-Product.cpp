class Solution {
public:
    // Rank: 34.85% -> 81.82%
    int largestPalindrome(int n) 
    {
        if (n==1) return 9;
        int lower = pow(10,n-1), upper = lower * 10 - 1;
        
        for (int i=upper; i>=lower; i--)
        {
            long long palindrome = i;
            for (int j = i; j > 0; j /= 10) 
            {
                palindrome = palindrome * 10 + j % 10;
            }
            
            for (int j=sqrt(palindrome); j <= upper; j++)
            {
                if (palindrome%j==0 && palindrome/j<=upper)
                    return palindrome%1337;
            }
        }
        
        return -1;
    }
};
