class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int>left(n);
        vector<int>right(n);
        vector<int>arr;
        
        for (int i=0; i<n; i++)
        {
            if (arr.size()==0 || nums[i]>arr.back())
            {
                arr.push_back(nums[i]);
                left[i] = arr.size();
            }                
            else
            {
                auto iter = lower_bound(arr.begin(), arr.end(), nums[i]);
                *iter = nums[i];
                left[i] = iter-arr.begin()+1;
            }
        }
        for (auto x: left) cout<<x<<" "; cout<<endl;

        arr.clear();
        for (int i=n-1; i>=0; i--)
        {
            if (arr.size()==0 || nums[i]>arr.back())
            {
                arr.push_back(nums[i]);
                right[i] = arr.size();
            }                
            else
            {
                auto iter = lower_bound(arr.begin(), arr.end(), nums[i]);
                *iter = nums[i];
                right[i] = iter-arr.begin()+1;
            }
        }
        
        int count = 0;
        for (int i=0; i<n; i++)
        {
            if (left[i]>=2 && right[i]>=2)
                count = max(count, left[i]+right[i]-1);
        }
        return n-count;

    }
};
