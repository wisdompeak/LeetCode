class Solution {
public:
    bool isIdealPermutation(vector<int>& A) 
    {
        int curMax = -1;
        for (int i=1; i<A.size(); i++)
        {
            if (i>=2)
                curMax = max(curMax, A[i-2]);
            if (curMax > A[i])
                    return false;
            
        }
        return true;        
    }
};
