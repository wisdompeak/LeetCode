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
    long long sumRange(int i, int j) 
    {  
        if (i>j) return 0;    
        return queryPreSum(j)-queryPreSum(i-1);
    } 
};


class Solution {
public:
    long long countOperationsToEmptyArray(vector<int>& nums) 
    {
        int n = nums.size();
        nums.insert(nums.begin(), 0);
        BIT bit;
        bit.init(n+10);
        
        for (int i=1; i<=n; i++) 
        {
            bit.updateDelta(i, 1);
        }
        
        map<int,int>Map;
        for (int i=1; i<=n; i++)
            Map[nums[i]] = i;
                
        long long ret = 0;
        int last_p = -1;
        for (auto& [v, p]: Map)
        {
            if (last_p==-1)
            {
                ret += bit.sumRange(1, p-1);
                last_p = p;
                bit.updateDelta(p, -1);
                continue;
            }
            
            if (last_p <= p)
            {
                ret += bit.sumRange(last_p, p-1);
            }
            else
            {
                ret += bit.sumRange(1, p-1);
                ret += bit.sumRange(last_p+1, n);                                
            }
            last_p = p;
            bit.updateDelta(p, -1);
        }
        
        return ret + n;
    }
};
