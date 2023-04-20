using LL = long long;
class Solution {
public:
    long long makeSubKSumEqual(vector<int>& arr, int k) 
    {        
        int n = arr.size();
        LL ret = 0;
        vector<int>visited(n);
        
        for (int i=0; i<k; i++)
        {
            vector<int>nums;
            int j = i;
            while (visited[j]==0)
            {                              
                visited[j] = 1;
                nums.push_back(arr[j]);
                j = (j+k)%n;                                
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
