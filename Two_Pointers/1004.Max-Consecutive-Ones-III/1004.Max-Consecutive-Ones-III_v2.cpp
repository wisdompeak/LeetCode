class Solution {
public:
    int longestOnes(vector<int>& A, int K) 
    {
        int n = A.size();
        int j = 0;
        int ret = 0;
        int count = 0;
        for (int i=0; i<n; i++)
        {
            while (j<n && (A[j]==1 || (A[j]==0 && count<K)))
            {
                if (A[j]==0) count++;                
                j++;                
            }
            ret = max(ret, j-i);
            if (A[i]==0) count--;
        }
        return ret;
        
    }
};
