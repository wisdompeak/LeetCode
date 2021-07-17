class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) 
    {
        long ret = 0;
        int start = -1, validMax = -1;
     
        for (int i = 0; i < A.size(); i++) 
        { 
            if (A[i] > R) 
            {                
                start = -1;
                validMax = -1;
            }
            else
            {
                if (start == -1)
                    start = i;
                if (A[i]<=R && A[i]>=L)
                    validMax = i;                                
                
                if (start!=-1 && validMax!=-1)
                    ret += (validMax-start+1);                
            }
        }
 
        return ret;
    }
};
