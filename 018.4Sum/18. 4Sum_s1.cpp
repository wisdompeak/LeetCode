class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        vector<vector<int>>results;
        if (nums.size()<4) return results;
        sort(nums.begin(),nums.end());
        
        for (int h1=0; h1<nums.size(); h1++)
        {
            if (nums[h1]*4>target) break;
            
            for (int h2=h1+1; h2<nums.size(); h2++)
            {
                if (nums[h1]+3*nums[h2]>target) break;
                
                int left=h2+1;
                if (nums[h1]+nums[h2]+2*nums[left]>target) break;
                
                int right=nums.size()-1;
                if (nums[h1]+nums[h2]+2*nums[right]<target) continue;
                
                while (left<right)
                {
                    if (nums[h1]+nums[h2]+nums[left]+nums[right]==target)
                    {
                        results.push_back({nums[h1],nums[h2],nums[left],nums[right]});
                        left++;
                        right--;
                        
                        while (left<right && nums[left]==nums[left-1])
                            left++;
                        while (left<right && nums[right]==nums[right+1])
                            right--;
                    }
                    else if (nums[h1]+nums[h2]+nums[left]+nums[right]>target)
                        right--;
                    else if (nums[h1]+nums[h2]+nums[left]+nums[right]<target)
                        left++;
                }
                
                while (h2+1<nums.size() && nums[h2+1]==nums[h2])
                    h2++;
            }
            
            while (h1+1<nums.size() && nums[h1+1]==nums[h1])
                h1++;            
            
        }
        
        return results;
        
    }
};
