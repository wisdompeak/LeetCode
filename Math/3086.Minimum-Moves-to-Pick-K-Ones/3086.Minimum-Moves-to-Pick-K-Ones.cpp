using LL = long long;
class Solution {
public:
    long long minimumMoves(vector<int>& nums, int k, int maxChanges) 
    {
        vector<int>arr;
        for (int i=0; i<nums.size(); i++)
        {
            if (nums[i]==1) arr.push_back(i);
        }
            
        int m = arr.size();        
        if (m==0) return k*2;        
        
        LL ret = LLONG_MAX;                
        
        maxChanges = min(k, maxChanges);
        
        int task = min(m, k-maxChanges);
        if (maxChanges >= k-task)
            ret = min(ret, helper(arr, task) +  (k-task)*2);
        
        task = min(m, k-maxChanges+1);
        if (maxChanges >= k-task && k-task>=0)
            ret = min(ret, helper(arr, task) + (k-task)*2);
                    
        task = min(m, k-maxChanges+2);
        if (maxChanges >= k-task && k-task>=0)
            ret = min(ret, helper(arr, task) + (k-task)*2);
        
        task = min(m, k-maxChanges+3);
        if (maxChanges >= k-task && k-task>=0)
            ret = min(ret, helper(arr, task) + (k-task)*2);
        
        return ret;
    }
    
    LL helper(vector<int>&arr, int k)
    {
        if (k==0) return 0;
        
        int m = arr.size();
        
        LL sum = 0;
        for (int i=0; i<min(m,k); i++)
        sum += abs(arr[i]-arr[k/2]);
        
        LL ret = sum;
        for (int i=1; i+k-1<m; i++)
        {            
            int d = arr[i+k/2]-arr[i+k/2-1];
            sum = sum - (k - k/2 -1)*d + (k/2 + 1)*d - abs(arr[i+k/2]-arr[i-1]) + abs(arr[i+k-1]-arr[i+k/2]);
            ret = min(ret, sum);
        }
        
        return ret;
    }
};
