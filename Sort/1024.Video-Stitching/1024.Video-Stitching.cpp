class Solution {
    static bool cmp(vector<int>&a, vector<int>&b)
    {
        if (a[0]==b[0]) return a[1]>b[1];
        else return a[0]<b[0];
    }
public:
    int videoStitching(vector<vector<int>>& q, int T) 
    {
        sort(q.begin(),q.end(), cmp);
        
        if (q[0][0]>0) return -1;
        int left = q[0][0];
        int right = q[0][1];
        int far = q[0][1];
        int count = 1;
        
        int i = 1;
        while (far<T && i<q.size())
        {
            int originFar = far;
            while (i<q.size() && q[i][0]<=right)
            {
                if (q[i][1]>=far)
                {
                    far = q[i][1];
                }
                i++;
            }
            
            if (far==originFar) break;
            
            left = right;
            right = far;
            count++;
        }
        
        if (far>=T) return count;
        else return -1;
    }
};
