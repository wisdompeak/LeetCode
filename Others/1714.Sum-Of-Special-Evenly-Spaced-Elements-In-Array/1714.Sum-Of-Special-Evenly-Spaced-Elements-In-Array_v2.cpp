class Solution {        
    long M = 1e9+7;
    int sufsum[256][50001];

public:
    vector<int> solve(vector<int>& nums, vector<vector<int>>& queries) 
    {        
        int n = nums.size();
        vector<int>rets(queries.size());    
        
        for (int d = 1; d<sqrt(n); d++)
            for (int i=0; i<n; i++)
                sufsum[d][i] = -1;

        
        for (int k=0; k<queries.size(); k++)
        {
            int s = queries[k][0];
            int d = queries[k][1];
            if (d >= sqrt(n))
            {
                long sum = 0;
                int i = s;
                while (i < n)
                {
                    sum = (sum+nums[i])%M;
                    i+=d;
                }
                rets[k] = sum;                    
            }
            else
            {                
                if (sufsum[d][0] == -1)
                {
                    for (int i = n-1; i>=0; i--)
                    {
                        if (i+d < n)
                            sufsum[d][i] = (sufsum[d][i+d] + nums[i]) % M;
                        else
                            sufsum[d][i] = nums[i];
                    }                
                }                                
                rets[k] = sufsum[d][s];
            }
        }
        return rets;
        
    }
};
