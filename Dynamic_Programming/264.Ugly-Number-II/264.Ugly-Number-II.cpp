class Solution {
public:
    int nthUglyNumber(int n) 
    {
        vector<int>q({1});
        int i=0, j=0, k=0;
        while (q.size()<n)
        {
            int x = min(q[i]*2, min(q[j]*3, q[k]*5));
            if (x==q[i]*2) i++;
            if (x==q[j]*3) j++;
            if (x==q[k]*5) k++;
            q.push_back(x);
        }
        return q[n-1];
    }
};
