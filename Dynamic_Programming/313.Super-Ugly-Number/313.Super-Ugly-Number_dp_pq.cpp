using LL = long long;
typedef pair<LL,int> PII;
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) 
    {
        int k = primes.size();
        
        vector<LL>rets({1});
        vector<LL>p(k, 0);
        
        priority_queue<PII, vector<PII>, greater<>>pq;
        for (int i=0; i<k; i++)
            pq.push({rets[p[i]]*primes[i], i});
        
        for (int t=0; t<n-1; t++)
        {
            LL cur = pq.top().first;
            rets.push_back(cur);
            
            while (!pq.empty() && cur == pq.top().first)
            {
                int i = pq.top().second;
                pq.pop();
                
                p[i]++;
                pq.push({rets[p[i]]*primes[i], i});
            }
        }
        
        return rets.back();
    }
};
