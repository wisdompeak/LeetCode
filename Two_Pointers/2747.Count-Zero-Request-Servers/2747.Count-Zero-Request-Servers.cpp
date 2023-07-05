class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) 
    {               
        for (int i=0; i<logs.size(); i++)
            logs[i] = {logs[i][1], logs[i][0]};        
        sort(logs.begin(), logs.end());
        
        vector<vector<int>>q;
        for (int i=0; i<queries.size(); i++)
            q.push_back({queries[i], i});        
        sort(q.begin(), q.end());
        
        int k = 0;
        
        vector<int>rets(q.size());
        unordered_map<int,int>Map;
        int i = 0;
        int j = 0;
        for (auto qq: q)
        {
            int t = qq[0], idx = qq[1];
            while (j<logs.size() && logs[j][0]<=t)
            {
                Map[logs[j][1]]++;
                j++;
            }
            while (i<logs.size() && logs[i][0]<t-x)
            {
                Map[logs[i][1]]--;
                if (Map[logs[i][1]]==0)
                    Map.erase(logs[i][1]);
                i++;
            }
            rets[idx] = n - Map.size();
        }
        return rets;
    }
};
