class Solution {
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) 
    {
        double pi = 3.1415926;
        vector<double>angles;
        
        int self = 0;
        
        for (auto p: points)
        {
            double x = p[0]-location[0];
            double y = p[1]-location[1];
            
            if (x==0 && y==0)
            {
                self++;
                continue;
            }
            
            double degree = atan2(y, x) + pi;    
            // double degree;
            // if (x==0) 
            // {
            //     if (y>0)
            //         degree = pi/2;
            //     else
            //         degree = pi*3/2;
            // }                
            // else
            // {                
            //     degree = atan(y/x);            
            //     if (x<0 && y>=0) degree += pi;
            //     else if (x<0 && y<0) degree += pi;
            //     else if (x>0 && y<0) degree += pi*2;
            // }
            
            angles.push_back(degree);            
        }
        
        sort(angles.begin(), angles.end());        
       
        int n = angles.size();
        for (int i=0; i<n; i++)
            angles.push_back(angles[i]+2*pi);
                
        int ret = 0;
        int j = 0;
        for (int i=0; i<2*n; i++)
        {            
            while (j<2*n && angles[j]-angles[i]<=angle*pi/180+0.0000001)
                j++;
            ret = max(ret, j-i);
        }
        return ret+self;
    }
};
