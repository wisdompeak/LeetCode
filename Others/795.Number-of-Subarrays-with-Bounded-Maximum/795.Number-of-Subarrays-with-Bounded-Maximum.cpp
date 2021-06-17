class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) 
    {
        long ret = 0;
        int start = -1, lastLR = -1;
     
        for (int i = 0; i < A.size(); i++) 
        { 
            if (A[i] > R) 
            {                
                start = -1;
                lastLR = -1;
            }
            else
            {
                if (start == -1)
                    start = i;
                if (A[i]<=R && A[i]>=L)
                    lastLR = i;                                
                
                if (start!=-1 && lastLR!=-1)
                    ret += (lastLR-start+1);                
            }
        }
 
        return ret;
    }
};
