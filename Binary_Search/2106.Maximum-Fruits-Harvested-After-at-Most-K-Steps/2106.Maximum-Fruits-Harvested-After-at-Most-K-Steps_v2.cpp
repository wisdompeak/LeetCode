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
        int mid = lower_bound(pos.begin(), pos.end(), startPos) - pos.begin();
        for (int i=mid; i<n; i++)
        {
            if (pos[i] - startPos > k) break;
            double d = (k-(pos[i]-startPos))/2;
            int j = lower_bound(pos.begin(), pos.end(), startPos-d) - pos.begin();
            if (j>=0 && j<n) ret = max(ret, presum[i] - (j==0?0:presum[j-1]));
        }

        mid = upper_bound(pos.begin(), pos.end(), startPos) - pos.begin()-1;
        for (int i=mid; i>=0; i--)
        {     
            if (startPos - pos[i] > k) break;
            double d = (k-(startPos-pos[i]))/2;
            int j = upper_bound(pos.begin(), pos.end(), startPos+d) - pos.begin() - 1;
            if (j>=0 && j<n) ret = max(ret, presum[j] - (i==0?0:presum[i-1]));
        }
        
        return ret;
    }
};
