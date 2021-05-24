class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) 
    {
        int n = dist.size();
        if (hour <= n-1 ) return -1;
        
        int low = 1, high = 1e7;
        
        while (low < high)
        {
            int mid = low+(high-low)/2;
            double time = helper(dist, mid);
            if (time > hour)
                low = mid+1;
            else
                high = mid;
        }
        
        return low;       
    }
    
    double helper(vector<int>&dist, int speed)
    {
        double time = 0;
        for (int i=0; i<dist.size()-1; i++)
        {
            time += (dist[i]-1)/speed+1;
        }
        time += dist.back()*1.0/speed;
        return time;
    }

};
