using LL = long long;
class Solution {
    static bool cmp(vector<int>&a, vector<int>&b)
    {
        if (a[1]!=b[1]) 
            return a[1] < b[1];
        else
            return a[0] < b[0];
    }
public:
    int minimumFinishTime(vector<vector<int>>& tires, int changeTime, int numLaps) 
    {
        sort(tires.begin(), tires.end(), cmp);
        vector<vector<int>>newTires;
        for (int i=0; i<tires.size(); i++)
        {                        
            if (!newTires.empty() && newTires.back()[0] <= tires[i][0])
                continue;
            newTires.push_back(tires[i]);                
        }
        
        vector<double>minTime(min(20, numLaps+1), DBL_MAX);
        for (int x=1; x<minTime.size(); x++)
        {
            for (int i=0; i<newTires.size(); i++)
                minTime[x] = min(minTime[x],  cal(newTires[i],x));             
        }
                
        vector<double>dp(numLaps+1, DBL_MAX);
        dp[0] = 0;
        for (int i=1; i<=numLaps; i++)
            for (int j=i-1; i-j<20 && j>=0; j--)
            {
                dp[i] = min(dp[i], dp[j]+minTime[i-j] + (j==0?0:changeTime));
            }                
        
        return dp[numLaps];
    }
        
    double cal(vector<int>tire, int x)
    {
        double f= tire[0], r = tire[1];
        double ret = f*(pow(r, x)-1)/(r-1);        
        return ret;
        
    }
};
