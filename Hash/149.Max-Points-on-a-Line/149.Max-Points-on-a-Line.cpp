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
public:
    int maxPoints(vector<Point>& points) 
    {
        int result=0;
        
        for (int i=0; i<points.size(); i++)
        {
            unordered_map <int,int> Map;
            int countSame=0;
            
            for (int j=0; j<points.size(); j++)
            {
                if (j==i) continue;
                
                if (points[i].x==points[j].x && points[i].y==points[j].y )
                {
                    countSame++;
                    continue;
                }
                
                int flag=0;
                for (auto a:Map)
                {
                    Point p=points[a.first];
                    if ( (long long)(p.y-points[i].y)*(points[j].x-points[i].x) == (long long)(points[j].y-points[i].y)*(p.x-points[i].x) )
                    {
                        flag=1;
                        Map[a.first]++;
                        break;
                    }
                }
                
                if (flag==0)                
                    Map[j]=1;                               
            }
            
            int temp=0;
            for (auto a:Map)
                temp = max(temp,a.second);
            temp+=(countSame+1);
            result=max(result,temp);
        }
        
        return result;
    }
};
