class Solution {
    static bool cmp(vector<int>a, vector<int>b)
    {
        if (a[1]==b[1])
            return a[0]>b[0];
        else
            return a[1]<b[1];
    }
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) 
    {
        sort(intervals.begin(),intervals.end(),cmp);
        int start=intervals[0][1]-1;
        int end=intervals[0][1];
        int count=2;

        for (int i=1; i<intervals.size(); i++)
        {
            if (intervals[i][1]==intervals[i-1][1])
                continue;
            
            if (intervals[i][0]<=start)
                continue;                
            else if (intervals[i][0]<=end)
            {
                count+=1;
                start=end;
                end=intervals[i][1];
            }
            else
            {
                count+=2;
                start=intervals[i][1]-1;
                end=intervals[i][1];
            }                
        }
        
        return count;
    }
};
