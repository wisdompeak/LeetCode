typedef long long LL;
class Solution {    
    int count[10];
    int b, n;
    unordered_map<LL, int>memo;    
public:
    int maxHappyGroups(int batchSize, vector<int>& groups) 
    {
        b = batchSize;                
        n = groups.size();

        for (auto x: groups)
            count[x%batchSize]++;
                
        return dfs(0, 0, 0);
    }
    
    int dfs(int presum, int prescore, int i)
    {
        if (i==n) 
            return prescore;
        
        if (presum % b == 0)
            prescore++;

        int ret = 0;
        for (int j=0; j<b; j++)
        {
            if (count[j]==0) continue;
            count[j]--;
            ret = max(ret, dfs((presum+j) % b, prescore, i+1));
            count[j]++;
        }
        return ret;
    }
};
