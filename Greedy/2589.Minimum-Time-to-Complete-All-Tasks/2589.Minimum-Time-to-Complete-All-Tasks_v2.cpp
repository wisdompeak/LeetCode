using AI3 = array<int,3>;
class Solution {
public:
    int findMinimumTime(vector<vector<int>>& tasks) 
    {
        sort(tasks.begin(), tasks.end(), [](vector<int>&a, vector<int>&b){
            return a[1] < b[1];
        });

        vector<AI3>arr;   
        arr.push_back({-2,-1,0});

        for (int i=0; i<tasks.size(); i++)
        {
            int start = tasks[i][0], end = tasks[i][1], duration = tasks[i][2];

            auto iter = lower_bound(arr.begin(), arr.end(), AI3({start,0,0}));
            iter = prev(iter);

            int overlap;
            if ((*iter)[1] < start)
                overlap = arr.back()[2] - (*iter)[2];
            else
                overlap = arr.back()[2] - (*iter)[2] + abs((*iter)[1] - start + 1);

            int diff = duration - overlap;
            int cur = end;
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
                    arr.push_back({cur-diff+1, end, arr.back()[2] + end-(cur-diff)});
                    diff = 0;
                }
            }
        }

        return arr.back()[2];
    }
};
