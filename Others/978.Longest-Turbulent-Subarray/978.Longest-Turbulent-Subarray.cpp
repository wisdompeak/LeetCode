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
        int i = 0;
        while (i<q.size())
        {
            if (q[i]==0) 
            {
                i++;
                continue;
            }
            
            int start = i;
            while (i+1<q.size() && q[i]*q[i+1]==-1)            
                i++;
            
            count = max(count, i-start+1+1);
            i++;
        }
        
        return count;
    }
};
