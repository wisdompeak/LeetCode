class Solution {
    static bool cmp(pair<int,int>&a, pair<int,int>&b)
    {
        return a.first+a.second<b.first+b.second;
    }
public:
    int minMoves(vector<int>& nums, int limit) 
    {
        int n = nums.size()/2;
        vector<pair<int,int>>p;
        for (int i=0; i<n; i++)
            p.push_back({min(nums[i],nums[2*n-1-i]), max(nums[i],nums[2*n-1-i])});
        
        sort(p.begin(), p.end(), cmp);
        
        vector<int>left(n);
        vector<int>right(n);
        multiset<int>Set;
        int count = 0;
        int same = 0;
        
        for (int i=0; i<n; i++)
        {
            int sum = p[i].first+p[i].second;
            if (i>0 && sum==p[i-1].first+p[i-1].second)
                same++;
            else
                same = 0;
            
            while (!Set.empty() && *Set.begin() < sum)
            {
                Set.erase(Set.begin());
                count++;
            }
            left[i] = i-count-same + count*2;
            Set.insert(p[i].second+limit);
        }
        
        Set.clear();
        count = 0;
        same = 0;
        
        for (int i=n-1; i>=0; i--)
        {
            int sum = p[i].first+p[i].second;
            if (i<n-1 && sum==p[i+1].first+p[i+1].second)
                same++;
            else
                same = 0;
            
            while (!Set.empty() && *Set.rbegin() > sum)
            {
                auto iter = Set.end();
                Set.erase(prev(iter));
                count++;
            }
            right[i] = n-1-i-count-same + count*2;
            Set.insert(p[i].first+1);
        }
        
        int ret = INT_MAX;
        for (int i=0; i<n; i++)
            ret = min(ret, left[i]+right[i]);
        return ret;
        
    }
};
