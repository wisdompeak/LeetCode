class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) 
    {
        int result=0;
        for (int i=0; i<points.size(); i++)
        {
            unordered_map<int,int>Map;
            for (int j=0; j<points.size(); j++)
            {
                int dis= (points[i].first-points[j].first)*(points[i].first-points[j].first)+(points[i].second-points[j].second)*(points[i].second-points[j].second);
                Map[dis]++;
            }
            for (auto a:Map)
            {
                result+=a.second*(a.second-1);
            }            
        }
        
        return result;
        
    }
};
