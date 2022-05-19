class Solution {
public:
    vector<vector<int>> averageHeightOfBuildings(vector<vector<int>>& buildings) 
    {
        map<int, pair<int,int>>Map; // pos -> {diffHeight, diffCount}
        for (auto build: buildings)
        {
            int s = build[0], e = build[1], h = build[2];
            Map[s].first += h;
            Map[s].second += 1;
            Map[e].first -= h;
            Map[e].second -= 1;
        }
        
        vector<pair<int,int>>seg;
        int totalHeight = 0, totalCount = 0;
        for (auto& [pos, kv]: Map)
        {
            int diffHeight = kv.first, diffCount = kv.second;
            totalHeight += diffHeight;
            totalCount += diffCount;
            int avg = (totalCount ==0 ? 0: totalHeight / totalCount);
            seg.push_back({pos, avg});
        }
        
        vector<vector<int>>rets;
        for (int i=0; i<seg.size(); i++)
        {
            if (seg[i].second == 0) continue;
            int j = i;
            while (j<seg.size() && seg[j].second == seg[i].second)
                j++;
            rets.push_back({seg[i].first, seg[j].first, seg[i].second});
            i = j-1;
        }
        
        return rets;
    }
};
