class Solution {
    vector<int>len;
public:
    char findKthBit(int n, int k) 
    {
        len.resize(n+1);
        len[1] = 1;
        for (int i=2; i<=n; i++)
            len[i] = len[i-1]*2+1;
        
        return dfs(n, k);
    }
    
    char dfs(int n, int k)
    {
        if (n==1) return '0';
        if (k==len[n]/2+1) return '1';
        if (k<len[n]/2+1)
            return dfs(n-1, k);
        else
        {
            char ch = dfs(n-1, len[n]-k+1);
            if (ch=='1') return '0';
            else return '1';
        }
        return '#';
    }
};
