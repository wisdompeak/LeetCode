class Solution {
public:
    int rob(vector<int>& nums) 
    {
        if (nums.size()==0) return 0;
        if (nums.size()==1) return nums[0];
        
        int Rob = 0;
        int noRob = nums[0];        
        for (int i=2; i<nums.size()-1; i++)
        {
            int noRob_temp = noRob;
            int Rob_temp = Rob;
            
            Rob = noRob_temp + nums[i];
            noRob = max(Rob_temp,noRob_temp);
        }
        int result1 = max(Rob,noRob);
        
        Rob = nums[1];
        noRob = 0;
        for (int i=2; i<nums.size(); i++)
        {
            int noRob_temp = noRob;
            int Rob_temp = Rob;
            
            Rob = noRob_temp + nums[i];
            noRob = max(Rob_temp,noRob_temp);
        }
        int result2 = max(Rob,noRob);
        
        return max(result1,result2);
    }
};
