class Solution {
public:
    bool isIdealPermutation(vector<int>& A) 
    {
        int curMax = A[0];
        for (int i=0; i<A.size(); i++)
        {
            if (i>=2) curMax = max(curMax, A[i-2]);         
            
            if (i>=2 && A[i]<curMax)
                return false;
        }
        return true;
    }
};
