class Solution {
    
public:
    static bool cmp(pair<int,int>a, pair<int,int>b)
    {
        if (a.first!=b.first)
            return a.first<b.first;
        else
            return a.second>=b.second;
    }
    
    int maxEnvelopes(vector<pair<int, int>>& envelopes) 
    {
        sort(envelopes.begin(),envelopes.end(),cmp);
        
        vector<int>q;
        
        for (int i=0; i<envelopes.size(); i++)
        {
            if (q.empty())
                q.push_back(envelopes[i].second);
            else
            {
                if (envelopes[i].second>q.back())
                    q.push_back(envelopes[i].second);
                else
                {
                    auto pos = lower_bound(q.begin(),q.end(),envelopes[i].second);
                    *pos = envelopes[i].second;
                }
            }
        }
        
        return q.size();
        
    }
};
