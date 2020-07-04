class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) 
    {
        unsigned char K = 0;
        for (int i=0; i<8; i++)
            K += (cells[i]<<i);
        
        K = (~((K>>1)^(K<<1)))&126;
        
        N = (N-1)%64;
        
        for (int i=0; i<N; i++)
        {
            K = (~((K>>1)^(K<<1)))&126;
        }
        
        vector<int>results(8,0);
        for (int i=0; i<8; i++)
            results[i] = ((K>>i)&1);
        return results;
    }
};
