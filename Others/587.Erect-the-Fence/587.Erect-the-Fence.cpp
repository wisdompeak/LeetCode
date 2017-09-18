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
public:
    vector<Point> outerTrees(vector<Point>& points) 
    {                
        if (points.size()<=3) return points;
        
        sort(points.begin(),points.end(),cmp);
        int k;

        vector<Point>Hull_lower(points.size());        
        Hull_lower.push_back(points[0]);
        k=0;
        for (int i=0; i<points.size(); i++)
        {            
            while (k>=2 && crossProduct(Hull_lower[k-2],Hull_lower[k-1],points[i])<0)
                k--;
            Hull_lower[k]=points[i];
            k++;
        }
        Hull_lower.resize(k);
        
        vector<Point>Hull_upper(points.size());
        //Hull_upper[0]=Hull_lower[Hull_lower.size()-1];
        Hull_upper[0]=points.back();
        k=1;
        for (int i=points.size()-1; i>=0; i--)
        {            
            while (k>=2 && crossProduct(Hull_upper[k-2],Hull_upper[k-1],points[i])<0)
                k--;
            Hull_upper[k]=points[i];
            k++;
        }
        Hull_upper.resize(k);        
        
        vector<Point>Hull(Hull_lower.begin(),Hull_lower.end());
        for (int i=1; i<Hull_upper.size(); i++)
            Hull.push_back(Hull_upper[i]);
        
        sort(Hull.begin(), Hull.end(), cmp);
        
        vector<Point>results;
        for (int i=0; i<Hull.size(); i++)
        {
            if (i==0)
                results.push_back(Hull[i]);
            else
            {
                if (Hull[i].x!=results.back().x || Hull[i].y!=results.back().y )
                    results.push_back(Hull[i]);
            }
        }
        return results;        
    }
    
    long long crossProduct(const Point &O, const Point &A, const Point &B) 
    {
        return (long long)(A.x - O.x) * (long long)(B.y - O.y) - (long long)(A.y - O.y) * (long long)(B.x - O.x);
    }    
    
};
