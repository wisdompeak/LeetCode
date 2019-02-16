class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) 
    {
        int N = nums.size();
        if (N==0) return {};
        
        sort(nums.begin(),nums.end());        
        vector<int>dp(N,1);
        vector<int>prev(N,-1);        
        
        for (int i=1; i<N; i++)
        {
            int count = 1;
            int Prev = -1;
            for (int j=0; j<i; j++)
            {
                if (nums[i]%nums[j]!=0) continue;
                if (dp[j]+1>count)
                {
                    count = dp[j]+1;
                    Prev = j;                    
                }
            }
            dp[i] = count;
            prev[i] = Prev;
            
        }
        
        int temp = 0;
        int end;
        for (int i=0; i<N; i++)
        {
            if (dp[i]>temp)
            {
                temp = dp[i];
                end = i;
            }
        }
        
        vector<int>results;
        while (end!=-1)
        {
            results.push_back(nums[end]);
            end = prev[end];
        }
        
        return results;
    }
};
