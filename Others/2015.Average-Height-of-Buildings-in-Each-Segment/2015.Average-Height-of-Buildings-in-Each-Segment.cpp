class Solution {
public:
    vector<vector<int>> averageHeightOfBuildings(vector<vector<int>>& buildings) 
    {
        map<int,pair<int,int>>Map; // pos=>{sum, count}
        for (auto build: buildings)
        {
            int start = build[0], end = build[1], height = build[2];            
            Map[start].first += height;
            Map[start].second += 1;
            Map[end].first -= height;
            Map[end].second -= 1;
        }                        
        
        int sum = 0;
        int count = 0;
        vector<pair<int,int>>temp;        
        for (auto& [pos, kv]: Map)
        {
            int heightDiff = kv.first, countDiff = kv.second;
            sum += heightDiff;
            count += countDiff;
            int avg = (count==0 ? 0 : sum / count);
            temp.push_back({pos, avg});            
        }        
        
        vector<vector<int>>rets;
        for (int i=0; i<temp.size(); i++)
        {
            if (temp[i].second==0) continue;
            int j = i;
            while (j<temp.size() && temp[j].second == temp[i].second)
                j++;
            rets.push_back({temp[i].first, temp[j].first, temp[i].second});
            i = j-1;            
        }
        return rets;
        
    }
};
