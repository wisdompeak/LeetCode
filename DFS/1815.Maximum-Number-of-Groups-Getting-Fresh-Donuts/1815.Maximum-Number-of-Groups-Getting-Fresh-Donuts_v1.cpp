typedef long long LL;
class Solution {    
    array<int, 10>count;
    int b, n;
public:
    int maxHappyGroups(int batchSize, vector<int>& groups) 
    {
        b = batchSize;                
        n = groups.size();

        for (int i=0; i<10; i++)
            count[i] = 0;
        for (auto x: groups)
            count[x%batchSize]++;
                
        return dfs(count, 0, 0);
    }
    
    int dfs(array<int, 10>&count, int presum, int i)
    {
        if (i==n) 
            return 0;

        int bonus = (presum % b == 0);
        int ret = 0;
        for (int j=0; j<b; j++)
        {
            if (count[j]==0) continue;
            count[j]--;
            ret = max(ret, dfs(count, (presum+j) % b, i+1));
            count[j]++;
        }

        return ret + bonus;
    }
};
