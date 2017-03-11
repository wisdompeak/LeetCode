class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) 
    {
        int count=0;
        sort(nums.begin(),nums.end());
        
        for (int a=0; a<nums.size(); a++)
        {
            int sum=target-nums[a];
            int left=a+1;
            int right=nums.size()-1;
            
            while (left<right)
            {
                if (nums[left]+nums[right]<sum)
                {
                    count+=right-left;
                    left++;
                }
                else
                {
                    right--;
                }
            }
            
            //cout<<count<<endl;
        }
        
        return count;
        
    }
};
