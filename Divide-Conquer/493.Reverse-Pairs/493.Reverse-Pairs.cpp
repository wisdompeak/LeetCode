class Solution {
    int result=0;
public:
    int reversePairs(vector<int>& nums) 
    {
        if (nums.size()<=1) return 0;
        vector<long>Nums;
        for (auto a:nums)
            Nums.push_back(long(a));
        divideConquer(Nums,0,nums.size()-1);
        return result;        
    }
    
    void divideConquer(vector<long>&nums, int a, int b)
    {
        if (a==b) return;
        
        int mid = a+(b-a)/2;
        divideConquer(nums,a,mid);
        divideConquer(nums,mid+1,b);
        
        for (int i=mid+1; i<=b; i++)
        {
            auto pos=upper_bound(nums.begin()+a,nums.begin()+mid+1,2*nums[i]);
            result+= nums.begin()+mid+1-pos;
        }
        
        //sort(nums.begin()+a,nums.begin()+b+1);            
        MergeSort(nums,a,mid,b);
    }
    
    void MergeSort(vector<long>&nums, int a, int mid, int b)
    {
        vector<int>array(b-a+1);
        int p1=a;
        int p2=mid+1;
        for (int i=0; i<b-a+1; i++)
        {
            if (p1>mid)
            {
                array[i]=nums[p2];
                p2++;
            }
            else if (p2>b)
            {
                array[i]=nums[p1];
                p1++;
            }
            else if (nums[p1]<=nums[p2])
            {
                array[i]=nums[p1];
                p1++;
            }
            else
            {
                array[i]=nums[p2];
                p2++;
            }                
        }
        for (int i=0; i<array.size(); i++)
            nums[i+a]=array[i];        
    }
};
