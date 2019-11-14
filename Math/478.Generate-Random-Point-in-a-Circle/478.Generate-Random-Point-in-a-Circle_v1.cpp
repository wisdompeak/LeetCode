class Solution {
    double R, x0, y0;
public:
    Solution(double radius, double x_center, double y_center) 
    {
        R = radius;
        x0 = x_center;
        y0 = y_center;
    }
    
    vector<double> randPoint() 
    {
        double r1 = (double)rand()/RAND_MAX;  // [0,1) 
        double x = r1*2*R-R+x0;
        double r2 = (double)rand()/RAND_MAX; 
        double y = r2*2*R-R+y0;
        
        if ((x-x0)*(x-x0)+(y-y0)*(y-y0)<=R*R)
            return {x,y};
        else
            return randPoint();
    }
};
