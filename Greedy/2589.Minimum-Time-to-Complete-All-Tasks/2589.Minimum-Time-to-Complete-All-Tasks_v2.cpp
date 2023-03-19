using AI3 = array<int,3>;
class Solution {
public:
    int findMinimumTime(vector<vector<int>>& tasks) 
    {
        sort(tasks.begin(), tasks.end(), 
             [](vector<int>&a, vector<int>&b){return a[1]<b[1];}
            );
        
        vector<AI3>arr;
        arr.push_back({-2,-1,0});
                
        for (int i=0; i<tasks.size(); i++)
        {
            int a = tasks[i][0], b = tasks[i][1], d = tasks[i][2];

            AI3 temp = {a,0,0};
            auto iter = lower_bound(arr.begin(), arr.end(), temp);
            iter = iter-1;
            int already = 0;
            if ((*iter)[1] < a)
                already = arr.back()[2] - (*iter)[2];
            else
                already = arr.back()[2] - (*iter)[2] + abs((*iter)[1] - a + 1) ;
                
            int diff = d - already;
            int cur = b;
            while (diff > 0)
            {                
                if (abs(arr.back()[1] - cur) < diff)
                {
                    diff -= abs(arr.back()[1] - cur);
                    cur = arr.back()[0] - 1;
                    arr.pop_back();
                }
                else
                {
                    arr.push_back({cur-diff+1, b, arr.back()[2]+b-(cur-diff)});
                    diff = 0;
                }                
            }            
        }
                
        return arr.back()[2];
    }
};
