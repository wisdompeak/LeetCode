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
        
        if (A.size()==1) return 1;
        if (A.size()==2) return q[0]==0? 1: 2;
        
        int count = 1;
        int start = 0;
        for (int i=0; i+1<A.size()-1; i++)
        {
            if (q[i]!=0)
                count = max(count, 2);
            
            start = i;
            while (i+1<A.size()-1 && q[i]*q[i+1]==-1)
            {
                i++;
                count = max(count, i-start+2);
            }
        }
        
        return count;
    }
};
