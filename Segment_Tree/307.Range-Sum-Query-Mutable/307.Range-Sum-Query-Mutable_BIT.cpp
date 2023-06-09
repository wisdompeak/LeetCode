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

class NumArray {
    BIT bit;
    vector<int>nums;
public:
    NumArray(vector<int>& nums) 
    {
        this->nums = nums;
        int n = nums.size();        
        bit.init(n+10);        

        for (int i=0; i<n; i++) {
            bit.updateDelta(i+1, nums[i]);            
        }
        
    }
    
    void update(int index, int val) 
    {
        bit.updateDelta(index+1, val-nums[index]);     
        nums[index] = val;   
    }
    
    int sumRange(int left, int right) 
    {
        return bit.sumRange(left+1, right+1);        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
