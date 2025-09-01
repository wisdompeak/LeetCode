class Solution {
    vector<int>divisors;
    vector<int>cur;
    vector<int>rets;
    int bestDiff = INT_MAX/2;
public:
    void dfs(int idx, int n, int k) {
        if (k==1) {
            cur.push_back(n);
            int diff = cur.back()-cur[0];
            if (diff < bestDiff) {
                bestDiff = diff;
                rets = cur;
            }
            cur.pop_back();
            return;
        }

        for (int i = idx; i<divisors.size(); i++) {
            int d = divisors[i];
            if (n%d!=0) continue;
            if (n/d < d) break;
            cur.push_back(d);
            dfs(i, n/d, k-1);
            cur.pop_back();
        }
    }
    
    vector<int> minDifference(int n, int k) {      
        for (int i=1; i*i<=n; i++) {
            if (n%i==0) {
                divisors.push_back(i);
                if (i*i!=n) divisors.push_back(n/i);
            }                
        }
        sort(divisors.begin(), divisors.end());

        dfs(0, n, k);

        return rets;        
    }
};
