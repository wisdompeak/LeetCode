class Solution {
    static bool cmp(pair<int,int>a, pair<int,int>b)
    {
        return a.second<b.second;
    }
public:
    int findMinArrowShots(vector<pair<int, int>>& points) 
    {
        sort(points.begin(),points.end(),cmp);
        
        int j=0;
        int count=0;
        while (j<points.size())
        {            
            int right=points[j].second;
            while (j<points.size() && points[j].first<=right)
                j++;
            count++;
        }
        
        return count;
    }
};
