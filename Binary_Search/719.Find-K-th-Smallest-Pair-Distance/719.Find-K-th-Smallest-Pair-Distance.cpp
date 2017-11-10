class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) 
    {
        sort(nums.begin(),nums.end());
        int N=nums.size();
        
        int left=nums[1]-nums[0];
        for (int i = 0; i <= N-2; ++i)
            left = min(left, nums[i+1] - nums[i]);
        
        int right=nums[N-1]-nums[0];
        int mid;
        
        while (left<right)
        {
            mid=left+(right-left)/2;
            int count=0;
            for (int i=0; i<N; i++)
            {
                auto pos=upper_bound(nums.begin(),nums.end(), nums[i]+mid);
                count+= pos-1-(nums.begin()+i);
            }
            if (count<k)
                left=mid+1;
            else
                right=mid;
        }
        
        return left;
    }
};
