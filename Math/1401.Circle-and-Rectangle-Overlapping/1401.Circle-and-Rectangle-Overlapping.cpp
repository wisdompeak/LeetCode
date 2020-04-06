class Solution {
public:
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) 
    {
        double cx = (x2+x1)*1.0/2, cy = (y2+y1)*1.0/2;
        double hx = (x2-x1)*1.0/2, hy = (y2-y1)*1.0/2;
        double px = x_center, py = y_center;
        
        double vx = abs(px-cx), vy = abs(py-cy);
        double ux = max(vx-hx, 0.0), uy = max(vy-hy,0.0);
        
        return ux*ux+uy*uy <= radius*radius;      
    }
};
