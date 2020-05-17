class Solution {
public:
    int numPoints(vector<vector<int>>& points, int r) 
    {
        double R = r+0.0001;
        double x,y;
        int ret = 0;
        
        for (int i=0; i<points.size(); i++)
            for (int j=i+1; j<points.size(); j++)
            {
                double x1 = points[i][0];
                double y1 = points[i][1];
                double x2 = points[j][0];
                double y2 = points[j][1];
                double x0 = (x1+x2)/2;
                double y0 = (y1+y2)/2;
                double d = sqrt(r*r*1.0 - ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))/4);
                int count1=0, count2=0;
                double a,b;
                                
                b = x1==x2 ? 0: 1.0/sqrt((y1-y2)*(y1-y2)/(x1-x2)/(x1-x2) + 1);
                a = x1==x2 ? 1: -(y1-y2)/(x1-x2)*b;
                x = x0+a*d;
                y = y0+b*d;
                                                                
                for (int k=0; k<points.size(); k++)
                    if ((points[k][0]-x)*(points[k][0]-x)+(points[k][1]-y)*(points[k][1]-y)<=R*R)
                        count1++;
                
                b = x1==x2 ? 0: -1.0/sqrt((y1-y2)*(y1-y2)/(x1-x2)/(x1-x2) + 1);
                a = x1==x2 ? -1: -(y1-y2)/(x1-x2)*b;
                x = x0+a*d;
                y = y0+b*d;
                                                                
                for (int k=0; k<points.size(); k++)
                    if ((points[k][0]-x)*(points[k][0]-x)+(points[k][1]-y)*(points[k][1]-y)<=R*R)
                        count2++;
                
                ret = max(ret, max(count1, count2));
            }
        
        return max(1,ret);
    }
};
