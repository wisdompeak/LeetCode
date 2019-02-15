class Solution {
    int result;
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) 
    {
        if (nums.size()==0) return 0;
        result = 0;
        vector<long>Nums(nums.size());
        Nums[0]=nums[0];
        for (int i=1; i<nums.size(); i++)
            Nums[i]=Nums[i-1]+nums[i];
        DivideConque(Nums,0,Nums.size()-1,lower,upper);
        return result;
    }
    
    void DivideConque(vector<long>& nums, int start, int end, int lower, int upper)
    {
        if (start==end) 
        {
            if (nums[start]>=lower && nums[end]<=upper)
                result+=1;
            return;
        }
        int mid = start+(end-start)/2;
        DivideConque(nums,start,mid,lower,upper);
        DivideConque(nums,mid+1,end,lower,upper);
        
        for (int i=start; i<=mid; i++)
        {
            auto p1 = lower_bound(nums.begin()+mid+1,nums.begin()+end+1,nums[i]+lower);
            auto p2 = upper_bound(nums.begin()+mid+1,nums.begin()+end+1,nums[i]+upper);
            result+=p2-p1;            
        }
        
        sort(nums.begin()+start,nums.begin()+end+1);
    }
};
