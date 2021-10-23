class Solution {
public:
    vector<vector<int>> averageHeightOfBuildings(vector<vector<int>>& buildings) 
    {
        vector<pair<int,int>>p;
        for (auto build: buildings)
        {
            int start = build[0], end = build[1], height = build[2];            
            p.push_back({start, height});
            p.push_back({end, -height});
        }
        
        sort(p.begin(), p.end());
        int count = 0;
        int sum = 0;
        
        vector<pair<int,int>>temp;
        for (int i=0; i<p.size(); i++)
        {
            int j = i;
            while (j<p.size() && p[j].first==p[i].first)
            {
                auto [pos, h] = p[j];
                if (h<0)
                {
                    count--;
                    sum -= (-h);
                }                    
                else
                {
                    count++;
                    sum += h;
                }            
                j++;
            }
            int avg = count==0 ? 0 : sum / count;
            temp.push_back({p[i].first, avg});
            i = j-1;
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
