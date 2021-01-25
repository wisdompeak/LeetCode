class Solution {
    static bool cmp(array<int,2>&a, array<int,2>&b)
    {
        if (a[0]!=b[0])
            return a[0] < b[0];
        else
            return a[1] > b[1];
    }
public:
    int minTaps(int n, vector<int>& ranges) 
    {
        vector<array<int,2>>intervals(n+1);
        for (int i=0; i<=n; i++)
            intervals[i] = {i-ranges[i], i+ranges[i]};
        sort(intervals.begin(), intervals.end(), cmp);

        if (intervals[0][0]>0) return -1;

        int i = 0;
        int far = 0;
        int count = 0;
        while (i<intervals.size())
        {                        
            count+=1;
            int nextFar = far;
            while (i<intervals.size() && intervals[i][0]<=far)
            {
                nextFar = max(nextFar, intervals[i][1]);
                i++;
            }            
            if (nextFar >= n)
                return count;
            if (nextFar == far)
                return -1;
            far = nextFar;
        }

        return -1;
    }
};
