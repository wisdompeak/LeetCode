class Solution {
public:
    double minAreaFreeRect(vector<vector<int>>& points) 
    {
        map<pair<int,int>,vector<pair<int,int>>>Map;
        int N = points.size();
        for (int i=0; i<N; i++)
            for (int j=0; j<N; j++)
            {
                if (i==j) continue;
                int deltaX = points[i][0]-points[j][0];
                int deltaY = points[i][1]-points[j][1];
                Map[{deltaX,deltaY}].push_back({i,j});                
            }
        
        double result = INT_MAX;
        for (auto item : Map)
        {
            for (int m=0; m<item.second.size(); m++)
                for (int n=m+1; n<item.second.size(); n++)
                {
                    int i = item.second[m].first;
                    int j = item.second[m].second;
                    int k = item.second[n].first;
                    
                    int dx1 = points[i][0]-points[j][0];
                    int dy1 = points[i][1]-points[j][1];  //vector {dx1,dy1}
                    int dx2 = points[i][0]-points[k][0];
                    int dy2 = points[i][1]-points[k][1];  //vector {dx2,dy2}
                    
                    if (dx1*dx2+dy1*dy2!=0) continue;
                    
                    double side1 = (points[i][0]-points[j][0])*(points[i][0]-points[j][0]) + (points[i][1]-points[j][1])*(points[i][1]-points[j][1]);
                    double side2 = (points[i][0]-points[k][0])*(points[i][0]-points[k][0]) + (points[i][1]-points[k][1])*(points[i][1]-points[k][1]);
                    
                    double area = sqrt(side1)*sqrt(side2);
                    
                    result = min(result, area);
                }
        }
        
        return result==INT_MAX?0:result;
    }
};
