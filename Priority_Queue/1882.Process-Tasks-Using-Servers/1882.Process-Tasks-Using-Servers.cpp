typedef array<int,2> AI2;
typedef array<int,3> AI3;

class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) 
    {
        priority_queue<AI2, vector<AI2>, greater<>>pq1;
        priority_queue<AI3, vector<AI3>, greater<>>pq2;
        for (int i=0; i<servers.size(); i++)
            pq1.push({servers[i], i});
        
        
        queue<int>jobs;
        vector<int>rets(tasks.size(),-1);
        
        for (int j=0; j<tasks.size(); j++)
        {
            jobs.push(j);
            while (!pq2.empty() && pq2.top()[0] <= j)
            {
                auto [t,w,idx] = pq2.top();
                pq2.pop();
                pq1.push({w,idx});
            }
            
            while (!jobs.empty() && !pq1.empty())
            {
                int job = jobs.front();
                jobs.pop();
                auto [w, idx] = pq1.top();
                pq1.pop();
                pq2.push({j+tasks[job], w, idx});                
                rets[job] = idx;
            }
        }
        
        while (!jobs.empty())
        {
            int job = jobs.front();
            jobs.pop();
            auto [t, w, idx] = pq2.top();
            pq2.pop();
            pq2.push({t+tasks[job], w, idx});                
            rets[job] = idx;
        }
        
        return rets;
    }
};
