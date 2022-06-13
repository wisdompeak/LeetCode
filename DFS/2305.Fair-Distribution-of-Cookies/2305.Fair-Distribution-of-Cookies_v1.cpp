class Solution {
    int ret = INT_MAX;
    int plan[8];
public:
    int distributeCookies(vector<int>& cookies, int k) 
    {      
        dfs(cookies, k, 0);        
        return ret;
    }
    
    void dfs(vector<int>& cookies, int k, int curCookie)
    {
        if (curCookie == cookies.size())
        {
            int mx = 0;
            for (int i=0; i<k; i++)
                mx = max(mx, plan[i]);
            ret = min(ret, mx);
            return;
        }
        
        for (int i=0; i<k; i++)
        {
            plan[i]+=cookies[curCookie];
            dfs(cookies, k, curCookie+1);
            plan[i]-=cookies[curCookie];
        }
    }
};
