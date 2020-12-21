class Solution {
    static bool cmp(vector<int>&a, vector<int>&b)
    {
        if (a[1]==b[1])
            return a[0]>b[0];
        else
            return a[1]<b[1];
    }
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) 
    {
        sort(intervals.begin(), intervals.end(), cmp);
        int a = intervals[0][1]-1, b = intervals[0][1];
        int count = 2;

        for (auto& interval: intervals)
        {
            if (interval[0]<=a)
                continue;
            else if (interval[0]<=b)
            {
                count++;
                a = b;
                b = interval[1];
            }
            else
            {
                count+=2;
                a = interval[1]-1;
                b = interval[1];
            }
        }
        return count;
    }
};
