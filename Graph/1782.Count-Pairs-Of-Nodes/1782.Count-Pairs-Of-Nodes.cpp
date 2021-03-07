class Solution {
public:
    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) 
    {
        vector<int>count(n);
        unordered_map<long, int>edgeCount;             
        long M = 20001;
        
        for (auto edge: edges)
        {
            int a = min(edge[0]-1, edge[1]-1);
            int b = max(edge[0]-1, edge[1]-1);
            count[a]++;
            count[b]++;
            edgeCount[a*M+b]++;
        }
               
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
                        
            for (auto [edgeIdx, cnt]:edgeCount)
            {
                int a = edgeIdx/M;
                int b = edgeIdx%M;
                if (count[a]+count[b]>q && count[a]+count[b]-cnt<=q)
                {
                    sum--;
                }
            }
            rets.push_back(sum);
        }        
        
        return rets;

    }
};
