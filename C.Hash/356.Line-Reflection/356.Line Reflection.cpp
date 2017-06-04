class Solution {
public:
    bool isReflected(vector<pair<int, int>>& points) 
    {
        
        int N=points.size();
        if (N==0) return true;
        
        unordered_map<int,set<int>>Map;
        unordered_set<int>Set;
        for (int i=0; i<N; i++)
        {
            Map[points[i].second].insert(points[i].first);
            Set.insert(points[i].first);
        }
        
        float x0=0;
        for (auto a:Set)
            x0+=a;
        x0=x0/Set.size();
        
        for (auto a:Map)
        {
            vector<int>q(a.second.begin(),a.second.end());
            int i=0;
            int j=q.size()-1;
            while (i<=j)
            {
                if (q[i]+q[j]!=x0*2)
                    return false;
                i++;
                j--;
            }
        }
        
        return true;
    }
};
