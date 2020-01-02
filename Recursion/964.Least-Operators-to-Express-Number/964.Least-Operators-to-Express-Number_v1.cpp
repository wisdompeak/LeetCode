class Solution {
    map<vector<long>,int>Map;
public:
    int leastOpsExpressTarget(int x, int target) 
    {
        int T = log(target)/log(x)+1;
        return DFS(x, target, T)-1;
    }

    int DFS(long x, long target, int k)
    {
        if (k==0)
            return target*2;
        
        if (Map.find({target,k})!=Map.end())
            return Map[{target,k}];

        int a = target / pow(x, k);
        int ans1 = a*k + DFS(x, target-a*pow(x,k), k-1);
        int ans2 = (a+1)*k + DFS(x, (a+1)*pow(x,k)-target, k-1);
        
        Map[{target,k}] = min(ans1,ans2);
        return min(ans1, ans2);

    }
};
