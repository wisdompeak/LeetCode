class Solution {
    int ret = 0;
public:
    int countSpecialNumbers(int N) 
    {
        string s = to_string(N);
        int n = s.size();
        
        for (int len=1; len<=n-1; len++)        
            ret += A(10, len) - A(9, len-1);        
        
        vector<int>visited(10);
        dfs(s, 0, visited);
        
        return ret;
    }
    
    void dfs(string&s, int i, vector<int>&visited)
    {        
        int n = s.size();        
        if (i>=n) 
        {
            ret++;
            return;
        }
        
        for (int d=0; d<=9; d++)
        {
            if (d==0 && i==0) continue;
            if (visited[d] == 1) continue;
            if (d < s[i]-'0')
                ret += A(10-i-1, n-1-i);
            else if (d == s[i]-'0')
            {
                visited[d] = 1;
                dfs(s, i+1, visited);                
                visited[d] = 0;
            }
        }
    }
    
    int A(int m, int k)
    {
        if (k==0) return 1;        
        int ret = 1;
        for (int i=0; i<k; i++)
            ret *= (m-i);
        return ret;
    }
};
