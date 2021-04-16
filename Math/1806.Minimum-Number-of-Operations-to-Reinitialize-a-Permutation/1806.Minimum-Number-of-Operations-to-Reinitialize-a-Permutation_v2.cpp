class Solution {
public:
    int reinitializePermutation(int n) 
    {        
        int count = 0;
        int i = 1;
        while (count==0 || i!=1)
        {
            if (i < n/2)
                i = i*2;
            else
                i = i*2 - (n-1);
            count++;
        }
        return count;
    }
};
