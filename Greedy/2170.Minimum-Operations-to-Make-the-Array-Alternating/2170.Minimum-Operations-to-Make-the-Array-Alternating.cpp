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
        
        vector<pair<int,int>>temp1(Map1.begin(), Map1.end());        
        vector<pair<int,int>>temp2(Map2.begin(), Map2.end());
        sort(temp1.begin(), temp1.end(), cmp);
        sort(temp2.begin(), temp2.end(), cmp);
        
        if (temp1.size()==1) temp1.push_back({0,0});
        if (temp2.size()==1) temp2.push_back({0,0});
                
        if (temp1[0].first!=temp2[0].first)
            return n - temp1[0].second - temp2[0].second;
        else
        {
            int x = count1 - temp1[0].second + count2 - temp2[1].second;
            int y = count1 - temp1[1].second + count2 - temp2[0].second;
            return min(x,y);
        }
    }
};
