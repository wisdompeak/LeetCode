class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) 
    {
        vector<int>rets;
        for (int i=0; i<nums.size(); i++)
        {
            int x = nums[i];
            while (!rets.empty() && gcd(rets.back(), x)>1)
            {
                x = lcm(rets.back(), x);
                rets.pop_back();                
            }
            rets.push_back(x);
        }
        return rets;        
    }

    long long lcm(long long a, long long b)
    {
        return (long long)a*(long long)b/gcd(a,b);
    }
};
