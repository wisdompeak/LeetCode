class Solution {
public:
    double minmaxGasDist(vector<int>& stations, int K) 
    {
        priority_queue<pair<double,int>>pq;
        for (int i=1; i<stations.size(); i++)
            pq.push({stations[i]-stations[i-1],1});
        
        for (int i=0; i<K; i++)
        {
            double space = pq.top().first;
            int insertNum = pq.top().second;
            pq.pop();
            
            pq.push({space*insertNum/(insertNum+1),insertNum+1});            
        }
        
        return pq.top().first;
    }
};
