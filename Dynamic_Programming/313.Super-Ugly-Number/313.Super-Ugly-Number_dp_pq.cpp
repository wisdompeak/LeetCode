typedef pair<int,int> PII;
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) 
    {
        vector<int>p(primes.size(),0);

        vector<int>rets({1});
        priority_queue<PII, vector<PII>, greater<>>pq;                
        for (int i=0; i<primes.size(); i++)
            pq.push({primes[i]*rets[0], i});

        for (int t=0; t<n-1; t++)
        {            
            int cur = pq.top().first;
            rets.push_back(cur);

            while (!pq.empty() && pq.top().first==cur)                
            {
                int i = pq.top().second;
                pq.pop();

                p[i]++;                
                pq.push({primes[i]*rets[p[i]], i});
            }            
        }

        return rets.back();
    }
};
