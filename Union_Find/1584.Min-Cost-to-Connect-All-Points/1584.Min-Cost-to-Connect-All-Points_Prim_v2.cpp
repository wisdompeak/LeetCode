class Solution {   
    int visited[1000];
public:
    int minCostConnectPoints(vector<vector<int>>& points) 
    {
        int n = points.size();
        if (n==1) return 0;
        
        vector<int>minDist(n,INT_MAX);  // the min dist from point i to the current MST                
        minDist[0] = 0;
                
        int ret = 0;
        int cur = 0;
        for (int k=0; k<n; k++)
        {
            int next;
            int gmin = INT_MAX;
            for (int j = 0; j < n; ++j) {
                if (visited[j]==0 && minDist[j] <= gmin) 
                {
                    gmin = minDist[j];
                    next = j;
                }
            }
            visited[next] = 1;
            ret += gmin;
            
            for (int j = 0; j < n; ++j) 
                if (visited[j] == 0) 
                {
                    int new_dist = abs(points[j][0] - points[next][0]) + abs(points[j][1] - points[next][1]);
                    minDist[j] = min(minDist[j], new_dist);
                }
        }                
        return ret;        
    }
};
