class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) 
    {
        vector<int>diff(n+2,0);
        for (auto p: bookings)
        {
            diff[p[0]]+=p[2];
            diff[p[1]+1]-=p[2];
        }
        vector<int>results;
        int cur = 0;
        for (int i=1; i<=n; i++)
        {
            cur += diff[i];
            results.push_back(cur);
        }
        return results;
        
    }
};
