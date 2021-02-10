class Solution {
    static bool cmp(vector<int>&a, vector<int>&b)
    {
        return a[0] < b[0];
    }
public:
    int maxEvents(vector<vector<int>>& events) 
    {
        sort(events.begin(), events.end(), cmp);
        priority_queue<int, vector<int>, greater<int>>pq;
        int i = 0;
        int ret = 0;
        for (int day=1; day<=100000; day++)
        {
            while (i<events.size() && events[i][0]<=day)
            {
                pq.push(events[i][1]);
                i++;
            }
            while (!pq.empty() && pq.top() < day)
                pq.pop();
            if (!pq.empty())
            {
                pq.pop();
                ret++;
            }
        }
        return ret;
    }
};
