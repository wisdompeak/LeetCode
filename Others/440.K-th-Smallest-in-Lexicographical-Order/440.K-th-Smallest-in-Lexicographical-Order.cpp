class Solution {
    
public:
    int findKthNumber(int n, int k) 
    {        
        return FindKthNumberBeginWith(0,n,k);
    }
    
    // return the Lexicographically Kth element that begin with the prefix
    // excluding the prefix itself
    int FindKthNumberBeginWith(int prefix, int n, int k)
    {       
        if (k==0) return prefix;        
        
        for (int i=(prefix==0?1:0); i<=9; i++)
        {
            int count = TotalNumbersBeginWith(prefix*10+i,n);
            if (count<k)
                k-=count;
            else
                return FindKthNumberBeginWith(prefix*10+i,n,k-1);
        }
    }
    
    // return how many numbers that begin with the prefix and within the range of n 
    // including the prefix itself
    int TotalNumbersBeginWith(long long prefix, int n)
    {
        long long fac = 1;
        int count = 0;
        
        for(int digit = 1; digit <= 9; digit++) 
        {
            long long min = prefix*fac;
            long long max = prefix*fac+fac-1;
            if(n < min)
                break;
            else if(min <= n && n <= max) 
            {
                count += (n-min+1);
                break;
            }
            else  
                count += fac;
            fac *= 10;
        }
        return count;
    }    
};
