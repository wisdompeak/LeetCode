  
class Solution {
    unordered_map<string,queue<string>>Map;
    
public:
    vector<string> findItinerary(vector<vector<string>> tickets) 
    {
        sort(tickets.begin(),tickets.end());
        for (auto ticket: tickets)
            Map[ticket[0]].push(ticket[1]);
        
        vector<string> path;
        DFS("JFK",path);
        reverse(path.begin(),path.end());
        return path;
    }
    
    void DFS(string start, vector<string>& path)
    {
        while (Map[start].size()>0)
        {
            string nextStart = Map[start].front();
            Map[start].pop();
            DFS(nextStart, path);
        }
        path.push_back(start);
    }
};
