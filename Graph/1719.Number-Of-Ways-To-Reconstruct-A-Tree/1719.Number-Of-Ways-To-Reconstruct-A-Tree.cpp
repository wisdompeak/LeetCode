class Solution {
    int flag = 1;
    unordered_map<int, vector<int>>children;
    unordered_map<int, int>father;
    unordered_map<int, int>depth;
    unordered_map<int, int>childrenCount;

public:
    int checkWays(vector<vector<int>>& pairs) 
    {
        unordered_map<int,int>order;
        unordered_set<int>nodeSet;
        for (auto pair: pairs)
        {
            nodeSet.insert(pair[0]);
            nodeSet.insert(pair[1]);
            order[pair[0]]++;
            order[pair[1]]++;
        }
        unordered_map<int,vector<pair<int,int>>>relative;
        for (auto pair: pairs)
        {
            relative[pair[0]].push_back({order[pair[1]], pair[1]});
            relative[pair[1]].push_back({order[pair[0]], pair[0]});
        }
        
        for (auto node: nodeSet)
        {    
            sort(relative[node].begin(), relative[node].end());
            int i = relative[node].size()-1;
            while (i>=0 && (relative[node][i].first > order[node] || relative[node][i].first == order[node] && relative[node][i].second > node))
            {
                if (relative[node][i].first == order[node] && flag == 1)
                    flag = 2;
                i--;
            }                
            if (i+1>=0 && i+1 < relative[node].size())
            {
                int parent = relative[node][i+1].second;
                children[parent].push_back(node);
                father[node] = parent;
            }            
        }

        int root = -1;
        for (auto node: nodeSet)
        {
            if (father.find(node)==father.end())
            {
                if (root!=-1) return 0;
                root = node;
            }
        }

        unordered_set<int>visited;
        if (dfs(root, visited, 0)==-1)
            return 0;

        for (auto node: nodeSet)
        {
            if (order[node]!=depth[node]+childrenCount[node])
                return 0;
        }
        
        return flag;
    }

    int dfs(int cur, unordered_set<int>&visited, int d)
    {
        if (visited.find(cur)!=visited.end())
            return -1;            
        visited.insert(cur);
        depth[cur] = d;

        int count = 0;
        for (auto next: children[cur])
        {
            int temp = dfs(next, visited, d+1);
            if (temp==-1)
                return -1;
            else
                count+=temp;
        }
        childrenCount[cur] = count;
        return count+1;
    }
};
