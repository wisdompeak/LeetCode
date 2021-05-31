typedef array<int,2> AI2;
typedef array<int,3> AI3;
class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) 
    {
        priority_queue<AI2,vector<AI2>,greater<>>FreePQ;
        priority_queue<AI3,vector<AI3>,greater<>>BusyPQ;
        
        for (int i=0; i<servers.size(); i++)
            FreePQ.push({servers[i],i});
        queue<int>jobs;
        vector<int>rets(tasks.size());
        
        for (int j=0; j<tasks.size(); j++)
        {
            jobs.push(j);
            while (!BusyPQ.empty() && BusyPQ.top()[0]<=j)
            {
                auto [t,w,idx] = BusyPQ.top();
                BusyPQ.pop();
                FreePQ.push({w, idx});
            }
            while (!jobs.empty() && !FreePQ.empty())
            {
                int job = jobs.front();
                jobs.pop();
                auto [w,idx] = FreePQ.top();
                FreePQ.pop();
                rets[job] = idx;
                BusyPQ.push({j+tasks[job], w, idx});
            }
        }
        
        while (!jobs.empty())
        {
            int job = jobs.front();
            jobs.pop();
            auto [t,w,idx] = BusyPQ.top();
            BusyPQ.pop();
            rets[job] = idx;
            BusyPQ.push({t+tasks[job], w, idx});            
        }
        
        return rets;
    }
};
