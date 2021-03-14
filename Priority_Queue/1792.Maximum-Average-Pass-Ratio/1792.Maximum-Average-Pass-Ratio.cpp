typedef array<double,3> AD3;
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) 
    {
        priority_queue<AD3>pq;
        for (auto c: classes)
        {
            double p = c[0];
            double t = c[1];
            pq.push({(p+1)/(t+1)-p/t, p, t});
        }
        
        for (int i=0; i<extraStudents; i++)
        {
            auto [r, p, t] = pq.top();
            pq.pop();
            p+=1;
            t+=1;
            pq.push({(p+1)/(t+1)-p/t, p, t});
        }
        
        double sum = 0;
        while (!pq.empty())
        {
            auto [r, p, t] = pq.top();
            sum += p/t;
            pq.pop();
        }
        int n = classes.size();
        return sum / n;        
        
    }
};
