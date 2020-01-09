class Solution {
public:
    int sumSubseqWidths(vector<int>& A) 
    {
        long M = 1e9+7;
        
        vector<long>Pow2(20000,1);
        for (int i=1; i<20000; i++)
            Pow2[i] = Pow2[i-1]*2%M;
        
        sort(A.begin(),A.end());
        long sum = 0;
        int n = A.size();
        for (int i=0; i<n; i++)
        {
            sum -= A[i]*Pow2[n-1-i]%M;
            sum += A[i]*Pow2[i]%M;
            sum %= M;
        }
        return sum;
    }
};
