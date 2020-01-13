class Solution {
public:
    int consecutiveNumbersSum(int N) 
    {
        int count = 0;
        for (int m = 1; 2*N-m*m+m>0; m++ )
        {
            if ((2*N-m*m+m)%(2*m)==0)
                count++;
        }
        return count;
    }
};
