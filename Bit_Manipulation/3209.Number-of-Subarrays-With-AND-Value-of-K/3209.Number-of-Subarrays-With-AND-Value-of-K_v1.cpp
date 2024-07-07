class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) 
    {
        map<int, long long> mp, temp;
        long long ans = 0;
        for(int x: nums)
        {
            for(auto& [k,v]: mp)
                temp[k & x] += v;
            temp[x]++;

            if(temp.find(k) != temp.end()) 
                ans += temp[k];
            
            mp = temp;
            temp.clear();
        }
        return ans;
    }
};
