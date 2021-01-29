class Solution {
    int dp[1000][1001];
    vector<int>blocks;
    int n;
    int split;
public:
    int minBuildTime(vector<int>& blocks, int split) 
    {
        n = blocks.size();
        sort(blocks.begin(), blocks.end(), greater<int>());        
        this->blocks = blocks;
        this->split = split;
        
        for (int i=0; i<1000; i++)
            for (int j=0; j<1001; j++)
                dp[i][j] = -1;
        
        return dfs(0, 1);
    }

    int dfs(int i, int j) // the min time to use j workers to finish blocks[i:end]
    {
        if (i == n) return 0; // we are done with all jobs
        if (j == 0) return INT_MAX/2; // we do not have any workers to move on
        if (j > n-i) return blocks[i]; // we have enough workers to start all remaining jobs simutaneously
        if (dp[i][j] != -1) return dp[i][j];
        
        dp[i][j] = min(split + dfs(i, j*2), max(blocks[i], dfs(i+1, j-1)));
        
        return dp[i][j];
    }
};
