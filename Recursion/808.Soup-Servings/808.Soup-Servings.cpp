class Solution {
    map<pair<int,int>,double>dp;
public:
    double soupServings(int N) 
    {
        if (N>5000) return 1;
        return DFS(N,N);
    }
    
    double DFS(int A, int B)
    {
        if (A<=0 && B>0) return 1;
        if (A<=0 && B<=0) return 0.5;
        if (A>0 && B<=0) return 0;
        
        if (dp.find(pair<int,int>(A,B))!=dp.end()) return dp[pair<int,int>(A,B)];
        
        dp[pair<int,int>(A,B)] = 0.25*(DFS(A-100,B)+DFS(A-75,B-25)+DFS(A-50,B-50)+DFS(A-25,B-75));
        return dp[pair<int,int>(A,B)];
    }
};
