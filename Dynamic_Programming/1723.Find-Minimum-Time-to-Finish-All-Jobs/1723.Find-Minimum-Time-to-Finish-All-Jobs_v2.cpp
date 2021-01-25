class Solution {
    int stateTime[4100];
    int visited[4100][13];
    int k;
public:
    int minimumTimeRequired(vector<int>& jobs, int k) 
    {
        int n = jobs.size();        
        this->k = k;
        for (int state=0; state<(1<<n); state++)
        {
            int sum = 0;
            for (int i=0; i<n; i++)
            {
                if ((state>>i)&1)
                    sum += jobs[i];
            }
            stateTime[state] = sum;            
        }

        int high = accumulate(jobs.begin(), jobs.end(), 0);
        int low = 1;
        
        while (low < high)
        {
            for (int i=0; i<4100; i++)
                for (int j=0; j<=12; j++)
                    visited[i][j] = 0;

            int mid = low + (high-low)/2;
            if (dfs((1<<n)-1, mid, 0))
                high = mid;
            else
                low = mid+1;            
        }
        return high;        
    }
    
    bool dfs(int state, int th, int m)
    {       
        if (state == 0)
            return true;
        if (m==k)
            return false;
        
        if (visited[state][m]==1)
            return false;
        
        for (int subset=state; subset>0; subset=(subset-1)&state)
        {
            if (stateTime[subset] > th) continue;            
            if (dfs(state-subset, th, m+1))
                return true;
        }
        visited[state][m] = 1;
        return false;
    }
};
