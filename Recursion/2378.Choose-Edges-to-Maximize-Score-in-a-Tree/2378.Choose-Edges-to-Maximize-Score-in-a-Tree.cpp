using LL = long long;
class Solution {
    vector<pair<int,LL>>children[100005];
    LL memo[100005][2];
public:
    long long maxScore(vector<vector<int>>& edges) 
    {
        int n = edges.size();
        int root = -1;
        for (int i=0; i<n; i++)
        {
            if (edges[i][0]==-1) 
            {
                root = i;
                continue;
            }
            int par = edges[i][0];
            int weight = edges[i][1];
            children[par].push_back({i, weight});
        }
        
        return dfs(root, 0);        
    }
    
    LL dfs(int node, int status)
    {
        if (memo[node][status]!=0)
            return memo[node][status];
        
        if (status == 0)
        {
            LL sum = 0;
            for (auto& [child, weight]: children[node])
                sum += dfs(child, 0);
            
            LL maxSum = sum;
            for (auto& [child, weight]: children[node])
                maxSum = max(maxSum, sum - dfs(child, 0) + dfs(child, 1) + weight);                
            
            memo[node][0] = maxSum;
            return maxSum;
        }
        else
        {
            LL sum = 0;
            for (auto& [child, weight]: children[node])
                sum += dfs(child, 0);
            memo[node][1] = sum;
            return sum;
        }
    }
};
