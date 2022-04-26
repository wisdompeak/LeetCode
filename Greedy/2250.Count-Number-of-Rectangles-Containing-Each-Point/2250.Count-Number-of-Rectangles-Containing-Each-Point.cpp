class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) 
    {
        sort(rectangles.begin(), rectangles.end());
        for (int i=0; i<points.size(); i++)
            points[i].push_back(i);
        sort(points.begin(), points.end());
        
        int j = rectangles.size()-1;
        vector<int>count(101);
        vector<int>rets(points.size());
        for (int i=points.size()-1; i>=0; i--)
        {
            while (j>=0 && rectangles[j][0]>=points[i][0])
            {
                count[rectangles[j][1]]++;
                j--;
            }
            int total = 0;
            for (int h=100; h>=points[i][1]; h--)
                total+=count[h];
            rets[points[i][2]] = total;
        }
        
        return rets;
    }
};
