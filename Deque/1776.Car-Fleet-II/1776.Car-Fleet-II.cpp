class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) 
    {
        int n = cars.size();
        vector<double>rets(n);
        
        rets[n-1] = -1;
        deque<array<double, 2>>dq; // {time, speed} curve of the previous car
        dq.push_back({0, (double)cars.back()[1]});        
        
        for (int i=cars.size()-1; i>=0; i--)
        {
            if (cars[i][1] <= dq.back()[1])
            {
                dq.clear();
                dq.push_back({0, (double)cars[i][1]});
                rets[i] = -1;
                continue;
            }

            int dL = cars[i+1][0]-cars[i][0];
            double v0 = cars[i][1];
            double totalTravel = 0;
            double t = dq.front()[0];
            double v = dq.front()[1];
            
            while (dq.size()>=2)
            {
                dq.pop_front();
                if (totalTravel + (dq.front()[0]-t)*v + dL >= dq.front()[0]*v0)
                {
                    totalTravel += (dq.front()[0]-t)*v;
                    t = dq.front()[0];
                    v = dq.front()[1];
                }
                else
                    break;
            }

            double dt = (totalTravel + dL - t*v0) *1.0 / (v0 - v);
            double t2 = dt + t;

            dq.push_front({t2, v});
            dq.push_front({0, v0});            
            rets[i] = t2;
        }
        return rets;
        
    }
};
