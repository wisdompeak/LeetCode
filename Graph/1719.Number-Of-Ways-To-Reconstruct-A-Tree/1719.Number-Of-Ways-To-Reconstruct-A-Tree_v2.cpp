class Solution {
    int flag = 1;
    unordered_set<int>nodeSet;
    vector<int> relative[501];
    int isRelative[501][501];    

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
                for (auto r: relative[nodes[i]])
                {
                    if (r!=nodes[j] && isRelative[r][nodes[j]]==0)
                        return 0;
                }
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
        return flag;
    }
};
