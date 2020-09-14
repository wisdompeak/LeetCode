class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) 
    {
        int sum = 0;
        int n = grumpy.size();
        for (int i=0; i<n; i++)
            if (grumpy[i]==0)
                sum+=customers[i];

        int ret = 0;
        for (int i=0; i<n; i++)
        {
            if (grumpy[i]==1)
                sum += customers[i];
            if (i>=X && grumpy[i-X]==1)
                sum -= customers[i-X];
            ret = max(ret, sum);
        }
        return ret;
    }
};
