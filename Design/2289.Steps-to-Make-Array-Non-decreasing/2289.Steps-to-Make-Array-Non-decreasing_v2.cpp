class Solution {
public:
    int totalSteps(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int>next(n);        
        for (int i=0; i<n; i++)
            next[i] = i+1;
        vector<int>removed(n);
        
        queue<pair<int,int>>q;
        for (int i=n-1; i>=1; i--)        
        {
            if (nums[i-1]>nums[i])
                q.push({i-1, i});
        }            

        int step = 0;
        while (!q.empty())
        {
            int len = q.size();            
            while (len--)
            {
                auto [l,r] = q.front();
                int r0 = r;
                q.pop();

                if (removed[l]) continue;
                // if (removed[r]) continue;

                removed[r] = 1;
                
                int r2 = next[r];
                while (r2!=n && removed[r2])
                    r2 = next[r2];
                next[r] = r2;

                if (r2!=n && nums[l]>nums[r2])
                    q.push({l,r2});
            }

            step++;                
        }

        return step;
    }
};
