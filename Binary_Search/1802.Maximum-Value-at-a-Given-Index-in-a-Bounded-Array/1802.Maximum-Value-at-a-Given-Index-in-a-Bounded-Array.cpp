class Solution {
public:
    int maxValue(int n, int index, int maxSum) 
    {
        int left = 1, right = maxSum;
        while (left < right)
        {
            int mid = right - (right-left)/2;
            if (count(mid, n, index) <= (long)maxSum)
                left = mid;
            else
                right = mid - 1;
        }
        return left;        
    }
    
    long count(long h, long n, long index)
    {
        long sum = 0;
        if (h > index)
        {
            sum += (h-index + h)*(index+1)/2;
        }
        else
        {
            sum += (1+h)*h/2;
            sum += index+1-h;
        }
        if (h > n-index)
        {
            sum += (h + h-(n-index)+1)*(n-index)/2;
        }
        else
        {
            sum += (h + 1)*h/2;
            sum += (n - (index+h));
        }
        return sum-h;
    }
};
