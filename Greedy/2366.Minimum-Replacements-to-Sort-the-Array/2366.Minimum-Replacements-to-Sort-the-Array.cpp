using LL = long long;
class Solution {
public:
    long long minimumReplacement(vector<int>& nums) 
    {
        LL ret = 0;
        for (int i = nums.size()-2; i>=0; i--)
        {
            LL x = nums[i+1];
            LL y = nums[i];
            if (y<=x) continue;
            
            LL k = y/x;
            LL d = y%x;
            if (d==0)
            {
                ret += k-1;
                nums[i] = x;
                continue;
            }
                                    
            // d + k*p <= x - p
            LL p = (x-d) / (k+1);
            
            LL x2 = x - p;
            LL d2 = d + k*p;
            
            if (d2 < x2)
            {
                nums[i] = x2-1;                
            }
            else
            {
                nums[i] = d2;
            }
            ret += k;
        }
        
        return ret;
    }
};
