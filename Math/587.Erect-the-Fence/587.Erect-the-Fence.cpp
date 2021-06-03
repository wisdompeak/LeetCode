/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
    static bool cmp(Point a, Point b)
    {
        if (a.x==b.x)
            return a.y<b.y;
        else
            return a.x<b.x;
    }
    static bool eqn(Point a, Point b)
    {
        
        return (a.x==b.x)&&(a.y==b.y);
    }    
        
public:
    vector<Point> outerTrees(vector<Point>& points) 
    {
        sort(points.begin(),points.end(),cmp);
        
        vector<Point>down;
        down.push_back(points[0]);
        for (int i=1; i<points.size(); i++)
        {
            while (down.size()>=2 && crossProduct(down[down.size()-2],down.back(),points[i])<0)
                down.pop_back();
            down.push_back(points[i]);
        }
        
        vector<Point>up;
        up.push_back(points.back());
        for (int i=points.size()-1; i>=0; i--)
        {
            while (up.size()>=2 && crossProduct(up[up.size()-2],up.back(),points[i])<0)
                up.pop_back();
            up.push_back(points[i]);
        }
        
        vector<Point>results(down.begin(),down.end());
        for (int i=0; i<up.size();i++)
            results.push_back(up[i]);
        
        sort(results.begin(),results.end(),cmp);
        results.erase(unique(results.begin(),results.end(),eqn),results.end());
        return results;        
    }
    
    long long crossProduct(Point A, Point B, Point C)
    {
        return (long long)(B.x - A.x) * (long long)(C.y - B.y) - (long long)(B.y - A.y) * (long long)(C.x - B.x);
    }
};
