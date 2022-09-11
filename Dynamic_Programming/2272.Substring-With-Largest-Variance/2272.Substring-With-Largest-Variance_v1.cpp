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
        int curSum0 = 0;
        int curSum1 = INT_MIN/2;
        int ret = 0;
        
        for (int i = 0; i < n; i++) 
        {
            if (nums[i]==1)
            {
                curSum1 = curSum1+nums[i];
                curSum0 = max(curSum0+nums[i], nums[i]);                
            }
            else if (nums[i] == -1)
            {
                curSum1 = max(nums[i], max(curSum0, curSum1)+nums[i]);
                curSum0 = 0;
            }
            
            ret = max(ret, curSum1);
        }
        
        return ret;
    }
};
