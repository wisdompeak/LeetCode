class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) 
    {
        if (nums.size()<3) return 0;
        sort(nums.begin(),nums.end());
        
        int result=0;
        for (int a=0; a<nums.size(); a++)
        {
            int left=a+1;
            int right=nums.size()-1;
            int sum = target-nums[a];
            
            while (left<right)
            {
                //cout<<a<<left<<right<<" "<<sum<<" ";
                
                if (nums[left]+nums[right]<sum)
                {
                    result+=right-left;
                    left++;
                }
                else if (nums[left]+nums[right]>=sum)
                    right--;
                
                //cout<<result<<endl;
            }
        }
        
        return result;
        
    }
};
