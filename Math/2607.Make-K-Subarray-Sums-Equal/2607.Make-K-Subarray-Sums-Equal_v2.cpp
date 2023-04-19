using LL = long long;
class Solution {
public:
    long long makeSubKSumEqual(vector<int>& arr, int k) 
    {        
        int n = arr.size();
        LL ret = 0;
        vector<int>visited(n);
        int T = gcd(k, n);
        
        for (int i=0; i<k; i++)
        {
            if (visited[i]==1) continue;
            vector<int>nums;
            int j = i;
            while (j<n)
            {                              
                visited[j] = 1;
                nums.push_back(arr[j]);
                j+=T;                     
            }
            ret += helper(nums);            
        }        
        return ret;
    }
    
    LL helper(vector<int>&nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        LL ret = 0;
        for (int i=0; i<n; i++)
            ret += (LL)abs(nums[i] - nums[n/2]);
        return ret;
    }
};
