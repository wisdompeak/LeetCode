class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& nums, int K) 
    {
        double left = 0;
        double right = 1;
        double mid;
        
        while (left < right)
        {
            mid = (left+right)/2;
            
            int count = 0;
            for (int i=0; i<nums.size(); i++)
            {
                auto pos = lower_bound(nums.begin(),nums.end(), nums[i]*1.0/mid);
                count += nums.end()-pos;
            }
            
            if (count < K)
                left = mid; // next time, mid >left
            else if (count > K)
                right = mid;
            else
                break; 
        }
        
        cout<<mid<<endl;
        
        vector<int>ret;
        double ans = 0;
        
        for (int i=0; i<nums.size(); i++)
        {
            auto pos = lower_bound(nums.begin(), nums.end(), nums[i]*1.0/mid);
            int j = pos-nums.begin();
            if (pos!=nums.end() && nums[i]*1.0/nums[j] > ans)
            {
                ans = nums[i]*1.0/nums[j];
                ret = {nums[i], nums[j]};
            }
        }
        
        return ret;
        
    }
};
