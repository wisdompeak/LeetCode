class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) 
    {
        int n = A.size();
        vector<int>diff(n+1);

        int flips = 0;
        int count = 0;
        for (int i=0; i<n; i++)
        {
            flips+=diff[i];
            if ((A[i]+flips)%2==1) continue;

            if (i+K-1>=n) return -1;
            flips++;
            count++;
            diff[i+K]-=1;
        }

        return count;
    }
};
