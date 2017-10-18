class Solution {
    unordered_map<string,vector<string>>next;
    unordered_map<string,double>value;
    unordered_map<string,int>visited;
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) 
    {
        for (int i=0; i<equations.size(); i++)
        {
            next[equations[i].first].push_back(equations[i].second);
            value[equations[i].first+":"+equations[i].second]=values[i];
            next[equations[i].second].push_back(equations[i].first);
            value[equations[i].second+":"+equations[i].first]=1.0/values[i];
            visited[equations[i].first]=0;
            visited[equations[i].second]=0;
        }
        
        vector<double>results;
        
        for (int i=0; i<queries.size(); i++)
        {
            for (auto a:visited)
                visited[a.first]=0;            
            results.push_back(DFS(queries[i].second,queries[i].first));
        }        
        
        return results;
    }
    
    double DFS(string start, string end)
    {
        if (next.find(start)==next.end())
            return -1.0;
        
        if (start==end) 
            return 1.0;
        
        for (auto b: next[start])
        {
            if (visited[b]==1) continue;
         
            visited[b]=1;            
            double temp = DFS(b, end);
            if (temp!=-1.0)             
                return value[b+":"+start] * temp;                            
            visited[b]=0;
        }
        
        return -1.0;
    }
};
