class Solution {
public:
    int nthUglyNumber(int n) 
    {
        vector<int>q({1});
        int a=0, b=0, c=0;
        for (int i=0; i<n-1; i++)
        {
            int num = min(min(q[a]*2,q[b]*3),q[c]*5);
            if (q[a]*2==num) a++;
            if (q[b]*3==num) b++;
            if (q[c]*5==num) c++;
            q.push_back(num);
        }
        return q[n-1];
    }
};
