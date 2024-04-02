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
                
        if (k-maxChanges <= m && maxChanges>=0)
            ret = min(ret, helper(arr, k-maxChanges) +  maxChanges*2);
        
        if (k-maxChanges+1 <= m && maxChanges-1>=0)
            ret = min(ret, helper(arr, k-maxChanges+1) + (maxChanges-1)*2);
                    
        if (k-maxChanges+2 <= m && maxChanges-2>=0)
            ret = min(ret, helper(arr, k-maxChanges+2) + (maxChanges-2)*2);
        
        if (k-maxChanges+3 <= m && maxChanges-3>=0)
            ret = min(ret, helper(arr, k-maxChanges+3) + (maxChanges-3)*2);
        
        return ret;
    }
    
    LL helper(vector<int>&arr, int k)
    {
        if (k==0) return 0;
        
        int m = arr.size();
        
        LL sum = 0;
        for (int i=0; i<k; i++)
        sum += abs(arr[i]-arr[k/2]);
        
        LL ret = sum;
        for (int i=0; i+k<m; i++)
        {            
            int d = arr[i+k/2+1]-arr[i+k/2];
            sum = sum + (k/2 + 1)*d - (k - (k/2+1))*d - abs(arr[i+k/2+1]-arr[i]) + abs(arr[i+k/2+1]-arr[i+k]);
            ret = min(ret, sum);
        }
        
        return ret;
    }
};
