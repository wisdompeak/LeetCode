class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) 
    {
        sort(nums.begin(), nums.end());
        int left = 0, right = INT_MAX;
        while (left < right)
        {
            int mid = left + (right-left)/2;
            if (isOK(nums, p, mid))
                right = mid;
            else
                left = mid+1;
        }
        return left;
    }
    
    bool isOK(vector<int>& nums, int p, int diff)
    {
        int n = nums.size();
        int count = 0;
        for (int i=0; i<n; i++)
        {
            int j = i;
            while (j<n && nums[j]-nums[i]<=diff)
                j++;
            count += (j-i)/2;
            if (j-i==1)
                i = j-1;
            else if ((j-i)%2==0)
                i = j-1;
            else
                i = j-2;
        }
        return (count >= p);
    }
};
