#define LL long long
LL M = 1e9+7;

class Fancy {
    LL add, mul;
    vector<LL>nums;
    
    LL quickPow(int x, int y) 
    {
        int ret = 1;
        int cur = x;
        while (y) 
        {
            if (y & 1) 
            {
                ret = (long long)ret * cur % M;
            }
            cur = (long long)cur * cur % M;
            y >>= 1;
        }
        return ret;
    }
    
    LL inv(int x) 
    {
        return quickPow(x, M - 2);
    }
    
public:
    Fancy() {
        mul = 1;
        add = 0;
    }
    
    void append(int val) 
    {
        val = (val-add+M) % M;
        val = (val * inv(mul)) % M;
        nums.push_back(val);
    }
    
    void addAll(int inc) 
    {
        add = (add + inc) % M;
    }
    
    void multAll(int m) 
    {
        mul = (mul*m) % M;
        add = (add*m) % M;

    }
    
    int getIndex(int idx) 
    {
        if (idx >= nums.size())
            return -1;
        return (nums[idx]*mul % M + add) % M;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */
