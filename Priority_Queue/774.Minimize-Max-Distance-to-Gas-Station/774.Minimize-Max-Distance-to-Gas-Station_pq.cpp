class Solution {
public:
    double minmaxGasDist(vector<int>& stations, int K) 
    {
        double ub = double(stations.back()-stations[0]) / (K + 1);
        
        priority_queue<pair<double,int>>pq;
        for (int i=1; i<stations.size(); i++)
        {
            double dist = stations[i]-stations[i-1];            
            int t = fmax(1, floor(dist / ub));
            pq.push({dist / t, t});
            K-=(t-1);
        }
                
        while (K>0)
        {
            double space = pq.top().first;
            int parts = pq.top().second;
            pq.pop();
            
            pq.push({space*parts/(parts+1), parts+1});
            K--;
        }
        
        return pq.top().first;
    }
};
