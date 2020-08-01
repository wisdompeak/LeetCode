class Solution {
public:
    vector<int> bit;
    
    long long sortedArrangement(vector<int> &nums) 
    {
        int n = nums.size();
        bit.resize(n+1);

        long long result = 0;
        
        for (int i = 0; i < n; i++) {
            int k1 = querySum(nums[i] - 1);
            int k2 = i - k1;
            result += 2 * min(k1, k2) + 1;
            update(nums[i], 1);
        }
        
        return result;
    }
    
    int lowbit(int x) 
    {
        return x & (-x);
    }
    
    void update(int pos, int value) 
    {
        while (pos < bit.size()) 
        {
            bit[pos] += value;
            pos += lowbit(pos);
        }
    }
    
    int querySum(int pos) 
    {
        int sum = 0;
        while (pos > 0) {
            sum += bit[pos];
            pos -= lowbit(pos);
        }
        return sum;
    }
};
