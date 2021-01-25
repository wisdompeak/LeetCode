class Solution {
    int workers[12];
    int k;
public:
    int minimumTimeRequired(vector<int>& jobs, int k) 
    {
        int n = jobs.size();        
        sort(jobs.begin(), jobs.end());
        reverse(jobs.begin(), jobs.end());
        this->k = k;
        
        int high = accumulate(jobs.begin(), jobs.end(), 0);
        int low = 1;
        
        while (low < high)
        {
            for (int i=0; i<k; i++)
                workers[i] = 0;

            int mid = low + (high-low)/2;
            if (dfs(jobs, 0, mid))
                high = mid;
            else
                low = mid+1;            
        }
        return high;        
    }
    
    bool dfs(vector<int>&jobs, int curJob, int th)
    {       
        if (curJob == jobs.size())
            return true;            
        int flag = 0;
        for (int j=0; j<k; j++)
        {
            if (workers[j]+jobs[curJob] > th) continue;
            if (workers[j]==0)
            {
                if (flag==1) continue;
                else flag = 1;
            }            
            workers[j]+=jobs[curJob];
            if (dfs(jobs, curJob+1, th))
                return true;
            workers[j]-=jobs[curJob];
        }        
        return false;
    }
};
