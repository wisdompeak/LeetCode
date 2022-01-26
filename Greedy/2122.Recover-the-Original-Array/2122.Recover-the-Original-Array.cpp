using LL = long long;
class Solution {
public:
    vector<int> recoverArray(vector<int>& nums) 
    {
        int n = nums.size()/2;
        sort(nums.begin(), nums.end());
        
        for (int i=1; i<=n; i++)
        {
            if (nums[i]==nums[0]) continue;
            if ((nums[i]+nums[0])%2==1) continue;
            int mn = (nums[i]+nums[0])/2;
            int k = (nums[i]-nums[0])/2;

            int left = 0, right = 1;
            int flag = 1;
            vector<int>visited(2*n);
            vector<int>rets;
            for (int t=0; t<n; t++)
            {
                while (visited[left]) left++;
                if (left==2*n)
                {
                    flag = 0;
                    break;
                }
                visited[left] = 1;
                while (right<2*n && (visited[right]==1 || nums[right]!=nums[left]+2*k))
                    right++;
                if (right<2*n)
                    visited[right] = 1;
                else
                {
                    flag = 0;
                    break;
                }                
                rets.push_back(nums[left]+k);    
            }
            if (flag)
                return rets;
        }
        return {};        
    }
};
