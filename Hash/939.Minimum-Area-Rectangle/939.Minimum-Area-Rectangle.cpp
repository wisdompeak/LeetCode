class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) 
    {
        unordered_map<int, unordered_set<int>>Map;
        for (auto p: points)
            Map[p[0]].insert(p[1]);
        
        int ret = INT_MAX;
        for (int i=0; i<points.size(); i++)
            for (int j=i+1; j<points.size(); j++)
            {
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];
                
                if (x1==x2 || y1==y2) continue;
                
                int x3 = x2;
                int y3 = y1;
                int x4 = x1;
                int y4 = y2;
                
                if (Map[x3].find(y3)==Map[x3].end())
                    continue;
                if (Map[x4].find(y4)==Map[x4].end())
                    continue;
                
                ret = min(ret, abs(x2-x1)*abs(y1-y2));
            }
        
        return ret==INT_MAX? 0:ret;
        
    }
};
