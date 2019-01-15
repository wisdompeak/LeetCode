class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) 
    {
        vector<pair<int,int>>tasks;
        for (int i=0; i<difficulty.size(); i++)
            tasks.push_back({difficulty[i],profit[i]});
        
        sort(tasks.begin(),tasks.end());
        
        int MAX = tasks[0].second;
        for (int i=1; i<tasks.size(); i++)
        {
            tasks[i].second = max(tasks[i].second,MAX);
            MAX = tasks[i].second;
        }        
        
        int sum = 0;
        for (int x:worker)
        {
            auto iter = upper_bound(tasks.begin(),tasks.end(),make_pair(x,INT_MAX));
            if (iter!=tasks.begin())
            {
                iter = prev(iter,1);
                sum+=iter->second;
            }
        }
        return sum;
    }
};
