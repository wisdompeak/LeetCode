class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
        if (nums.size()<3) return -1;
        
        sort(nums.begin(),nums.end());
        
        int diff=INT_MAX;
        int result;
        
        int h1=0;
        int left=0;
        int right=0;
        
        for (h1=0; h1<nums.size(); h1++)
        {
            while (h1>0 && nums[h1]==nums[h1-1])
                h1++;
            
            int left=h1+1;
            int right=nums.size()-1;
            
            int sum=target-nums[h1];
            
            while (left<right)
            {
                //cout<<h1<<left<<right<<endl;
                
                if (abs(nums[h1]+nums[left]+nums[right]-target) < diff)
                {
                    diff = abs(nums[h1]+nums[left]+nums[right]-target);
                    result = nums[h1]+nums[left]+nums[right];
                }

                if (nums[left]+nums[right]==sum)
                {
                    result=target;
                    return result;
                }
                else if (nums[left]+nums[right]<sum)
                    left++;
                else if (nums[left]+nums[right]>sum)
                    right--;
                
                while (left>h1+1 && nums[left]==nums[left-1])
                    left++;
                while (right<nums.size()-1 && nums[right]==nums[right+1])
                    right--;                    
            }
        
        }
        
        return result;
     
    }
};
