class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) 
    {
        int globalMax = INT_MIN;    // cannot be 0-element
        int globalMin = 0;          // can be 0-elelment, but cannot cantain all elements
        int N = A.size();
        vector<int>LocalMin(N);
        vector<int>LocalMax(N);
        
        int Sum = accumulate(A.begin(),A.end(),0);
        
        LocalMax[0] = A[0];
        LocalMin[0] = min(0,A[0]);
        
        for (int i=1; i<A.size(); i++)
        {
            LocalMax[i] = max(LocalMax[i-1]+A[i],A[i]);
            LocalMin[i] = min(LocalMin[i-1]+A[i],A[i]);
            globalMax = max(globalMax,LocalMax[i]);
            globalMin = min(globalMin,LocalMin[i]);
        }
        
        if (Sum==globalMin)     // in this case, the minimum subarray contain all elements, which is invalid
            return globalMax;
        else
            return max(globalMax,Sum-globalMin);
        
    }
};
