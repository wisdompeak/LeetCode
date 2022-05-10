class Solution {
    static bool cmp(pair<int,int>&a, pair<int,int>&b)
    {
        if (a.first!=b.first)
            return a.first <b.first;
        else
            return a.second > b.second;
    }
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        vector<pair<int,int>>diff;
        for (auto& interval: intervals)
        {
            diff.push_back({interval[0], 1});
            diff.push_back({interval[1], -1});
        }

        sort(diff.begin(), diff.end(), cmp);
        
        vector<vector<int>>rets;
        int start = 0, end = 0;   
        int sum = 0;
        for (int i=0; i<diff.size(); i++)
        {            
            if (sum==0 && diff[i].second > 0)
            {
                start = diff[i].first;                
            }
            else if (sum > 0 && sum + diff[i].second == 0)
            {
                end = diff[i].first;
                rets.push_back({start,end});
            }
            sum += diff[i].second;            
        }

        return rets;
    }
};
