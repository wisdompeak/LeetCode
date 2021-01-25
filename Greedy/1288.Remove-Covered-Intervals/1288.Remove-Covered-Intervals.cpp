class Solution {
    static bool cmp(vector<int>&a, vector<int>&b)
    {
        if (a[0]!=b[0])
            return a[0]<b[0];
        else
            return a[1]>b[1];
    }
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) 
    {
        sort(intervals.begin(), intervals.end(), cmp);
        int i = 0;
        int count = 0;
        while (i<intervals.size())
        {
            count++;
            int j=i+1;
            while (j<intervals.size() && intervals[j][1]<=intervals[i][1])
                j++;
            i = j;
        }
        return count;
    }
};
