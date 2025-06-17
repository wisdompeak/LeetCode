using ll = long long;
const int MAXN = 100000;
const int LOGN = 17;
class Solution {
    int up[MAXN][LOGN+1];
public:
    ll stepUp(int u, int k) {        
        for (int i=LOGN; i>=0; i--) {
            if ((k>>i)&1) {
                u = up[u][i];
            }
        }
        return u;
    }

    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {        
        vector<pair<int,int>>arr;
        for (int i=0; i<nums.size(); i++) {
            arr.push_back({nums[i], i});
        }
        sort(arr.begin(), arr.end());

        unordered_map<int,int>idx;
        for (int i=0; i<n; i++) {
            idx[arr[i].second] = i;
        }
        
        int j = 0;
        for (int i=0; i<n; i++) {
            while (j<n && arr[j].first-arr[i].first<=maxDiff) {
                j++;
            }                        
            up[i][0] = j-1;
        }
        
        for(int k = 1; k <= LOGN; k++) {
            for(int v = 0; v < n; v++) {
                up[v][k] = up[up[v][k-1]][k-1];
            }
        }

        vector<int>rets;        
        for (auto& q: queries) {
            if (q[0]==q[1]) {
                rets.push_back(0);
                continue;
            }
            int u = idx[q[0]], v = idx[q[1]];
            if (u>v) swap(u,v);

            int low = 1, high = 1e5;            
            while (low < high) {
                int mid = low + (high-low)/2;
                int k = stepUp(u, mid);
                if (arr[k].first >= arr[v].first)
                    high = mid;
                else
                    low = mid+1;
            }
            int k = stepUp(u, low);
            if (arr[k].first >= arr[v].first)            
                rets.push_back(low);
            else
                rets.push_back(-1);
        }

        return rets;
    }
};
