class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) 
    {
        vector<pair<long long, long long>>persons;
        for (int i=0; i<n; i++)
            persons.push_back({efficiency[i], speed[i]});
        sort(persons.rbegin(), persons.rend());
        
        priority_queue<int,vector<int>,greater<>>pq;
        long long speedSum = 0;
        long long ret = 0;
        
        for (int i=0; i<n; i++)
        {
            if (pq.size()>k-1)
            {
                speedSum -= pq.top();
                pq.pop();
            }                
            
            speedSum += persons[i].second;
            ret = max(ret, speedSum * persons[i].first );
                        
            pq.push(persons[i].second);            
        }
        
        long long M = 1e9+7;
        return ret % M;        
    }
};
