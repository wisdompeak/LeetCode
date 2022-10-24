class Solution {
public:
    int countPrimes(int n) 
    {
        vector<int>isPrime(n, true);
        int count = 0;
        for (int i=2; i<n; i++)
        {
            if (isPrime[i]==false) continue;
            count++;
            
            if (i < sqrt(n))
                for (int j=2*i; j<n; j+=i)
                    isPrime[j] = false;
        }
        
        return count;
    }
};
