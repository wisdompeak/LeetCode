class Solution {
    int memo[10001];
public:
    int minimumOperationsToMakeEqual(int x, int y) 
    {
        if (y>=x) return y-x;
        
        if (memo[x]!=0) return memo[x];
        
        int ret = INT_MAX/2;
        ret = min(ret, minimumOperationsToMakeEqual( (x-(x%11))/11, y) + x%11+1);
        ret = min(ret, minimumOperationsToMakeEqual( (x+ (11-x%11))/11, y) + (11-x%11) + 1);
        
        ret = min(ret, minimumOperationsToMakeEqual( (x-(x%5))/5, y) + x%5+1);
        ret = min(ret, minimumOperationsToMakeEqual( (x+(5-x%5))/5, y) + (5-x%5)+1);
        
        ret = min(ret, x-y);
        
        memo[x] = ret;
        
        return ret;
    }
};
