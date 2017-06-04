class Solution {
    
private:
    static bool cmp1(int a, int b)
    {
        return a<b;
    }
    static bool cmp2(int a, int b)
    {
        return a<b;
    }    
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        vector<int>results;
        
        auto pos1 = lower_bound(nums.begin(),nums.end(),target,cmp1);
        if (pos1!=nums.end() && *pos1==target) 
            results.push_back(pos1-nums.begin());
        else
            results.push_back(-1);
            
        auto pos2 = upper_bound(nums.begin(),nums.end(),target,cmp2);
        
        if (pos2-nums.begin()-1>=0 && *(pos2-1)==target) 
            results.push_back(pos2-nums.begin()-1);
        else
            results.push_back(-1);            
        
        return results;
    }
};
