class Solution {
    vector<int>primes = {2,3,5,7,11,13,17,19,23,29};    
    long M = 1e9+7;
public:
    int numberOfGoodSubsets(vector<int>& nums) 
    {        
        int n = primes.size();
        vector<long>dp(1<<n);
        dp[0] = 1;

        unordered_map<int,int>Map;
        for (auto x: nums)
            Map[x]++;
        
        int count1 = 0;
        for (auto p: Map)
        {
            int x = p.first;
            int count = p.second;

            if (x==1) continue;
            int encode = encoding(x);
            if (encode==-1) continue;

            for (int state=(1<<n)-1; state>=1; state--)
            {
                if (state-encode == (state^encode))                
                    dp[state] = (dp[state] + dp[state-encode]*count%M) % M; 
            }
        }

        long ret = 0;
        for (int state=1; state<(1<<n); state++)
            ret = (ret+dp[state])%M;

        long power2 = 1;
        for (int i=0; i<Map[1]; i++)
            power2 = (power2 * 2) % M;

        return ret * power2 % M;
    }

    int encoding(int num)
    {       
        int encode = 0; 
        for (int i=0; i<primes.size(); i++)
        {
            if (num % primes[i] ==0)
            {
                encode += (1<<i);
                num /= primes[i];
            }                
            if (num % primes[i]==0)
                return -1;
        }
        return encode;
    }
};
