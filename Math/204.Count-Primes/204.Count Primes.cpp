class Solution {
public:
    int countPrimes(int n) 
    {
        if (n<=2) return 0;
        
        vector<bool> num(n - 1, true);
        
        for (int x = 2; x <= sqrt(n); x++) 
        {
            if (num[x]==false) continue;
            
            for (int j=2; x*j < n; j++) 
                num[x*j] = false;
        }
        
        int count=0;
        for (int j = 2; j < n; ++j) 
        {
            if (num[j]) count++;
        }
        
        return count;
    }
};
