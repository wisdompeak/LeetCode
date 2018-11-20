class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) 
    {
        int N = A.size();
        vector<pair<int,int>>LA;
        vector<pair<int,int>>LB;
        for (int i=0; i<N; i++)
            for (int j=0; j<N; j++)
            {
                if (A[i][j]==1) LA.push_back({i,j});
                if (B[i][j]==1) LB.push_back({i,j});
            }
        map<pair<int,int>,int>count;        
        for (int i=0; i<LA.size(); i++)
            for (int j=0; j<LB.size(); j++)            
                count[{LB[j].first-LA[i].first,LB[j].second-LA[i].second}]++;                
        int result = 0;
        for (auto a:count) result = max(result,a.second);
        return result;
    }
};
