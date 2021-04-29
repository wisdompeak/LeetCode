class Solution {
    static bool cmp(pair<int,int>a, pair<int,int>b)
    {
        if (a.first==b.first)
            return a.second > b.second;
        else
            return a.first<b.first;
    }
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) 
    {
        vector<pair<int,int>>p;
        for (auto x: slots1)
        {
            p.push_back({x[0],1});
            p.push_back({x[1],-1});
        }
        for (auto x: slots2)
        {
            p.push_back({x[0],1});
            p.push_back({x[1],-1});
        }
        sort(p.begin(),p.end(),cmp);
        
        int count = 0;
        int start;
        vector<int>ret;
        for (int i=0; i<p.size(); i++)
        {
            count += p[i].second;
            if (p[i].second==1 && count==2)
            {
                start = p[i].first;
            }
            else if (p[i].second==-1 && count==1 && p[i].first-start>=duration)
            {
                ret={start,start+duration};
                return ret;
            }
        }
        return {};
            
    }
};
