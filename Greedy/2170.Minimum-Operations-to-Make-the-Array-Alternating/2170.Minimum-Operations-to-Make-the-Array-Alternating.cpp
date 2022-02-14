class Solution {
    static bool cmp(pair<int,int>&a,pair<int,int>&b)
    {
        return a.second > b.second;
    }
public:
    int minimumOperations(vector<int>& nums) 
    {
        int n = nums.size();
        if (n==1) return 0;
        
        unordered_map<int,int>Map1;
        unordered_map<int,int>Map2;
        int count1 = 0, count2 = 0;
        for (int i=0; i<n; i+=2)
        {
            Map1[nums[i]]++;
            count1++;
        }
        for (int i=1; i<n; i+=2)
        {
            Map2[nums[i]]++;
            count2++;
        }
        
        vector<pair<int,int>>temp2(Map2.begin(), Map2.end());
        sort(temp2.begin(), temp2.end(), cmp);
        
        int ret = n;
        for (auto& x: Map1)
        {            
            int key = x.first, freq = x.second;
            int ans = count1-freq;
            
            if (temp2[0].first == key)
                ans += count2 - (temp2.size()==1?0:temp2[1].second);
            else
                ans += count2 - temp2[0].second;
            
            ret = min(ret, ans);
        }
        
        return ret;
    }
};
