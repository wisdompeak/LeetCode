class Solution {
public:
    int reinitializePermutation(int n) 
    {        
        int count = 0;
        int i = 1;
        while (count==0 || i!=1)
        {
            if (i%2==0)
                i = i/2;
            else
                i = n / 2 + (i - 1) / 2;
            count++;
        }
        return count;
    }
};
