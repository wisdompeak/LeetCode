class Solution {
    unordered_map<string,vector<string>>Map;
    
public:
    vector<string> findItinerary(vector<vector<string>> tickets) 
    {
        sort(tickets.begin(),tickets.end());
        reverse(tickets.begin(),tickets.end());        
        for (auto ticket: tickets)
            Map[ticket[0]].push_back(ticket[1]);
                
        return DFS("JFK");
    }
    
    vector<string> DFS(string start)
    {
        vector<vector<string>>paths;        
        while (Map[start].size()>0)
        {
            string nextStart = Map[start].back();
            Map[start].pop_back();
            paths.push_back(DFS(nextStart));
        }
        vector<string>ret({start});
        for (int i=paths.size()-1; i>=0; i--)
            for (auto t: paths[i])
                ret.push_back(t);
        return ret;
    }
};
