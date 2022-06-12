class Solution {
    int ret = INT_MAX;
    int plan[8];
public:
    int distributeCookies(vector<int>& cookies, int k) 
    {      
        dfs(cookies, k, 0, 0);        
        return ret;
    }
    
    void dfs(vector<int>& cookies, int k, int idx, int count)
    {
        if (idx==cookies.size())
        {
            int mx = 0;
            for (int i=0; i<k; i++)
                mx = max(mx, plan[i]);
            ret = min(ret, mx);
            return;
        }
        
        for (int i=0; i<k; i++)
        {
            plan[i]+=cookies[idx];
            dfs(cookies, k, idx+1, count+(plan[i]==cookies[idx]));
            plan[i]-=cookies[idx];
        }
    }
};
