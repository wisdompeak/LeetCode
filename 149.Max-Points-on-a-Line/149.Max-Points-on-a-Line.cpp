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
        int result = 0;
        
        for (int i=0; i<points.size(); i++)
        {
            map <pair<int,int>,int> Map;

            int countSame = 0;
            int countVertical = 0;
            
            for (int j=0; j<points.size(); j++)
            {
                if (j==i) continue;
                
                if (points[j].x==points[i].x && points[j].y==points[i].y )
                {
                    countSame++;
                    continue;
                }
                
                if (points[j].x==points[i].x)
                {
                    countVertical++;
                    continue;
                }                
                
                int flag = 1;
                
                for (auto a:Map)
                {
                    Point p;
                    p.x = a.first.first;
                    p.y = a.first.second;
                    
                    if ( (long long)(p.y-points[i].y)*(points[j].x-points[i].x) == (long long)(points[j].y-points[i].y)*(p.x-points[i].x) )
                    {
                        Map[{p.x,p.y}]++;
                        flag = 0;
                        break;
                    }
                }
                if (flag == 1)
                    Map[{points[j].x,points[j].y}]=1;
            }
            
            int temp=0;
            for (auto a:Map)
            {
                temp = max(temp, a.second);
            }

            temp = max(temp,countVertical);

            result = max(result,temp+countSame+1);
            
        }
        
        return result;    
    }
};
