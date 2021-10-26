class Solution {
public:
    int findKthNumber(int m, int n, int k) 
    {
        int left=1;
        int right=m*n;
        if (m > n) {
            m ^= n ^ (n = m);
        }
        
        while (left<right)
        {
            int mid=left+(right-left)/2;
            
            int count=0;
            for (int i=1; i<=m; i++)
                count+= min(mid/i,n);
            if (count<k)
                left=mid+1;
            else
                right=mid;
        }
        
        return left;
    }
};
