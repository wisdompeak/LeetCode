class Solution {
    unordered_map<string,queue<string>>Map;
    
public:
    vector<string> findItinerary(vector<vector<string>> tickets) 
    {
        sort(tickets.begin(),tickets.end());
        for (auto ticket: tickets)
            Map[ticket[0]].push(ticket[1]);
                
        return DFS("JFK");
    }
    
    vector<string> DFS(string start)
    {
        vector<vector<string>>paths;        
        while (Map[start].size()>0)
        {
            string nextStart = Map[start].front();
            Map[start].pop();
            paths.push_back(DFS(nextStart));
        }
        vector<string>ret({start});
        for (int i=paths.size()-1; i>=0; i--)
            for (auto t: paths[i])
                ret.push_back(t);
        return ret;
    }
};
