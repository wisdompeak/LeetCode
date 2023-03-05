using LL = long long;
LL M = 1e9+7;
class Solution {    
public:
    int countWays(vector<vector<int>>& ranges) 
    {
        sort(ranges.begin(), ranges.end());
        int n = ranges.size();
        LL ret = 1;
        
        for (int i=0; i<n; i++)
        {
            int far = ranges[i][1];
            int j = i;
            while (j<n && ranges[j][0]<=far)
            {
                far = max(far, ranges[j][1]);
                j++;
            }
            ret = ret*2%M;
            i = j-1;
        }
            
        return ret;
    }
};
