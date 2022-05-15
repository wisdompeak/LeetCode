class Solution {
public:
    int largestVariance(string s) 
    {
        vector<int>count(26,0);
        for (auto x: s)
            count[x-'a']++;
                
        int ret = 0;
        int n = s.size();
        for (int i=0; i<26; i++)
            for (int j=0; j<26; j++)
            {
                if (i==j) continue;
                if (count[i]==0 || count[j]==0) continue;
                vector<int>arr(n, 0);
                for (int k=0; k<n; k++)
                {
                    if (s[k]=='a'+i)
                        arr[k] = 1;
                    else if (s[k]=='a'+j)
                        arr[k] = -1;
                }                
                ret = max(ret, helper(arr));                    
            }
        
        return ret;
    }
    
    int helper(vector<int>&nums)
    {                
        int n = nums.size();        
        vector<int>dp(n);
        int curSum = 0;
        
        for (int i = 0; i < n; i++) 
        {
            curSum = max(curSum+nums[i], nums[i]);
            dp[i] = curSum;            
        }
        
        curSum = 0;
        int ret = 0;
        for (int i=n-1; i>=0; i--)
        {
            curSum = max(curSum+nums[i], nums[i]);
            if (nums[i]==-1)
                ret = max(ret, curSum + dp[i] - nums[i]);
        }
        return ret;
    }
};
