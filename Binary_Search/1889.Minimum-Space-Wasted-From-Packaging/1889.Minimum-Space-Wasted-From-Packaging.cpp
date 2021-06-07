typedef long long ll;
class Solution {
public:
    int minWastedSpace(vector<int>& packages, vector<vector<int>>& boxes) 
    {
        int m = packages.size();
        sort(packages.begin(), packages.end());
        vector<ll>presum(m);
        ll pre = 0;
        for (int i=0; i<m; i++)
        {
            pre += packages[i];
            presum[i] = pre;
        }
        
        ll ret = -1;
        ll M = 1e9+7;
        for (auto& box: boxes)
        {
            sort(box.begin(), box.end());
            int n = box.size();
            ll sum = 0;
            int lastPack = -1;
            for (int i=0; i<n; i++)
            {
                auto iter = upper_bound(packages.begin(), packages.end(), box[i]);
                if (iter==packages.begin())
                    continue;
                int j = prev(iter)-packages.begin();
                sum += (ll)box[i]*(ll)(j-lastPack) - (presum[j] - (lastPack==-1 ? 0:presum[lastPack])); 
                lastPack = j;
                if (lastPack==m-1)
                    break;
            }
            if (lastPack!=m-1)
                continue;
            if (ret==-1)
                ret = sum;
            else
                ret = min(ret, sum);            
        }                
        return ret % M;
    }
};
