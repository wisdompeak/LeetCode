class Solution {
public:
    int minDeletionSize(vector<string>& A) 
    {
        int m = A.size();
        int n = A[0].size();
        vector<int>p(m, 0);
        int ret = 0;
        for (int j=0; j<n; j++)
        {
            vector<int>p2 = p;
            int flag = true;
            for (int i=1; i<m; i++)
            {
                if (p[i]==1) continue;
                if (p[i]==0)
                {
                    if (A[i][j]>A[i-1][j])
                        p2[i] = 1;
                    else if (A[i][j]<A[i-1][j])
                    {
                        flag = false;
                        break;
                    }                        
                }
            }
            if (flag==true)
                p = p2;
            else
                ret++;
        }
        return ret;

    }
};
