class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) 
    {
        sort(A.begin(), A.end());
        int diff = A.back()-A[0];
        for (int i=0; i<A.size()-1; i++)
        {
            int MAX = max(A[i]+K, A.back()-K);
            int MIN = min(A[0]+K, A[i+1]-K);
            diff = min(diff, MAX-MIN);
        }
        return diff;
    }
};
