class Solution {
    int count=0;
    int Lower;
    int Upper;
    static bool cmp1(long a, long b)
    {
        return a<b;
    }
    static bool cmp2(long a, long b)
    {
        return a<=b;
    }    
public:
    long countRangeSum(vector<int>& nums, int lower, int upper) 
    {
        Lower=lower;
        Upper=upper;
        nums.insert(nums.begin(),0);
        vector<long>sums(nums.size(),0);
        for (int i=1; i<sums.size(); i++)
            sums[i] = sums[i-1]+nums[i];
        
        DivideConque(sums,0,sums.size()-1);
        return count;
    }
    
    void DivideConque(vector<long>&sums, int start, int end)
    {
        if (start==end) return;
        
        int mid=start+(end-start)/2;
        DivideConque(sums,start,mid);
        DivideConque(sums,mid+1,end);
        
        for (int i=start; i<=mid; i++)
        {
            auto pos1 = lower_bound(sums.begin()+mid+1,sums.begin()+end+1,sums[i]+Lower,cmp1);
            auto pos2 = lower_bound(sums.begin()+mid+1,sums.begin()+end+1,sums[i]+Upper,cmp2);   
            count+=pos2-pos1;            
        }
        
        sort(sums.begin()+start,sums.begin()+end+1);
    }
};
