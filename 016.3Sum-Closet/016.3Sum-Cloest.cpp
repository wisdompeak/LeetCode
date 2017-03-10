class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
		sort(nums.begin(),nums.end());
		int diff=INT_MAX;

		for (int a=0; a<nums.size(); a++)
		{
			int left=a+1;
			int right=nums.size()-1;
			int sum=target-nums[a];

			while (left<right)
			{
				if (abs(nums[left]+nums[right]-sum)<diff)
				{
					diff=abs(nums[left]+nums[right]-sum);
					result=nums[a]+nums[left]+nums[right];
				}

				if (nums[left]+nums[right]<sum)
					left++;
				else
					right--;
			}

			while (a+1<nums.size() && nums[a+1]==nums[a])
				a++;
			a++;

		}		

		return result;             

    }

};


