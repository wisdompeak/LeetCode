class Solution {
public:
    int findKthNumber(int n, int k) 
    {
        return FindKthNUmberBeginWith(0, n, k);
    }

    // return the Lexicographically k-th element that begins with prefix
    // if k==0, return prefix itself
    int FindKthNUmberBeginWith(int prefix, int n, int k)
    {
        if (k==0) return prefix;

        int start = (prefix == 0) ? 1 : 0;
        for (int i=start; i<=9; i++)
        {
            int count = 1 + TotalNumbersBeginWith(prefix*10+i, n);
            if (count < k)
                k = k-count;
            else
                return FindKthNUmberBeginWith(prefix*10+i, n, k-1);
        }

        return -1;
    }

    // return how many numbers that begin with prefix (and <= n)
    // excluding prefix itself
    int TotalNumbersBeginWith(long prefix, int n)
    {
        long count = 0;
        long exp = 10;
        while (1)
        {
            long lower = prefix * exp;
            long upper = prefix * exp + exp + 1;
            if (lower > n) break;
            if (lower <= n && upper >= n)
            {
                count += (n - lower +1);
                break;
            }
            else
            {
                count += exp;
            }

            exp *= 10;
        }

        return count;
    }
};

