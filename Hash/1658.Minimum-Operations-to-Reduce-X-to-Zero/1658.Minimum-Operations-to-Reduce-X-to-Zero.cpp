class Solution {
public:
    int minOperations(vector<int>& nums, int x) 
    {
        int n = nums.size();
        unordered_map<int,int>Map;
        Map[0] = 0;
        int sum = 0;
        for (int i=0; i<nums.size(); i++)
        {
            sum += nums[i];
            if (Map.find(sum)==Map.end())
                Map[sum] = i+1;
        }
        
        int ret = INT_MAX;
        if (Map.find(x)!=Map.end())
            ret = Map[x];
        sum = 0;        
        for (int i=n-1; i>=0; i--)
        {
            sum += nums[i];
            if (Map.find(x-sum)!=Map.end() && Map[x-sum]<=i)
                ret = min(ret, Map[x-sum] + (n-i));
        }
        
        if (ret==INT_MAX)
            return -1;
        else
            return ret;        
    }
};
