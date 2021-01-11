class Solution {
    int n;
    vector<int>ret;
    int used[21];
public:
    vector<int> constructDistancedSequence(int n) 
    {
        this->n = n;
        ret.resize(2*n-1);
        dfs(0);
        return ret;
    }

    bool dfs(int pos)
    {
        if (pos==2*n-1)
            return true;
        if (ret[pos]>0)
            return dfs(pos+1);
        
        for (int d = n; d>=1; d--)
        {
            if (used[d]==1) continue;
            if (d > 1 && (pos+d >= 2*n-1 || ret[pos+d]>0)) continue;
            used[d] = 1;
            ret[pos] = d;
            if (d>1) ret[pos+d] = d;            
            
            if (dfs(pos+1))
                return true;

            used[d] = 0;
            ret[pos] = 0;
            if (d>1) ret[pos+d] = 0;                        
        }
        return false;
    }
};
