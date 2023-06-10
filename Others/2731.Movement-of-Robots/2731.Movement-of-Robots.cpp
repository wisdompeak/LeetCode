using LL = long long;
LL M = 1e9+7;
class Solution {
public:
    int sumDistance(vector<int>& nums, string s, int d) 
    {
        int n = nums.size();
        vector<LL>pos;               
        for (int i=0; i<n; i++)
        {
            LL p;
            if (s[i]=='L')
                p = nums[i] - d;
            else
                p = nums[i] + d;
            pos.push_back(p);
        }
        sort(pos.begin(), pos.end());
        
        LL ret = 0;
        for (int i=0; i+1<n; i++)
        {
            LL s = (pos[i+1]-pos[i]) % M;
            ret += s * (i+1) % M * (n-1-i) % M;
            ret %= M;
        }
      
        return ret;
    }
};
