class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) 
    {
        int K = 0;
        for (int i=0; i<8; i++)
            K += (cells[i]<<i);
        int K0 = K;

        unordered_map<int,int>Map;
        int t = 0;
        while (Map.find(K)==Map.end())
        {
            Map[K] = t;
            K = (~((K>>1)^(K<<1)))&126;
            t++;
        }
        int S = Map[K];
        int L = t - S;

        int M = K0;
        if (N >= S)
            N = (N-S) % L + S;

        for (int i=0; i<N; i++)
        {
            M = (~((M>>1)^(M<<1)))&126;
        }
        
        vector<int>results(8,0);
        for (int i=0; i<8; i++)
            results[i] = ((M>>i)&1);
        return results;
    }
};
