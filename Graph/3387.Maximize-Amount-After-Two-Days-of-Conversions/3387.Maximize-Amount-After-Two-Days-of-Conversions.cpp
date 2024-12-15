class Solution {
    unordered_map<string,int>name2idx;
public:
    double maxAmount(string initialCurrency, vector<vector<string>>& pairs1, vector<double>& rates1, vector<vector<string>>& pairs2, vector<double>& rates2) 
    {
        unordered_set<string>Set;
        for (auto pair: pairs1)
        {
            Set.insert(pair[0]);
            Set.insert(pair[1]);
        }
        for (auto pair: pairs2)
        {
            Set.insert(pair[0]);
            Set.insert(pair[1]);
        }
        int idx = 0;
        for (string s: Set)
            name2idx[s] = idx++;
            
        
        int n = name2idx.size();
        vector<vector<double>> dist1 = floyd(pairs1, rates1);
        vector<vector<double>> dist2 = floyd(pairs2, rates2);
        
        int s = name2idx[initialCurrency];
        double ret = 1.0;
        for (int i=0; i<n; i++)
            ret = max(ret, 1.0*dist1[s][i]*dist2[i][s]);
        return ret;
    }
    
    vector<vector<double>> floyd(vector<vector<string>>& pairs, vector<double>& rates)
    {
        int n = name2idx.size();
        vector<vector<double>>dist(n, vector<double>(n,0));
        for (int i=0; i<n; i++)
            dist[i][i] = 1.0;
        for (int i=0; i<rates.size(); i++)
        {
            int a = name2idx[pairs[i][0]];
            int b = name2idx[pairs[i][1]];
            double t = rates[i];
            
            for (int i=0; i<n; i++)
                for (int j=0; j<n; j++)
                {
                    dist[i][j] = max(dist[i][j], dist[i][a]*t*dist[b][j]);
                    dist[i][j] = max(dist[i][j], dist[i][b]*1.0/t*dist[a][j]);
                    
                    dist[j][i] = max(dist[j][i], dist[j][a]*t*dist[b][i]);
                    dist[j][i] = max(dist[j][i], dist[j][b]*1.0/t*dist[b][i]);
                }                        
        }
        return dist;
    }
    
    
};
