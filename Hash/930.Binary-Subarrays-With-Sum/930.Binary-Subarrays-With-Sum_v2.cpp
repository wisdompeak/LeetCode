class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) 
    {       
        int n = A.size();
        vector<int>postZeros(n);
        int count = 0;
        for (int i=n-1; i>=0; i--)
        {
            postZeros[i] = count;
            if (A[i]==0)            
                count++;            
            else
                count = 0;
        }
        
        int j = 0, sum = 0;
        int ret = 0;
        for (int i=0; i<n; i++)
        {
            while (j<=i || (j<n && sum < S))
            {
                sum += A[j];
                j++;
            }
            
            if (sum==S)
                ret += postZeros[j-1]+1;
            sum -= A[i]; 
        }
        
        return ret;        
    }
};
