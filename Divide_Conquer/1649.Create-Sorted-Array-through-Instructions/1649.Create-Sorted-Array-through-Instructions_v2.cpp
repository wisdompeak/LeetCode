const int MAX_N = 100000;

class Solution {
public:    
    long long bitArr[MAX_N+1];
    long long nums[MAX_N+1];
    long long M = 1e9+7;

    void updateDelta(int i, long long delta) {
        int idx = i;
        while (idx <= MAX_N)
        {
            bitArr[idx]+=delta;
            bitArr[idx] %= M;
            idx+=idx&(-idx);
        }
    }

    long long queryPreSum(int idx){
        long long result = 0;
        while (idx){
            result += bitArr[idx];
            result %= M;
            idx-=idx&(-idx);
        }
        return result;
    }

    long long sumRange(int i, int j) {
        return queryPreSum(j)-queryPreSum(i-1);
    }
    
    int createSortedArray(vector<int>& instructions) 
    {        
        long long ret = 0;
        
        for (auto x:instructions)
        {
            updateDelta(x, 1);
            long long a = sumRange(1, x-1);
            long long b = sumRange(x+1, MAX_N);
            ret += min(a,b);
            ret %= M;
        }
        return ret;
        
    }
};
