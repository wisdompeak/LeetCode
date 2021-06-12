class Solution {
    static bool cmp(pair<int,int>&a, pair<int,int>&b)
    {
        return a.second*1.0 / a.first < b.second*1.0 / b.first; 
    }
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) 
    {
        vector<pair<int,int>>persons;
        for (int i=0; i<quality.size(); i++)
            persons.push_back({quality[i], wage[i]});

        sort(persons.begin(), persons.end(), cmp);

        priority_queue<int>pq_quality;
        int sum_quality = 0;
        double ret = 1e20;

        for (int i=0; i<persons.size(); i++)
        {
            sum_quality += persons[i].first;
            pq_quality.push(persons[i].first);
            if (pq_quality.size() > k)
            {
                sum_quality -= pq_quality.top();
                pq_quality.pop();
            }
            if (pq_quality.size() == k)
            {
                double unitWage = persons[i].second * 1.0 / persons[i].first;
                ret = min(ret, unitWage * sum_quality);
            }                
        }

        return ret;

    }
};
