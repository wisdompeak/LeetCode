class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) 
    {
        int n = fruits.size();
        vector<int>pos(n);
        vector<int>presum(n);
        for (int i=0; i<n; i++)
        {
            pos[i] = fruits[i][0];
            presum[i] = (i==0?0:presum[i-1]) + fruits[i][1];
        }
        
        int ret = 0;
        for (int i=0; i<n; i++)
        {
            if (pos[i]<=startPos)
            {
                double d = k - (startPos-pos[i]);
                if (d<0) continue;
                int j = upper_bound(pos.begin(), pos.end(), startPos+d/2) - pos.begin() - 1;
                if (j>=0 && j<n)
                    ret = max(ret, presum[j] - (i==0?0:presum[i-1]));
            }
            else
            {
                double d = k - (pos[i]-startPos);
                if (d<0) continue;   
                int j = lower_bound(pos.begin(), pos.end(), startPos-d/2) - pos.begin();
                if (j>=0 && j<n)
                    ret = max(ret, presum[i]- (j==0?0:presum[j-1]));
            }
        }
        return ret;
    }
};
