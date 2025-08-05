class Solution {
public:
    int minJumps(vector<int>& nums) {
        int MAXA = *max_element(nums.begin(), nums.end());
        vector<int>spf(MAXA+1, 0);
        for (int i=2; i<=MAXA;i++) {
            if (spf[i]) continue;
            for (int j=i; j<=MAXA; j+=i)
                if (!spf[j]) spf[j]=i;            
        }

        vector<vector<int>>prime_to_idx(MAXA+1);
        int n = nums.size();
        for (int i=0; i<n; i++) {
            int x = nums[i];            
            while (x>1) {
                int p = spf[x];
                prime_to_idx[p].push_back(i);
                while (x%p==0) x/=p;
            }
        }

        const int INF = 1e9;
        vector<int>dist(n, INF);
        vector<int>used_prime(MAXA+1, 0);
        deque<int>q;
        dist[0] = 0;
        q.push_back(0);

        while (!q.empty()) {
            int i = q.front();
            q.pop_front();
            int d = dist[i];
            if (i==n-1) 
                return d;

            if (i+1<n && dist[i+1]==INF) {
                dist[i+1] = d+1;
                q.push_back(i+1);
            }
            if (i-1>=0 && dist[i-1]==INF) {
                dist[i-1] = d+1;
                q.push_back(i-1);
            }
            int x = nums[i];            
            if (x>1 && spf[x]==x) {
                if (used_prime[x]) continue;
                used_prime[x] = 1;
                for (int j: prime_to_idx[x]) {
                    if (dist[j]==INF) {
                        dist[j] = d+1;
                        q.push_back(j);
                    }
                }                
            }
        }

        return 0;        
    }
};
