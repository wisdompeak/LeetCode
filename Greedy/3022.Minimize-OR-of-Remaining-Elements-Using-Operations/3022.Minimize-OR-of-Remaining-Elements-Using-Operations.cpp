class Solution {
public:
    int minOrAfterOperations(vector<int>& nums, int k) 
    {
        int n = nums.size();
        vector<int>arr(n);
        int ret = 0;
        for (int t=29; t>=0; t--)
        {            
            for (int i=0; i<n; i++)
                arr[i] = (arr[i]<<1) + ((nums[i]>>t)&1);
            
            if (checkOK(arr, k))
                ret = ret*2+0;
            else
            {
                ret = ret*2+1;
                for (int i=0; i<n; i++)
                    arr[i] = (arr[i] >> 1);
            }                
        }
        return ret;
    }
    
    bool checkOK(vector<int>&arr, int k)
    {
        int n = arr.size();
        int count = 0;
        int i = 0;
        while (i<n)
        {            
            int cur = arr[i];
            int j = i;
            while (cur!=0)
            {
                count++;
                j++;
                if (j==n) break;
                cur &= arr[j];                
            }                        
            i = j+1;
        }        
        return (count!=n && count <= k);        
    }
};
