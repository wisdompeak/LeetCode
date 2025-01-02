class Solution {
public:
    int getKey(int x, int y)
    {
        int g = gcd(x,y);
        x = x/g;
        y = y/g;
        return x*1000+y;
    }

    long long numberOfSubsequences(vector<int>& nums) 
    {
        unordered_map<int, vector<int>>Map;
        int n = nums.size();
        for (int i=0; i<n; i++) 
            for (int j=i+2; j<n; j++)
                Map[getKey(nums[i], nums[j])].push_back(i);

        for (auto& [k,v]: Map)
            sort(v.begin(), v.end());

        long long ret = 0;
        for (int p=0; p<n; p++)
            for (int q=p+2; q<n; q++)
            {
                int key = getKey(nums[q], nums[p]);
                if (Map.find(key)==Map.end()) continue;
                auto iter = lower_bound(Map[key].begin(), Map[key].end(), q+2);
                ret += Map[key].end()- iter;
            }
        return ret;
    }
};
