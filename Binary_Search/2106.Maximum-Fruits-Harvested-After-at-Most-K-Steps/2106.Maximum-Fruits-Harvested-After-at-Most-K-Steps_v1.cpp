class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) 
    {
        int n = fruits.size();
        vector<int>pos(n);
        vector<int>val(n);
        for (int i=0; i<n; i++)
        {
            pos[i] = fruits[i][0];
            val[i] = fruits[i][1];
        }
        vector<int>presum(n);
        int cur = 0;
        for (int i=0; i<n; i++)
        {
            cur += val[i];
            presum[i] = cur;
        }

        int ret = 0;
        int j = 0;
        while (j<n && pos[j]<startPos) j++;        
        for (int i=0; i<n && pos[i]<=startPos; i++)
        {            
            while (j<n && (startPos-pos[i]+(pos[j]-startPos)*2) <= k)
            {                
                ret = max(ret, presum[j] - (i==0 ? 0:presum[i-1]));
                j++;
            }
        }

        j = n-1;
        while (j>=0 && pos[j]>startPos) j--;
        for (int i=n-1; i>=0 && pos[i]>=startPos; i--)
        {
            while (j>=0 && (pos[i]-startPos+(startPos-pos[j])*2 <=k))
            {
                
                ret = max(ret, presum[i] - (j==0?0:presum[j-1]));
                j--;
            }
        }

        int i = upper_bound(pos.begin(), pos.end(), startPos) - pos.begin()-1;
        int sum = 0;
        while (i>=0 && startPos-pos[i]<=k) 
        {
            sum += val[i];
            i--;
        }
        ret = max(ret, sum);

        i = lower_bound(pos.begin(), pos.end(), startPos) - pos.begin();
        sum = 0;
        while (i<n && pos[i]-startPos<=k) 
        {
            sum += val[i];
            i++;
        }
        ret = max(ret, sum);

        return ret;
    }
};
