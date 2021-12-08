class Solution {
    static bool cmp(pair<int,int>a, pair<int,int>b)
    {
        if (a.first==b.first)
            return a.second<b.second;
        else
            return a.first<b.first;
    }
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) 
    {
        long long area=0;
        unordered_set<string>Set;
        for (int i=0; i<rectangles.size(); i++)
        {
            string str;
            str=to_string(rectangles[i][0]);
            str+=",";
            str+=to_string(rectangles[i][1]);
            if (Set.find(str)==Set.end())
                Set.insert(str);
            else
                Set.erase(str);
            
            str=to_string(rectangles[i][0]);
            str+=",";
            str+=to_string(rectangles[i][3]);
            if (Set.find(str)==Set.end())
                Set.insert(str);
            else
                Set.erase(str);
            
            str=to_string(rectangles[i][2]);
            str+=",";
            str+=to_string(rectangles[i][1]);
            if (Set.find(str)==Set.end())
                Set.insert(str);
            else
                Set.erase(str);
            
            str=to_string(rectangles[i][2]);
            str+=",";
            str+=to_string(rectangles[i][3]);
            if (Set.find(str)==Set.end())
                Set.insert(str);
            else
                Set.erase(str);         
            
            area+= (long long)(rectangles[i][3]-rectangles[i][1])*(long long)(rectangles[i][2]-rectangles[i][0]);
        }
        
        if (Set.size()!=4) return false;
        
        vector<pair<int,int>>points;
        for (auto a:Set)
        {
            int i=0;
            while (a[i]!=',') i++;
            int x = stoi(a.substr(0,i));
            int y = stoi(a.substr(i+1));
            points.push_back({x,y});
        }
        
        sort(points.begin(),points.end(),cmp);
        
        long long A=(long long)(points[3].second-points[0].second)*(long long)(points[3].first-points[0].first);
        
        return (A==area);
        
    }
};
