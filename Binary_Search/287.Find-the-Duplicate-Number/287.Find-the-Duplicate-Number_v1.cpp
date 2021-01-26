class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
        int n = nums.size();
        int left=1;
        int right=n-1;        
        
        while (left<right)
        {
            int k = left+(right-left)/2;
            int count=0;
            for (auto x: nums)
                if (x <= k) count++;
            
            if (count > k)
                right = k;
            else
                left = k+1;
        }        
        return left;        
    }
};
