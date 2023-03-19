class Solution {
public:
    int findMinimumTime(vector<vector<int>>& tasks) 
    {
        sort(tasks.begin(), tasks.end(), [](vector<int>&a, vector<int>&b){
            return a[1] < b[1];
        });

        vector<int>time(2005);
        for (int i=0; i<tasks.size(); i++)
        {
            int start = tasks[i][0], end = tasks[i][1], duration = tasks[i][2];
            int overlap = 0;
            for (int t=start; t<=end; t++)
                overlap += (time[t]==1);

            if (overlap >= duration) continue;
            int diff = duration - overlap;
            for (int t=end; t>=start; t--)
            {
                if (time[t]==0)
                {
                    time[t] = 1;
                    diff--;
                }
                if (diff == 0)
                    break;
            }
        }

        int ret = 0;
        for (int t=0; t<=2000; t++)
            ret += (time[t]==1);
        return ret;
    }
};
