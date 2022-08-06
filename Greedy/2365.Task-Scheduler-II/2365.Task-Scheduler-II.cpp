using LL = long long;
class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) 
    {
        int n = tasks.size();
        unordered_map<int,LL>Map;        
        LL cur = 0;
        for (int i=0; i<n; i++)
        {
            if (Map.find(tasks[i])!=Map.end())        
                cur = max(cur, Map[tasks[i]]);            
            Map[tasks[i]] = cur+(LL)space+1;
            cur++;
        }
        return cur;        
    }
};
