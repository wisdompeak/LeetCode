class Solution {
    vector<int> children[100000];
    int len[100000];
    int globalRet = 1;
    string s;
public:
    int longestPath(vector<int>& parent, string s) 
    {
        int n = parent.size();
        this->s = s;
        
        for (int i=0; i<n; i++)
        {
            if (parent[i]!=-1)
                children[parent[i]].push_back(i);
        }
        
        dfs(0);
        
        return globalRet;
    }
    
    void dfs(int node)
    {
        if (children[node].size()==0)
        {
            len[node] = 1;
            return;
        }
        
        int ret = 1;
        vector<int>temp;
        for (int child: children[node])
        {
            dfs(child);
            if (s[child]!=s[node])
            {
                ret = max(ret, len[child]+1);
                temp.push_back(len[child]);
            }                
        }
        len[node] = ret; 
        
        sort(temp.rbegin(), temp.rend());
        if (temp.size()>=2)
            globalRet = max(globalRet, temp[0]+temp[1]+1);
        else if (temp.size()==1)
            globalRet = max(globalRet, temp[0]+1);
        else
            globalRet = max(globalRet, 1);        
    }
};
