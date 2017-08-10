class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) 
    {
        int x1,x2;
        int count1=0,count2=0;
        
        for (int i=0; i<nums.size(); i++)
        {
            if (count1>0 && nums[i]==x1)
            {
                count1++;
            }
            else if (count2>0 && nums[i]==x2)
            {
                count2++;
            }
            else if (count1==0)
            {
                x1=nums[i];
                count1=1;
            }
            else if (count2==0)
            {
                x2=nums[i];
                count2=1;
            }
            else if (nums[i]!=x1 && nums[i]!=x2)
            {
                count1--;
                count2--;
            }            
        }
                
        vector<int>results;
        count1=0;
        count2=0;
        for (int i=0; i<nums.size(); i++)
        {
            if (nums[i]==x1) count1++;
            if (nums[i]==x2) count2++;
        }  
        if (count1>nums.size()/3) results.push_back(x1);
        if (x1!=x2 && count2>nums.size()/3) results.push_back(x2);
        
        return results;
    }
};
