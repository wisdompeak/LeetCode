class Solution {
    static bool cmp(vector<int>&a, vector<int>&b)
    {
        return a[1] < b[1];
    }
    
public:
    int findMinArrowShots(vector<vector<int>>& points) 
    {
        sort(points.begin(), points.end(), cmp);
        int i = 0;
        int count = 0;
        while (i<points.size())
        {
            count++;
            int j = i+1;
            while (j<points.size() && points[j][0]<=points[i][1])
                j++;
            i = j;
        }
        return count;        
    }
};
