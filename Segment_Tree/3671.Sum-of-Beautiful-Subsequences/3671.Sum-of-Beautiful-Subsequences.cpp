class BIT{
    public:
    int N;    
    vector<long long>bitArr; // Note: all arrays are 1-index
    vector<long long>nums;
    long long M = 1e9+7;

    void init(int N)
    {
        this->N = N;
        bitArr.resize(N+1);
        nums.resize(N+1);        
    }

    // increase nums[i] by delta
    void updateDelta(int i, long long delta) {
        int idx = i;
        while (idx <= N)
        {
            bitArr[idx]+=delta;
            bitArr[idx] %= M;
            idx+=idx&(-idx);
        }
    }

    // sum of a range nums[1:j] inclusively
    long long queryPreSum(int idx){
        long long result = 0;
        while (idx){
            result += bitArr[idx];
            // result %= M;
            idx-=idx&(-idx);
        }
        return result;
    }

    // sum of a range nums[i:j] inclusively
    long long sumRange(int i, int j) {    
        return queryPreSum(j)-queryPreSum(i-1);
    } 
};

long long MOD = 1e9+7;

class Solution {
public:
    int totalBeauty(vector<int>& nums) {
        int mx = *max_element(begin(nums), end(nums));
        vector<vector<int>>pos(mx+1);
        for (int i=0; i<nums.size(); i++) {
            for (int j=1; j*j<=nums[i]; j++) {
                if (nums[i]%j==0) {
                    pos[j].push_back(i);
                    if (j*j!=nums[i]) pos[nums[i]/j].push_back(i);
                }
            }
        }

        vector<long long>seq(mx+1);
        for (int g=1; g<=mx; g++) {
            map<int,int>mp;
            for (int x: pos[g]) mp[nums[x]] = 1;
            int idx = 0;
            for (auto& [k,v]:mp) v = ++idx;

            vector<int>arr;
            for (int x: pos[g]) arr.push_back(mp[nums[x]]);

            BIT bit;
            bit.init(arr.size());                        
            for (int x: arr) {
                long long ans = bit.queryPreSum(x-1) + 1;
                seq[g] = (seq[g]+ans)%MOD;
                bit.updateDelta(x, ans);
            }
        }

        vector<long long>ret(mx+1);        
        for (int g=mx; g>=1; g--) {
            ret[g] = seq[g];
            for (int j=g*2; j<=mx; j+=g)
                ret[g] = (ret[g]-ret[j]+MOD) % MOD;            
        }

        long long ans = 0;
        for (int g=mx; g>=1; g--) {
            ans = (ans + g*ret[g]) % MOD;
        }
        return ans;       
    }
};
