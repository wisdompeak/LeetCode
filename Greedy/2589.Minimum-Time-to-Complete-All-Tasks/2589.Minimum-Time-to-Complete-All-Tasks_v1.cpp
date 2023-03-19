class Solution {
public:
    int findMinimumTime(vector<vector<int>>& tasks) 
    {
        sort(tasks.begin(), tasks.end(), [](vector<int>&a, vector<int>&b){
             return a[1]<b[1];}
            );
        
        vector<int>time(4005);
        for (int i=0; i<tasks.size(); i++)
        {
            int a = tasks[i][0], b = tasks[i][1], d = tasks[i][2];
            int count = 0;
            for (int t=a; t<=b; t++)
                count += (time[t]==1);
            if (count >= d) continue;
            int diff = d - count;
            for (int j=b; j>=a; j--)
            {
                if (time[j]==0)
                {
                    time[j] = 1;
                    diff--;
                }
                if (diff == 0) break;
            }            
        }
        
        int ret = 0;
        for (int t=0; t<=2000; t++)
            ret += (time[t]==1);
        return ret;
    }
};
