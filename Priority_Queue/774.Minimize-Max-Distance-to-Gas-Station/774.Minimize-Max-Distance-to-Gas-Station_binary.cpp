class Solution {
public:
    double minmaxGasDist(vector<int>& stations, int K) 
    {
        double left = 0;
        double right = 0;
        for (int i=1; i<stations.size(); i++)
            right = fmax(right,stations[i]-stations[i-1]);
        
        double mid;
        while (right-left>1e-6)
        {
            mid = (right+left)/2;
            int count = 0;
            for (int i=1; i<stations.size(); i++)
            {
                double k = (stations[i]-stations[i-1])/mid;
                count+=  ceil(k)-1;               
            }
            if (count>K)
                left = mid;
            else
                right = mid;            
        }
        return mid;
    }
};
