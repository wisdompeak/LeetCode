class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) 
    {
        int N = num_people;
        int C = candies;
        int k = 0;
        
        while (C >= (1+N)*N/2 + N*N*k)
        {
             C -= (1+N)*N/2 + N*N*k;
             k++;
        }
        
        vector<int>rets(N,0);
        if (k>0)
        {
            for (int i=0; i<N; i++)
                rets[i] = (i+1 + i+1+N*(k-1) ) *k /2;
        }
        
        for (int i=0; i<N; i++)
        {
            if (C >= i+1+N*k )
            {
                rets[i] += i+1+N*k;
                C -= i+1+N*k;
            }
            else
            {
                rets[i] += C;
                break;
            }
        }
        
        return rets;
    }
};
