class Solution {
public:
    bool canPartition(vector<int>& nums) 
    {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if (sum%2!=0) return false;
        
        unordered_set<int>dp;
        dp.insert(0);

        for (auto x: nums)
        {
            vector<int>temp;
            for (auto s: dp)
            {
                if (s+x==sum/2) return true;
                temp.push_back(s+x);
            }
            for (auto a: temp)
                dp.insert(a);
        }
        return false;
    }
};
