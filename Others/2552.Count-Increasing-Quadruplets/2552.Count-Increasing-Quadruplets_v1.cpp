using LL = long long;
class Solution {    
public:
    long long countQuadruplets(vector<int>& nums) 
    {
        int n = nums.size();
        nums.insert(nums.begin(), 0);
        LL ret = 0;
        
        vector<vector<int>>pre(n+5, vector<int>(n+5));
        vector<vector<int>>post(n+5, vector<int>(n+5));
        
        for (int i=1; i<=n; i++)
            for (int v=1; v<=n; v++)
            {
                if (nums[i] < v)
                    pre[i][v] = pre[i-1][v]+1;
                else
                    pre[i][v] = pre[i-1][v];
            }
                
        for (int i=n; i>=1; i--)
            for (int v=1; v<=n; v++)
            {
                if (nums[i] > v)
                    post[i][v] = post[i+1][v]+1;
                else
                    post[i][v] = post[i+1][v];                
            }
                    
        for (int j=1; j<=n; j++)                    
            for (int k=j+1; k<=n; k++)
            {
                if (nums[j]>nums[k])                
                    ret += pre[j-1][nums[k]] * post[k+1][nums[j]];
            }    
    
        return ret;
    }
};
