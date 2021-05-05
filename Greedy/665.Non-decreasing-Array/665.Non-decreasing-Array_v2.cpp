class Solution {
public:
    bool checkPossibility(vector<int>& nums) 
    {
        int a = -1, b = -1;
        for (int i=1; i<nums.size(); i++)
        {
            if (nums[i-1]>nums[i])
            {
                a = i-1;
                b = i;
            }
        }
        if (a==-1) return true;
        
        int flag = 1;
        for (int i=1; i<nums.size(); i++)
        {
            if (i==a) continue;
            else if (i==a+1)
            {
                if (i-2>=0 && nums[i-2]>nums[i])
                {
                    flag = false;
                    break;                    
                }                
            }
            else if (nums[i-1]>nums[i])
            {
                flag = false;
                break;
            }                
        }
        if (flag) return true;
        
        flag = 1;
        for (int i=1; i<nums.size(); i++)
        {
            if (i==b) continue;
            else if (i==b+1)
            {
                if (i-2>=0 && nums[i-2]>nums[i])
                {
                    flag = false;
                    break;                    
                }  
            }
            else if (nums[i-1]>nums[i])
            {
                flag = false;
                break;
            }                
        }
        if (flag) return true;
        return false;
    }
};
