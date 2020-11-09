const int MAX_N = 100000;

class Solution {
public:    
    long long bitArr[MAX_N+1];
    long long nums[MAX_N+1];  // Note: nums is 1-index
    long long M = 1e9+7;

    // increase nums[i] by delta  (1-index)
    void updateDelta(int i, long long delta) {
        int idx = i;
        while (idx <= MAX_N)
        {
            bitArr[idx]+=delta;
            bitArr[idx] %= M;
            idx+=idx&(-idx);
        }
    }

    // sum of a range nums[1:j] inclusively, 1-index
    long long queryPreSum(int idx){
        long long result = 0;
        while (idx){
            result += bitArr[idx];
            result %= M;
            idx-=idx&(-idx);
        }
        return result;
    }

    // sum of a range nums[i:j] inclusively
    long long sumRange(int i, int j) {    
        return queryPreSum(j)-queryPreSum(i-1);
    }    
};
