class Solution {
    vector<int>freq;
    vector<int>sf;
    long long ret = 0;
    vector<vector<int>>next;
public:
    void dfs(int cur, int parent){
        ret += freq[sf[cur]];
        freq[sf[cur]]+=1;
        for (int nxt: next[cur]) {
            if (nxt==parent) continue;
            dfs(nxt, cur);
        }
        freq[sf[cur]]--;
    }
    
    vector<int>ComputeSpf(int N) {
        vector<int>spf(N+1);
        for (int i = 0; i <= N; ++i) spf[i] = i;
        for (int i = 2; i * i <= maxA; ++i) {
            if (spf[i] == i) {
                for (int j = i * i; j <= N; j += i) {
                    if (spf[j] == j) spf[j] = i;
                }
            }
        }    
        return spf;
    }

    
    long long sumOfAncestors(int n, vector<vector<int>>& edges, vector<int>& nums) {
        int maxA = *max_element(nums.begin(), nums.end());
        vector<int>spf = ComputeSpf(maxA);

        freq.resize(maxA+1);
        sf.resize(n);
        for (int i=0; i<n; i++) {
            int x = nums[i];
            int ret = 1;
            while (x>1) {                
                int p = spf[x];
                int cnt = 0;
                while (x%p==0) {
                    x/=p;
                    cnt++;
                }
                if (cnt%2==1) ret*=p;
            }
            sf[i] = ret;
        }
      
        next.resize(n);
        for (auto& e: edges) {
            int u = e[0], v = e[1];
            next[u].push_back(v);
            next[v].push_back(u);
        }        
        
        dfs(0, -1);

        return ret;        
    }
};
