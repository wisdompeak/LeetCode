const int MAX_N = 200003;
using LL = long long;

class Solution {        
    int OFFSET = 100001;
    long long bitArr[MAX_N];
    long long nums[MAX_N];  // Note: nums is 1-index
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
    
public:
    int subarraysWithMoreZerosThanOnes(vector<int>& nums) 
    {
        cout<<nums.size()<<endl;
        int diff = 0;
        LL ret = 0;
        updateDelta(0+OFFSET, 1);
        
        for (int i=0; i<nums.size(); i++)
        {
            if (nums[i]==1) diff++;
            else diff--;
            
            ret = (ret + queryPreSum(diff-1+OFFSET)) % M;                    
            updateDelta(diff+OFFSET, 1);
        }        
        return ret;        
    }
};
