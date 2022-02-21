class Solution {
public:
    long long countPairs(vector<int>& nums, int k) 
    {
        unordered_set<int>yueshu;
        for (int i=1; i*i<=k; i++)
        {
            if (k%i!=0) continue;
            yueshu.insert(i);
            if (i*i!=k)
                yueshu.insert(k/i);
        }

        unordered_map<int, vector<int>>Map;
        for (int i=0; i<nums.size(); i++)
            for (auto x: yueshu)
            {
                if (nums[i]%x==0)
                    Map[x].push_back(i);
            }
        
        long long ret = 0;
        for (int i=0; i<nums.size(); i++)
        {
            int a = gcd(nums[i], k);
            int b = k/a;
            auto iter = upper_bound(Map[b].begin(), Map[b].end(), i);
            ret += Map[b].end() - iter;
        }

        return ret;
        
    }
};
