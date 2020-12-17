class Solution {
    static bool cmp(vector<int>&a, vector<int>&b)
    {
        if (a[1]-a[0] == b[1]-b[0])
            return a[1]<b[1];
        else
            return a[1]-a[0]<b[1]-b[0];
    }
public:
    int minimumEffort(vector<vector<int>>& tasks) 
    {
        sort(tasks.begin(), tasks.end(), cmp);        
        int start = 0;
        for (auto x: tasks)
        {            
            start = max(start+x[0], x[1]);     
        }
        return start;        
    }
};
