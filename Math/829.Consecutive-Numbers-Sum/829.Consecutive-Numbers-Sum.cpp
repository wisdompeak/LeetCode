class Solution {
public:
    int consecutiveNumbersSum(int N) 
    {
        int count = 0;
        
        for (int m=1; m<=sqrt(2*N)+1; m++)
        {
            if ((2*N-m*(m-1))%(2*m)==0 && 2*N-m*(m-1)>0)
                count++;
        }
        return count;
    }
};
