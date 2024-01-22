using LL = long long;
class Solution {
public:
    vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& removeQueries) 
    {
        int n = nums.size();
        map<LL, LL>Map;  // start->end
        multiset<LL>Set;  // segment sum
        
        vector<LL>presum(n);
        for (int i=0; i<n; i++)
            presum[i] = (i==0?0:presum[i-1]) + nums[i];
        
        Map[0] = n-1;
        Set.insert(presum[n-1]);
        
        vector<LL>rets;
        
        for (int t: removeQueries)
        {
            auto iter = Map.upper_bound(t);
            iter = prev(iter);
            
            int start = iter->first;
            int end = iter->second;
            
            Map.erase(start);
            LL sum = presum[end] - (start==0?0:presum[start-1]);
            Set.erase(Set.lower_bound(sum));
            
            if (start <= t-1)
            {
                Map[start] = t-1;
                Set.insert(presum[t-1] - (start==0?0:presum[start-1]));                
            }
            
            if (t+1 <= end)
            {
                Map[t+1] = end;
                Set.insert(presum[end] - (t+1==0?0:presum[t+1-1]));                
            }
            
            LL ret = Set.empty()? 0: (*Set.rbegin());
            rets.push_back(ret);
        }
        
        return rets;
        
    }
};
