class Solution {
    static bool cmp(vector<int>&a, vector<int>&b)
    {
        if (a[0]==b[0])
            return a[1]>b[1];
        else
            return a[0]<b[0];
    }
public:
    int videoStitching(vector<vector<int>>& clips, int T) 
    {
        sort(clips.begin(),clips.end(),cmp);
        
        if (clips[0][0]!=0) return -1;
        int right = clips[0][1];
        int idx = 0;
        int count = 1;
        if (clips[0][1]>=T) return count;
        
        while (idx < clips.size())
        {
            int farReach = right;
            while (idx<clips.size() && clips[idx][0]<=right)
            {
                farReach = max(farReach, clips[idx][1]);
                idx++;
            }
            if (farReach == right)
                return -1;
            
            count++;
            
            if (farReach>=T) return count;
            right = farReach;
        }
        
        return -1;
        
    }
};
