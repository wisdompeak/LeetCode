using LL = long long;
class Solution {    
    int n;
public:
    long long countSubstrings(string s) 
    {
        n = s.size();
        vector<int>nums;
        for (auto ch: s)
            nums.push_back(ch-'0');
        nums.insert(nums.begin(), 0);
        
        LL ret = 0;
        for (int k=1; k<=9; k++)
            ret += helper(nums, k);        
        return ret;
    }
    
    LL helper(vector<int>&nums, int k)
    {        
        vector<LL>count(k, 0);
        vector<LL>count2(k,0);
        LL ret = 0;
        
        int r = 0;
        count[0] = 1;
        for (int i=1; i<=n; i++)
        {                        
            for (int d=0; d<k; d++)
                count2[d] = 0;
            for (int d=0; d<k; d++)
                count2[(d*10)%k]+=count[d];
            count = count2;
            
            r = (r*10+nums[i])%k;
            if (nums[i]==k)            
                ret += count[r];            
            count[r]+=1;
        }

        return ret;
    }
};
