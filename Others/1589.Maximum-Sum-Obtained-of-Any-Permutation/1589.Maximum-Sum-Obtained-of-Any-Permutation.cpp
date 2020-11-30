class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) 
    {
        int n = nums.size();
        vector<int>diff(n+1);
        for (auto request: requests)
        {
            diff[request[0]]+=1;
            diff[request[1]+1]-=1;
        }
        int sum = 0;
        vector<int>count(n,0);
        for (int i=0; i<n; i++)
        {
            sum += diff[i];
            count[i] = sum;
        }
        sort(count.begin(), count.end());
        sort(nums.begin(), nums.end());
        
        long ret = 0;
        long M = 1e9+7;
        for (int i=0; i<n; i++)
            ret = (ret + (long)nums[i]*long(count[i]))%M;
        return ret;        
    }
};
