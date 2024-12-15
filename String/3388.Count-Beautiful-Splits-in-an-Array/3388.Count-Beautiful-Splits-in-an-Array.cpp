using LL = long long;

class Solution {
    const LL P = 53; 
    const LL M = 1e9 + 7; 
    
    LL get_hash(const vector<LL>& prefix_hash, const vector<LL>& p_powers, int i, int j) 
    {
        return (prefix_hash[j] - (prefix_hash[i-1] * p_powers[j-i+1]) % M + M) % M;
    }
    
public:
    int beautifulSplits(vector<int>& nums) 
    {
        int n = nums.size();
        nums.insert(nums.begin(), 0);
        int count = 0;
        
        vector<LL> prefix_hash(n+1, 0); 
        vector<LL> p_powers(n+1, 1); 
        
        for (int i = 1; i <= n; i++) 
        {
            prefix_hash[i] = (prefix_hash[i - 1] * P + nums[i]) % M;
            p_powers[i] = (p_powers[i - 1] * P) % M;
        }        
                        
        for (int i = 2; i < n; i++) 
            for (int j = i + 1; j <= n; j++) 
            {  
                LL nums1_hash = get_hash(prefix_hash, p_powers, 1, i-1);
                LL nums2_hash = get_hash(prefix_hash, p_powers, i, j-1);
                int len1 = i-1;
                int len2 = j-i;
                int len3 = n-j+1;

                int flag =0;
                if ((len2>=len1) && nums1_hash == get_hash(prefix_hash, p_powers, i, i+len1-1))
                    flag = 1;                               
                
                if (len3>=len2 && nums2_hash == get_hash(prefix_hash, p_powers, j, j+len2-1)) 
                    flag = 1;
                count += flag;
            }
        
        return count;
    }
};
