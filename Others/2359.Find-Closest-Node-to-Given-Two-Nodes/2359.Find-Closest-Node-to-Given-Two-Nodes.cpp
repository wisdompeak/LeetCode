class Solution {
public:
    vector<int>getDist(vector<int>& edges, int node)
    {
        int n = edges.size();
        vector<int>dist(n, -1);
        int i = node;
        dist[i] = 0;
        while (edges[i]!=-1 && dist[edges[i]]==-1)
        {
            int j = edges[i];
            dist[j] = dist[i] + 1;
            i = j;
        }
        return dist;
    }
    
    int closestMeetingNode(vector<int>& edges, int node1, int node2) 
    {
        int n = edges.size();
        
        vector<int>dist1 = getDist(edges, node1);
        vector<int>dist2 = getDist(edges, node2);
        
        
        int ret = INT_MAX;
        int ans = -1;
        for (int i=0; i<n; i++)
        {
            if (dist1[i]!=-1 && dist2[i]!=-1)
            {
                if (max(dist1[i], dist2[i])<ret)
                {
                    ret = max(dist1[i], dist2[i]);
                    ans = i;
                }
                else if (max(dist1[i], dist2[i]) == ret)                
                    ans = min(ans, i);
            }
        }
        if (ret!=INT_MAX)
            return ans;
        else
            return -1;
    }
};
