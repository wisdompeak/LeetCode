class Solution {
public:
    int maxWidthRamp(vector<int>& nums) 
    {
        vector<int>q;
        vector<int>idx;
        int result = 0;
        
        for (int i=0; i<nums.size();i++)
        {           
            if (q.size()==0 || q.size()>0 && nums[i]<q.back())
            {
                q.push_back(nums[i]);
                idx.push_back(i);
            }
            else
            {
                auto it = upper_bound(q.rbegin(),q.rend(),nums[i]);
                int k = it-q.rbegin();
                k = q.size()-1-k + 1;
                result = max(result, i-idx[k]);                
            }            
        }        
        return result;
    }
};
