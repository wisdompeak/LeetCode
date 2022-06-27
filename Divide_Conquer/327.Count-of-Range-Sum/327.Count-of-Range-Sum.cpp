class Solution {
    int result;
    long temp[100005];
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) 
    {
        int n = nums.size();
        vector<long>presum(n+1);
        for (int i=0; i<n; i++)
            presum[i+1] = presum[i]+nums[i];        
        DivideConque(presum,0,n,lower,upper);
        return result;
    }
    
    void DivideConque(vector<long>& nums, int a, int b, int lower, int upper)
    {
        if (a>=b)  return;
        int mid = a+(b-a)/2;
        DivideConque(nums,a,mid,lower,upper);
        DivideConque(nums,mid+1,b,lower,upper);
        
        for (int i=a; i<=mid; i++)
        {
            auto p1 = lower_bound(nums.begin()+mid+1,nums.begin()+b+1,nums[i]+lower);
            auto p2 = upper_bound(nums.begin()+mid+1,nums.begin()+b+1,nums[i]+upper);
            result+=p2-p1;            
        }
        
        inplace_merge(nums.begin()+a, nums.begin()+mid+1, nums.begin()+b+1);
        
        // int i=a, j=mid+1, p = 0;        
        // while (i<=mid && j<=b)
        // {
        //     if (nums[i]<=nums[j])
        //     {
        //         temp[p] = nums[i];
        //         i++;
        //     }                
        //     else
        //     {
        //         temp[p] = nums[j];
        //         j++;
        //     } 
        //     p++;
        // }
        // while (i<=mid)
        // {
        //     temp[p] = nums[i];
        //     i++;
        //     p++;
        // }
        // while (j<=b)
        // {
        //     temp[p] = nums[j];
        //     j++;
        //     p++;
        // }
        // for (int i=0; i<b-a+1; i++)
        //     nums[a+i] = temp[i];
    }
};
