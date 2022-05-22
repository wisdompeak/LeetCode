class Solution {
public:
    int meetRequirement(int n, vector<vector<int>>& lights, vector<int>& requirement) 
    {
        vector<int>diff(n+1);
        for (int i=0; i<lights.size(); i++)
        {
            int a = max(0, lights[i][0]-lights[i][1]);
            int b = min(n-1, lights[i][0]+lights[i][1]);
            
            diff[a]+=1;
            diff[b+1]-=1;
        }
        
        vector<int>bright(n);
        int sum = 0;
        for (int i=0; i<n; i++)
        {
            sum += diff[i];
            bright[i] = sum;
        }
        
        int ret = 0;
        for (int i=0; i<n; i++)
        {
            if (bright[i]>=requirement[i])
                ret++;
        }
        return ret;
    }
};
