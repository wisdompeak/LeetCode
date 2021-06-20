class Solution {
public:
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) 
    {
        int n = nums.size();
        vector<vector<int>>presum(101, vector<int>(n,0));

        for (int k = 1; k<=100; k++)
        {
            for (int i=0; i<n; i++)
                presum[k][i] = (i==0?0:presum[k][i-1]) + (nums[i]==k);
        }

        vector<int>rets;
        for (auto q: queries)
        {
            int left = q[0], right = q[1];
            vector<int>arr;
            for (int k=1; k<=100; k++)
            {
                int count = presum[k][right] - (left==0?0:presum[k][left-1]);
                if (count>0)
                    arr.push_back(k);

                if (arr.size()>=2 && arr.back() - arr[arr.size()-2]==1)
                    break;
            }            

            if (arr.size()<=1)
            {
                rets.push_back(-1)
            }
            else
            {
                int gap = INT_MAX;
                for (int i=1; i<arr.size(); i++)
                    gap = min(gap, arr[i]-arr[i-1]);
                rets.push_back(gap);
            }
        }

        return rets;
    }
};
