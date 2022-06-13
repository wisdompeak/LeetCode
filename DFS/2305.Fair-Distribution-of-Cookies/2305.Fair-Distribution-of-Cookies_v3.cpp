class Solution {
    int plan[8];
public:
    int distributeCookies(vector<int>& cookies, int k) 
    {      
        sort(cookies.rbegin(), cookies.rend());
        int n = cookies.size();
        
        int left = 1, right = INT_MAX;
        while (left < right)
        {
            for (int i=0; i<k; i++)
                plan[i] = 0;
            
            int mid = left+(right-left)/2;
            if (dfs(cookies, mid, k, 0, (1<<n)-1))
                right = mid;
            else
                left = mid+1;
        }
        return left;
    }
    
    bool dfs(vector<int>& cookies, int limit, int k, int curPerson, int state)
    {
        if (curPerson == k)
        {
            return state == 0;
        }
        
        for (int subset=state; subset>0; subset=(subset-1)&state)
        {
            int sum = getSum(cookies, subset);
            if (sum > limit) continue;
            if (dfs(cookies, limit, k, curPerson+1, state-subset))
                return true;            
        };
                
        return false;
    }
    
    int getSum(vector<int>& cookies, int state)
    {
        int ret = 0;
        for (int i=0; i<cookies.size(); i++)
        {
            if ((state>>i)&1)
                ret += cookies[i];
        }
        return ret;
    }
};
