class Solution {
public:
    int numberOfGoodPartitions(vector<int>& nums) 
    {
        int n = nums.size();
        unordered_map<int,int>right;
        for (int i=0; i<n; i++)
            right[nums[i]] = i;
        unordered_map<int,int>left;
        for (int i=n-1; i>=0; i--)
            left[nums[i]] = i;
        
        vector<int>diff(n);
        for (auto [k,v]: left)
        {
            diff[left[k]]+=1;
            diff[right[k]]-=1;
        }
    
        int count = 0;
        int sum = 0;
        for (int i=0; i<n; i++)
        {
            sum += diff[i];
            if (sum==0)
                count++;            
        }
        
        int ret = 1;
        int M = 1e9+7;
        for (int i=0; i<count-1; i++)
            ret = ret*2%M;
        
        return ret;
        
    }
};
