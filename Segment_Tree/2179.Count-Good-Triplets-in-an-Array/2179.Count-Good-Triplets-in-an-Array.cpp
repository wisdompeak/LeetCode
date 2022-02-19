class BIT{
    public:
    int N;    
    vector<long long>bitArr; // Note: all arrays are 1-index
    vector<long long>nums;
    long long M = 1e9+7;
    
    BIT(int N)
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

class Solution {
public:    
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) 
    {
        int n = nums1.size();
        unordered_map<int,int>Map;
        for (int i=0; i<n; i++)
            Map[nums1[i]] = i;
        
        for (int i=0; i<n; i++)
            nums2[i] = Map[nums2[i]]+1;
        
        vector<int>smallerBefore(n,0);
        BIT bit1(100005);
        for (int i=0; i<n; i++)
        {
            smallerBefore[i] = bit1.sumRange(1,nums2[i]);
            bit1.updateDelta(nums2[i], 1);
        }
        
        vector<int>largerAfter(n,0);
        BIT bit2(100005);
        for (int i=n-1; i>=0; i--)
        {
            largerAfter[i] = bit2.sumRange(nums2[i], 100000);
            bit2.updateDelta(nums2[i], 1);
        }
        
        long long ret = 0;
        for (int i=0; i<n; i++)
            ret += (long long)smallerBefore[i] * (long long)largerAfter[i];
        return ret;
    }    
};
