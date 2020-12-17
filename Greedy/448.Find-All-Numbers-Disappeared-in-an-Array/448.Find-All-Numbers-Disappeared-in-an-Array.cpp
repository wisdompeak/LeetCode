class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int> &nums) 
    {
        nums.insert(nums.begin(),0);
        vector<int>results;
        
        int i = 1;
        while (i<nums.size())
        {
            if (nums[i]==i || nums[nums[i]]==nums[i])             
                i++;            
            else            
                swap(nums[i],nums[nums[i]]);            
        }
        
        for (int i=1; i<nums.size(); i++)
            if (nums[i]!=i) results.push_back(i);
            
        return results;        
    }
};
