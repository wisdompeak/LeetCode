class Solution {
    vector<int>sufSum;
    map<pair<int,int>,int>Map;
public:
    int stoneGameII(vector<int>& piles) 
    {
        int n = piles.size();
        sufSum.resize(n);
        for (int i=n-1; i>=0; i--)
        {
            if (i==n-1) sufSum[i] = piles.back();
            else sufSum[i] = piles[i]+sufSum[i+1];
        }
                           
        int M = 1;
        return dfs(piles,0,M);
    }
    
    int dfs(vector<int>& piles, int start, int M)
    {                
        if (start>=piles.size()) return 0;
        if (Map.find({start,M})!=Map.end())
            return Map[{start,M}];       
       
        int sum = 0;
        int best = 0;
        for (int i=start; i<start+2*M; i++)
        {
            if (i>=piles.size()) continue;
            
            sum += piles[i];
            int X = i-start+1;            
            int other = dfs(piles, i+1, max(X,M));
            
            int ret;
            if (i+1==piles.size())
                ret = sum;
            else
                ret = sum + sufSum[i+1] - other;
            
            if (ret>best)
                best = ret;            
        }
        
        Map[{start,M}] = best;
        return best;
    }
};
