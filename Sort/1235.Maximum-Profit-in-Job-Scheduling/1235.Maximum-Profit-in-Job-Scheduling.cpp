class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) 
    {
        vector<vector<int>>p;
        for (int i=0; i<startTime.size(); i++)
            p.push_back({endTime[i], startTime[i], profit[i]});
        
        sort(p.begin(), p.end());
        vector<pair<int,int>>q;
        q.push_back({0,0});
        
        for (int i=0; i<p.size(); i++)
        {            
            int end = p[i][0];
            int start = p[i][1];
            int pro = p[i][2];
            
            auto iter = upper_bound(q.begin(),q.end(), make_pair(start, INT_MAX));
            iter = prev(iter,1);
            int newPro = iter->second + p[i][2];
            if (q.size()>0 && q.back().second < newPro)
                q.push_back({end, newPro});
        }
        
        return q.back().second;
    }
};
