class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) 
    {        
        sort(points.begin(), points.end(), [](vector<int>&a, vector<int>&b){
            if (a[0]==b[0]) return a[1]>b[1];
            else return a[0]<b[0];
        });
        int n = points.size();
        int ret = 0;
        
        for (int i=0; i<n; i++)
        {
            int lower = INT_MIN;
            int upper = points[i][1];
            
            for (int j=i+1; j<n; j++)
            {
                if (points[j][1] > upper) continue;
                if (points[j][1] > lower && points[j][1] <= upper)
                    ret++;
                lower = max(lower, points[j][1]);
            }
        }
        
        return ret;
    }
};
