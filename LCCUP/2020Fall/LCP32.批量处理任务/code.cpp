typedef pair<int,int> PII;
class Solution {    
public:
    int processTasks(vector<vector<int>>& tasks) 
    {
        int runtime = 0;  // the minimum time to run jobs
        priority_queue<PII, vector<PII>, greater<>>pq; // {latestTimeToStart, duration}
        sort(tasks.begin(), tasks.end());
        tasks.push_back({1000000005, 1000000005, 1});

        for (auto task: tasks)
        {
            while (!pq.empty() && pq.top().first + runtime < task[0])
            {
                if (runtime >= pq.top().second) 
                    pq.pop();
                else
                    runtime += min(pq.top().second, task[0]-pq.top().first) - runtime;
            }
            pq.push({task[1]-task[2]+1-runtime, task[2]+runtime});
        }
        return runtime;
    }
};
