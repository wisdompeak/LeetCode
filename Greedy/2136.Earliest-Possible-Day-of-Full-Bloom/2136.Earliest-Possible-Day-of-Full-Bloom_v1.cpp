class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) 
    {
        int n = plantTime.size();
        vector<vector<int>>time(n);
        for (int i=0; i<n; i++)
        {
            time[i] = {plantTime[i], -growTime[i]};            
        }
        sort(time.begin(), time.end(), [](vector<int>&a, vector<int>&b){return a[1]<b[1];});
        
        int left = 1, right = INT_MAX/2;
        while (left < right)
        {
            int mid = left+(right-left)/2;
            if (checkOK(mid, time))
                right = mid;
            else
                left = mid+1;
        }
        return left;        
    }
    
    bool checkOK(int T, vector<vector<int>>&time)
    {
        int n = time.size();
        int days = 0;
        
        for (int i=0; i<n; i++)
        {
            days += time[i][0];
            
            if (days > T+time[i][1])
            {
                return false;
            }
        }        
        return true;      
    }
};
