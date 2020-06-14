class Solution {    
    vector<int>presum;
public:
    int findBestValue(vector<int>& arr, int target) 
    {
        sort(arr.begin(),arr.end());
        
        presum.resize(arr.size());
        presum[0] = arr[0];        
        for (int i=1; i<arr.size(); i++)
            presum[i] = presum[i-1]+arr[i];

        if (presum.back() <= target) return arr.back();
                    
        int left = 0;
        int right = 1e5;
        
        while (left<right)
        {
            int mid = left+(right-left)/2;
            if (helper(arr, mid)>=target)
                right = mid;
            else
                left = mid+1;
        }
        
        int a = helper(arr,left);
        int b = helper(arr,left-1);
        if (abs(a-target)<abs(target-b))
            return left;
        else
            return left-1;                
    }
    
    long long helper(vector<int>&arr, int value)
    {
        auto iter = upper_bound(arr.begin(),arr.end(),value);
        int num = arr.end()-iter;
        if (iter-arr.begin()-1>=0)
            return presum[iter-arr.begin()-1]+(long long)num*value;
        else
            return (long long)num*value;
    }
};
