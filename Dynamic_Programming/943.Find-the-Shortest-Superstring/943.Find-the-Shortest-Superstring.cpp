class Solution {
public:
    string shortestSuperstring(vector<string>& A) 
    {
        int N = A.size();
        auto graph = vector<vector<int>>(N,vector<int>(N));
        for (int i=0; i<N; i++)
            for (int j=0; j<N; j++)
                if (i!=j) graph[i][j]=cal(A[i],A[j]);
        
        int M = 1<<N;
        auto dp = vector<vector<int>>(M,vector<int>(N,INT_MAX/2));
        auto parent = vector<vector<int>>(M,vector<int>(N,-1));
        for (int i=0; i<N; i++)
            dp[1<<i][i] = A[i].size();
                
        for (int mask=0; mask<M; mask++)
            for (int bit=0; bit<N; bit++)
            {
                if ((mask&(1<<bit))==0) continue;
                int pmask = mask^(1<<bit);      
                // we want to update dp[mask][bit] = min_{i}(dp[pmask][i]+graph[i][bit])
                // where bit must be in mask, and i must be within pmask
                
                for (int i=0; i<N; i++)
                {
                    if ((pmask&(1<<i))==0) continue;
                    if (dp[pmask][i]+graph[i][bit]<dp[mask][bit])
                    {
                        dp[mask][bit] = dp[pmask][i]+graph[i][bit];
                        parent[mask][bit] = i;
                    }
                }                    
            }
                
        int start;
        int count = INT_MAX;
        for (int i=0; i<N; i++)
            if (dp[M-1][i]<count)
            {
                count = dp[M-1][i];
                start = i;
            }
        
        int mask = M-1;
        vector<int>path({start});
        while (parent[mask][start]!=-1)
        {
            int next = parent[mask][start];
            path.push_back(next);
            mask = mask^(1<<start);
            start = next;
        }
        
        reverse(path.begin(),path.end());
        string result = A[path[0]];
        for (int i=1; i<path.size(); i++)
            result = combine(result,A[path[i]]);
        
        return result;
        
    }
    
    int cal(string S, string T)
    {
        for (int k=min(S.size(), T.size()); k>=0; k--)
        {
            if (S.substr(S.size()-k)==T.substr(0,k))
                return T.size()-k;
        }
        return 0;
    }
    
    string combine(string S, string T)
    {
        for (int k=min(S.size(), T.size()); k>=0; k--)
        {
            if (S.substr(S.size()-k)==T.substr(0,k))
                return S+T.substr(k);
        }
        return S+T;
    }
};
