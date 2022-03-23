class Solution {
public:
    int maximumTop(vector<int>& nums, int K) 
    {
        int n = nums.size();        
        int ret = INT_MIN;
        for (int i=1; i<=n; i++)
        {
            int k = K;
            if (k<i-1) continue;
            k -= (i-1);
            int flag = 0;

            if (k==0)
                flag = 1;
            else if (k==1)
                flag = 0;
            else if (k%2==0)
                flag = 1;
            else if (k%2==1 && i<n)
                flag = 1;
            else if (k%2==1 && i>1)
                flag = 1;

            if (flag) ret = max(ret, nums[i-1]);
        }
        return ret==INT_MIN? -1:ret;
    }
};
