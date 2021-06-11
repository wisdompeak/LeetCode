class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) 
    {
        vector<pair<double,int>>q;
        for (int i=0; i<quality.size(); i++)
            q.push_back({wage[i]*1.0/quality[i],quality[i]});
        sort(q.begin(),q.end());
        
        int totalQuality = 0;
        double result = INT_MAX;
        priority_queue<int>pq;
        for (int i=0; i<q.size(); i++)
        {
            totalQuality+=q[i].second;
            pq.push(q[i].second);
            
            if (pq.size()==K)
            {
                double unitWage = q[i].first;
                result = min(result,unitWage*totalQuality);
                totalQuality-=pq.top();
                pq.pop();
            }
        }        
        
        return result;        
    }
};
