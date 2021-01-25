class Solution {
    static bool cmp(vector<int>&a, vector<int>&b)
    {
        if (a[0]!=b[0])
            return a[0]<b[0];
        else
            return a[1]>b[1];
    }
public:
    int videoStitching(vector<vector<int>>& clips, int T) 
    {
        if (T==0) return 0;
        sort(clips.begin(),clips.end(),cmp);        
        
        int far = 0;
        int i = 0;
        int count = 0;
                
        while (i < clips.size())
        {            
            int nextFar = far;
            while (i<clips.size() && clips[i][0]<=far)
            {
                nextFar = max(nextFar, clips[i][1]);
                i++;
            }
            count++;

            if (nextFar >= T)
                return count;
            else if (nextFar == far)
                return -1;                            
            far = nextFar;
        }        

        return -1;        
    }
};
