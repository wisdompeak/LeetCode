class Solution {
public:
    vector<int> maximumSumQueries(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) 
    {
        map<int, set<pair<int,int>>>Map;
        for (int i=0; i<queries.size(); i++)
        {
            int a = queries[i][0], b = queries[i][1];
            Map[a].insert({b, i});
        }
        
        vector<int>rets(queries.size(), -1);
        
        vector<vector<int>>nums;
        for (int i=0; i<nums1.size(); i++)
            nums.push_back({nums1[i]+nums2[i], nums1[i], nums2[i]});
        sort(nums.rbegin(), nums.rend());
        
        for (auto& e: nums)
        {
            int val = e[0], x = e[1], y = e[2];
            auto iter = Map.begin();
            
            while (iter!=Map.end() && iter->first <= x)
            {
                auto iter2 = iter->second.begin();                
                while (iter2 != iter->second.end() && iter2->first <= y)
                {
                    rets[iter2->second] = val;
                    iter->second.erase(iter2++);
                }
                if (iter->second.empty())
                    Map.erase(iter++);
                else
                    iter++;
            }
        }
        
        return rets;
        
    }
};
