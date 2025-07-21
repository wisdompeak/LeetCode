using ll = long long;

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
            // bitArr[idx] %= M;
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

class Solution {
public:    
    int getDepth(ll x) {
        int count = 0;        
        while (x!=1ll) {
            x = __builtin_popcountll(x);
            count++;            
        }
        return count;
    }
    
    vector<int> popcountDepth(vector<long long>& nums, vector<vector<long long>>& queries) {
        int N = nums.size()+1;
        vector<BIT> bit_arr (6);
        for (int i=0; i<=5; i++)
            bit_arr[i].init(N);
                
        for (int i=0; i<nums.size(); i++) {
            int depth = getDepth(nums[i]);
            bit_arr[depth].updateDelta(i+1, 1);
        }
        
        vector<int>rets;
        for (auto&q: queries) {
            if (q[0]==2) {
                ll idx = q[1], val = q[2];
                int depth0 = getDepth(nums[idx]);
                int depth1 = getDepth(val);
                bit_arr[depth0].updateDelta(idx+1, -1);
                bit_arr[depth1].updateDelta(idx+1, 1);
                nums[idx] = val;
            } else {
                int l = q[1], r = q[2], k = q[3];                
                rets.push_back(bit_arr[k].sumRange(l+1,r+1));
            }
        }

        return rets;
        
    }
};
