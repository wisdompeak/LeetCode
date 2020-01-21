class Solution {
public:
    int findMinMoves(vector<int>& machines) 
    {
        int n = machines.size();
        vector<int>left(n,0);
        vector<int>right(n,0);

        int sum = 0;
        for (auto x:machines)
            sum += x;
        if (sum%n!=0) return -1;
        int k = sum/n;

        right[0] = machines[0] - k;
        for (int i=1; i<n-1; i++)
        {
            left[i] = -right[i-1];
            right[i] = machines[i]-k-left[i];
        }
        left[n-1] = machines[n-1]-k;

        int ret = 0;
        for (int i=0; i<n; i++)
        {
            int t = 0;
            if (left[i]>0) t+= left[i];
            if (right[i]>0) t+= right[i];
            ret = max(ret,t);
        }
        return ret;
    }
};
