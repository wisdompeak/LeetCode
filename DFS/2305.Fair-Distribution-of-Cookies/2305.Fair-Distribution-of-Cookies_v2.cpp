class Solution {
    int plan[8];
public:
    int distributeCookies(vector<int>& cookies, int k) 
    {      
        sort(cookies.rbegin(), cookies.rend());
        
        int left = 1, right = INT_MAX;
        while (left < right)
        {
            for (int i=0; i<k; i++)
                plan[i] = 0;
            
            int mid = left+(right-left)/2;
            if (dfs(cookies, mid, k, 0))
                right = mid;
            else
                left = mid+1;
        }
        return left;
    }
    
    bool dfs(vector<int>& cookies, int limit, int k, int idx)
    {
        if (idx == cookies.size()) return true;
        
        int flag = 0;
        for (int i=0; i<k; i++)
        {
            if (plan[i]+cookies[idx] > limit) continue;
            if (plan[i]==0)
            {
                if (flag==1) continue;
                flag = 1;
            }
            
            plan[i] += cookies[idx];
            if (dfs(cookies, limit, k, idx+1))
                return true;
            plan[i] -= cookies[idx];
        }
        return false;
    }
};
