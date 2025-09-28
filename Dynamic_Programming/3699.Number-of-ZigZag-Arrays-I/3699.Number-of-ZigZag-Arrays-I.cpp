int MOD = 1e9+7;
class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        int  m = r-l+1;

        vector<int>up(m+1,1);
        vector<int>down(m+1,1);    

        for (int pos = 2; pos<=n; pos++) {
            vector<int>new_up(m+1, 0), new_down(m+1, 0);
            int presum = 0;
            for (int x=1; x<=m; x++) {
                new_up[x] = presum;
                presum = (presum + down[x])% MOD;
            }
            presum = 0;
            for (int x=m; x>=0; x--) {
                new_down[x] = presum;
                presum = (presum + up[x])% MOD;
            }
            
            up = move(new_up);
            down = move(new_down);            
        }

        long long ans = 0;
        for (int x=1; x<=m; x++) {
            ans += up[x];
            ans += down[x];
            ans%=MOD;
        }
        return ans;
    }
};
