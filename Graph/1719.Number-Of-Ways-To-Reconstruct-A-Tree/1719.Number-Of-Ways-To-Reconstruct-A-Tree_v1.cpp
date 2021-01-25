class Solution {
    int flag = 1;
    unordered_set<int>nodeSet;
    vector<int> relative[501];
    int isRelative[501][501];    
    vector<int> children[501];    
    unordered_set<int>visited;

public:
    int checkWays(vector<vector<int>>& pairs) 
    {
        for (auto pair: pairs)
        {
            nodeSet.insert(pair[0]);
            nodeSet.insert(pair[1]);                                    
            relative[pair[0]].push_back(pair[1]);
            relative[pair[1]].push_back(pair[0]);
            isRelative[pair[0]][pair[1]] = 1;
            isRelative[pair[1]][pair[0]] = 1;            
        }

        vector<int>nodes(nodeSet.begin(), nodeSet.end());
        sort(nodes.begin(),nodes.end(),[&](int x,int y)->bool{return relative[x].size()<relative[y].size();});

        int root = -1;

        for (int i=0; i<nodes.size(); i++)
        {
            int j = i+1;
            while (j<nodes.size() && !isRelative[nodes[i]][nodes[j]])
                j++;
            if (j<nodes.size())
            {                       
                children[nodes[j]].push_back(nodes[i]);
                if (relative[nodes[j]].size() == relative[nodes[i]].size())
                {
                    flag = 2;
                }
            }
            else
            {
                if (root==-1)
                    root = nodes[i];
                else
                    return 0;
            }                
        }

        dfs(root,0);
        
        return flag;
    }

    int dfs(int cur, int depth)
    {
        if (flag==0) return -1;
        if (visited.find(cur)!=visited.end())
        {
            flag = 0;
            return -1;
        }
        visited.insert(cur);
        int sum = 0;
        for (int child: children[cur])
        {
            sum += dfs(child, depth+1);
        }
        if (sum+depth!=relative[cur].size())
        {
            flag = 0;
            return -1;
        }
        return sum+1;
    }
};
