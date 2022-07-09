class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) 
    {
        int m = passengers.size();
        
        sort(buses.begin(), buses.end());
        sort(passengers.begin(), passengers.end());
        
        int j = 0;
        int ret = -1;        
        
        for (int i=0; i<buses.size(); i++)
        {
            int cap = capacity;        
            while (j<m && passengers[j]<=buses[i] && cap>0)
            {
                cap--;
                if (j>=1 && passengers[j]-1 != passengers[j-1])
                    ret = passengers[j]-1;
                else if (j==0)
                    ret = passengers[j]-1;
                j++;
            }
            
            if (cap > 0)
            {
                if (j>=1 && passengers[j-1]!=buses[i])
                    ret = buses[i];
                else if (j==0)
                    ret = buses[i];                    
            }
        }
        
        return ret;
    }
};
