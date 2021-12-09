class Solution {
    unordered_map<int,vector<int>>Map;
    unordered_map<int,int>in;
    unordered_map<int,int>out;

public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) 
    {
        
        for (auto pair: pairs)
        {
            Map[pair[0]].push_back(pair[1]);
            in[pair[1]]++;
            out[pair[0]]++;
        }
        
        int start = -1;
        for (auto x: Map)
        {
            int p = x.first;
            if (out[p]-in[p]==1)
                start = p;            
        }
        
        if (start==-1) 
            start = pairs[0][0];
        
        vector<int>path;
        DFS(start, path);
        reverse(path.begin(), path.end());
        
        vector<vector<int>>rets;
        for (int i=0; i<path.size()-1; i++)
            rets.push_back({path[i], path[i+1]});
        return rets;                
    }

    
    void DFS(int start, vector<int>& path)
    {
        while (Map[start].size()>0)
        {
            int nextStart = Map[start].back();
            Map[start].pop_back();
            DFS(nextStart, path);
        }
        path.push_back(start);
    }
};
