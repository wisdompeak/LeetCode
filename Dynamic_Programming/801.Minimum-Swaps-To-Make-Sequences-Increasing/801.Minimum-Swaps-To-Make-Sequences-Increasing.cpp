class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) 
    {
        int changed = 1, unchanged = 0;
        for (int i=1; i<A.size(); i++)
        {
            int changed_prev = changed;
            int unchanged_prev = unchanged;

            unchanged = INT_MAX, changed = INT_MAX;
            if (A[i-1]<A[i] && B[i-1]<B[i])
                unchanged = min(unchanged, unchanged_prev);
            if (B[i-1]<A[i] && A[i-1]<B[i])
                unchanged = min(unchanged, changed_prev);

            if (A[i-1]<B[i] && B[i-1]<A[i])
                changed = min(changed, unchanged_prev+1);
            if (B[i-1]<B[i] && A[i-1]<A[i])
                changed = min(changed, changed_prev+1);            
        }
        return min(changed, unchanged);

    }
};
