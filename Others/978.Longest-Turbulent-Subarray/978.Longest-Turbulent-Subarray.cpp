class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) 
    {
        int N = A.size();
        vector<int>q(N,0);
        for (int i=0; i<A.size()-1; i++)
        {
            if (A[i]>A[i+1])
                q[i] = -1;
            else if (A[i]<A[i+1])
                q[i] = 1;
        }
        
        int count = 1;
        int start = 0;
        for (int i=0; i<A.size()-1; i++)
        {
            start = i;
            while (i+1<A.size()-1 && q[i+1]*q[i]==-1)
                i++;
            if (q[i]!=0)
                count = max(count, i-start+2);
        }
        
        return count;
    }
};
