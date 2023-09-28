class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) 
    {
        int m = mat.size(), n = mat[0].size();
        vector<int>nums(n+1, 0);    
        int ret = 0;    
        for (int i=0; i<m; i++)
        {
            for (int j=0; j<n; j++)
                nums[j+1] = (mat[i][j]==1 ? (nums[j+1]+1) : 0);
            stack<int>stk;       
            stk.push(0);     
            int sum = 0;
            for (int j=1; j<=n; j++)
            {
                while (!stk.empty() && nums[stk.top()] > nums[j])
                {
                    int p1 = stk.top();
                    stk.pop();
                    int p2 = stk.top();
                    sum -= (p1-p2) * (nums[p1] - nums[j]);
                }
                stk.push(j);
                sum += nums[j];
                ret += sum;
            }            
        }
        return ret;        
    }
};
