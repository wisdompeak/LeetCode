class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) 
    {
        int left = nums[0], right = 1e9;
        while (left < right)
        {
            int mid = left+(right-left)/2;
            
            long long buff = 0;
            int flag = true;
            for (int i=0; i<nums.size(); i++)
            {
                int x = nums[i];
                if (x > mid)
                    buff -= (x-mid);
                else
                    buff += (mid-x);                
                if (buff < 0)
                {
                    flag = false;
                    break;
                }
            }
            
            if (flag)
                right = mid;
            else
                left = mid+1;
        }
        
        return left;
        
    }
};
