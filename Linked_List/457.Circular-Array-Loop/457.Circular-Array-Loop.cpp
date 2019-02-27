class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) 
    {
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0) continue; 
            
            int slow = i, fast = i, dir = nums[i];
            do {
                slow = advanceBy(1, slow, nums, dir);
                fast = advanceBy(2, fast, nums, dir);
            } while (slow >= 0 && fast >= 0 && slow != fast);
                
            if (slow >= 0 && fast >= 0 && slow != advanceBy(1, slow, nums, dir)) 
                return true;
            
            slow = i;
            while (advanceBy(1, slow, nums, dir)>=0)
            {
                int tmp = advanceBy(1, slow, nums, dir);
                nums[slow] = 0;
                slow = tmp;
            }
        }
        return false;
    }
    
    int advanceBy(int step, int j, vector<int>& nums, int dir) 
    {
        int n = nums.size();
        for (int k=0; k<step; k++) 
        {
            j = (j + nums[j] + n) % n;
            j = (j + n) % n;
            if (nums[j] * dir <= 0)
                return -1;
        }
        return j;
    }
};
