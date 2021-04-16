class Solution {
public:
    int reinitializePermutation(int n) 
    {
        vector<int>perm0(n);
        for (int i=0; i<n; i++)
            perm0[i] = i;
        
        auto perm = perm0;
        
        int count = 0;
        while (1)
        {
            vector<int>arr = perm;
            for (int i=0; i<n; i++)
            {
                if (i%2==0)
                    arr[i] = perm[i / 2];
                else
                    arr[i] = perm[n / 2 + (i - 1) / 2];                    
            }
            count++;
            if (arr == perm0) return count;
            perm = arr;            
        }
        return -1;
        
    }
};
