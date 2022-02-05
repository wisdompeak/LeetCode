class Solution {
public:
    double equalizeWater(vector<int>& buckets, int loss) 
    {
        double left = 0;
        double right = 0;
        for (int x: buckets)
            right += x;
        
        while (abs(right-left)>1e-5)
        {
            double mid = (left+right)/2;
            double s1 = 0;
            double s2 = 0;
            for (int x: buckets)
            {
                if (x>mid)
                    s1 += x-mid;
                else
                    s2 += mid -x;
            }
                        
            if (s1*(100-loss)*0.01 > s2)
                left = mid;
            else
                right = mid;
        }
        
        return left;
        
    }
};
