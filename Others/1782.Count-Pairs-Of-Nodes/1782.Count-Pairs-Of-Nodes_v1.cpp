class Solution {
public:
    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) 
    {
        vector<int>count(n);
        vector<unordered_map<int,int>>num(n);                
        
        for (auto edge: edges)
        {
            int a = min(edge[0]-1, edge[1]-1);
            int b = max(edge[0]-1, edge[1]-1);
            count[a]++;
            count[b]++;
            num[a][b]++;            
        }
        
        vector<vector<int>> edges2;
        for (int i=0; i<n; i++)
            for (auto [j, k]: num[i])
                edges2.push_back({i,j});
        
        auto count2 = count;
        sort(count2.begin(), count2.end());
        
        vector<int>rets;
        for (int q: queries)
        {
            int sum = 0;
            int j = n-1;
            for (int i=0; i<n; i++)
            {
                if (i>=j)
                {
                    sum += n-i-1;
                }
                else
                {
                    while (i<j && count2[i]+count2[j] > q)
                        j--;
                    sum += n-j-1;                    
                }                
            }
                        
            for (auto edge:edges2)
            {
                int a = min(edge[0], edge[1]);
                int b = max(edge[0], edge[1]);
                if (count[a]+count[b]>q && count[a]+count[b]-num[a][b]<=q)
                {
                    sum--;
                }
            }
            rets.push_back(sum);
        }        
        
        return rets;        
    }
};
