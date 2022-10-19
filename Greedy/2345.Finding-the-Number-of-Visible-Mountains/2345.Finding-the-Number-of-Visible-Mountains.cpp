class Solution {
public:
    int visibleMountains(vector<vector<int>>& peaks) 
    {        
        sort(peaks.begin(), peaks.end(), [](vector<int>&a, vector<int>&b){
            int l1=a[0]-a[1], r1=a[0]+a[1];
            int l2=b[0]-b[1], r2=b[0]+b[1];
            if (l1!=l2) return l1<l2;
            else return r1>r2;
        });
        
        int n = peaks.size();
        int rightMost = -1;
        int ret = 0;
        for (int i=0; i<n; i++)
        {
            if (i>0 && peaks[i]==peaks[i-1]) continue;
            if (peaks[i][0]+peaks[i][1] > rightMost)
            {
                rightMost = peaks[i][0]+peaks[i][1];
                if (i==n-1 || peaks[i]!=peaks[i+1])
                    ret++;
            }            
        }
        
        return ret;
    }
};
