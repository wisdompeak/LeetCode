class Solution {
 +    static bool cmp(int a, int b)
 +    {
 +        return (a<b);
 +    }
 +    
 +public:
 +    vector<int> countSmaller(vector<int>& nums) 
 +    {
 +        int N=nums.size();
 +        
 +        vector<int>count(N,0);
 +        vector<int>sortedNums(nums);
 +        
 +        if (N<=1) return count;
 +        
 +        DivideConquer(nums,sortedNums,count,0,N-1);
 +        // 0表示起点，N-1表示终点
 +        
 +        return count;
 +    }
 +    
 +    void DivideConquer(vector<int>& nums, vector<int>& sortedNums, vector<int>& count, int start, int end)
 +    {
 +        if (start==end) //如果需要处理的元素只要一个，显然number of smaller elements to the right是0
 +        {
 +            count[start]=0;
 +            return;
 +        }
 +        
 +        // 如果需要处理的元素有多个，则折半分治处理。注意：分治处理后的两段元素都是有序的。
 +        int mid = start+(end-start)/2;
 +        DivideConquer(nums,sortedNums,count,start,mid);
 +        DivideConquer(nums,sortedNums,count,mid+1,end);
 +        
 +        // OK，既然现在start~mid和mid+1~end这两段都分别有序，
 +        // 那么对于start~mid中的任何一个元素，我们都可以轻易地知道在mid+1~end中有多少小于它的数
 +        for (int i=start; i<=mid; i++)
 +        {
 +            int x=nums[i];
 +            auto pos = lower_bound(sortedNums.begin()+mid+1,sortedNums.begin()+end+1,x,cmp);
 +            count[i]+= pos - (sortedNums.begin()+mid+1); // 更新nums[i]的number of smaller elements to the right
 +        }
 +        
 +        // 将两段已经有序的数组段start~mid,mid+1~end合起来排序。
 +        // 如果写归并排序的code会更快一些。这里就偷懒了，直接用sort函数。
 +        sort(sortedNums.begin()+start,sortedNums.begin()+end+1);
 +    }
 +};
