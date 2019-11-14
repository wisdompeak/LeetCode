class Solution {
    double R;
    double x0;
    double y0;
public:
    double PI = 3.1415926;
    Solution(double radius, double x_center, double y_center) 
    {
        R = radius;
        x0 = x_center;
        y0 = y_center;
    }
    
    vector<double> randPoint() 
    {        
        double r = (double)rand()/RAND_MAX;
        r = sqrt(r)*R;
        double theta = (double)rand()/RAND_MAX*PI*2;
        double x = x0+r*sin(theta);
        double y = y0+r*cos(theta);
        return {x,y};        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj.randPoint();
 */
